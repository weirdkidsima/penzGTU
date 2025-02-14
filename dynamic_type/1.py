import asyncio
import time
import logging

# 3 
logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__name__)

# 1
async def task_coroutine(task_id, delay):
    start_time = time.time()
    logger.debug(f"Задача {task_id} стартовала в {time.strftime('%X')}")
    await asyncio.sleep(delay)
    end_time = time.time()
    execution_time = end_time - start_time
    logger.debug(f"Задача {task_id} завершена в {time.strftime('%X')}, время выполнения: {execution_time:.2f} сек")
    return task_id, execution_time

# 2
async def infinite_task():
    try:
        while True:
            logger.debug("Бесконечная задача работает..")
            await asyncio.sleep(1)
    except asyncio.CancelledError:
        logger.debug("Бесконечная задача отменена")

async def main():
    start_time = time.time()

    # Запуск параллельных задач
    tasks = [task_coroutine(i, delay) for i, delay in enumerate([1, 2, 3], start=1)]
    results = await asyncio.gather(*tasks)

    # Запуск и отмена бесконечной задачи
    infinite_task_obj = asyncio.create_task(infinite_task())
    await asyncio.sleep(5)
    infinite_task_obj.cancel()
    try:
        await infinite_task_obj
    except asyncio.CancelledError:
        logger.debug("Бесконечная задача была успешно отменена")

    # 4
    total_time = time.time() - start_time
    logger.debug(f"Общее время выполнения программы: {total_time:.2f} сек")
    logger.debug(f"Результаты выполнения задач: {results}")

    # Сравнение с последовательным выполнением
    sequential_time = sum(delay for _, delay in results)
    logger.debug(f"Суммарное время последовательного выполнения: {sequential_time:.2f} сек")
    logger.debug(f"Экономия времени за счет параллельного выполнения: {sequential_time - total_time:.2f} сек")

# Запуск программы в режиме отладки
if __name__ == "__main__":
    asyncio.run(main(), debug=True)