import asyncio
import logging

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(message)s')

class BankAccount:
    def __init__(self):
        self.balance = 0
        self.lock = asyncio.Lock()
        self.condition = asyncio.Condition(self.lock)
        self.semaphore = asyncio.Semaphore(10)  # Ограничение на 10 одновременных транзакций

    async def deposit(self, amount):
        async with self.semaphore:
            async with self.lock:
                self.balance += amount
                logging.info(f'Внесена сумма {amount}, новый баланс: {self.balance}')
                self.condition.notify_all()

    async def withdraw(self, amount):
        async with self.semaphore:
            async with self.lock:
                while self.balance < amount:
                    logging.info(f'Средств недостаточно, ждём... текущий баланс: {self.balance}')
                    await self.condition.wait()
                self.balance -= amount
                logging.info(f'выведена {amount}, новый баланс: {self.balance}')

async def perform_transactions(account):
    tasks = []
    for _ in range(20):
        task = asyncio.create_task(account.deposit(100))
        tasks.append(task)
    for _ in range(10):
        task = asyncio.create_task(account.withdraw(150))
        tasks.append(task)
    await asyncio.gather(*tasks)

async def main():
    account = BankAccount()
    await perform_transactions(account)

asyncio.run(main())
