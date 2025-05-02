import os
import aiofiles
import asyncio
import aiosqlite
import logging
from collections import Counter

async def read_file(file_path):
    async with aiofiles.open(file_path, mode='r') as file:
        content = await file.read()
        return file_path, content

def process_data(file_path, content):
    words = content.split()
    word_frequency = Counter(words)
    return file_path, word_frequency

async def create_db():
    async with aiosqlite.connect('file_stats.db') as db:
        await db.execute('''
            CREATE TABLE IF NOT EXISTS file_stats (
                file_name TEXT,
                word TEXT,
                frequency INTEGER
            )
        ''')
        await db.commit()

async def insert_stats(file_name, word_frequency):
    async with aiosqlite.connect('file_stats.db') as db:
        for word, frequency in word_frequency.items():
            await db.execute('INSERT INTO file_stats (file_name, word, frequency) VALUES (?, ?, ?)', 
                             (file_name, word, frequency))
        await db.commit()

async def main():
    await create_db()
    files = [f'D:/penzgtu/code/dynamic_type/3/data/{i+1}.txt' for i in range(5)]
    tasks = [read_file(file) for file in files]
    results = await asyncio.gather(*tasks, return_exceptions=True)

    for result in results:
        if isinstance(result, Exception):
            logging.error(f"Ошибка обработки файла: {result}")
        else:
            file_path, content = result
            file_name = os.path.basename(file_path)
            file_name, word_frequency = process_data(file_name, content)
            await insert_stats(file_name, word_frequency)

if __name__ == '__main__':
    logging.basicConfig(level=logging.INFO)
    asyncio.run(main())
