import aiohttp
import asyncio
import logging
from time import time

# Настройка логирования
logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")
logger = logging.getLogger(__name__)

# Кэш для результатов запросов
CACHE = {}
CACHE_TIMEOUT = 60  # Время жизни данных в кэше в секундах

# Функция с таймаутом и повторными попытками гет запросов
async def fetch_with_retries(url, session, retries=3, timeout=5):
    for attempt in range(1, retries + 1):
        try:
            logger.info(f"Запрос {url}, попытка {attempt}")
            # Задание таймаута
            async with session.get(url) as response:
                response.raise_for_status()  # Проверка статус-кода
                data = await asyncio.wait_for(response.json(), timeout=timeout)
                return data
        
        except asyncio.TimeoutError:
            logger.error(f"Таймаут запроса {url} на попытке {attempt}")
        except aiohttp.ClientError as e:
            logger.error(f"Ошибка соединения {e} на попытке {attempt}")
        except Exception as e:
            logger.error(f"Непредвиденная ошибка {e} на попытке {attempt}")
        
        if attempt < retries:  # Задержка перед повторной попыткой
            await asyncio.sleep(1)
    logger.error(f"Не удалось получить данные с {url} после {retries} попыток")
    return None

# Проверка и кэширование данных
async def get_data(url, session):
    current_time = time()
    # Проверка кэша
    if url in CACHE:
        timestamp, data = CACHE[url]
        if current_time - timestamp < CACHE_TIMEOUT:
            logger.info(f"Возвращены закэшированные данные для {url}")
            return data

    # Если данных в кэше нет или срок истёк то запрос
    logger.info(f"Запрос данных для {url}")
    data = await fetch_with_retries(url, session)
    if data is not None:  # Кэшируем новые данные
        CACHE[url] = (current_time, data)
    return data

async def main():
    urls = [
        "https://jsonplaceholder.typicode.com/posts",
        "https://jsonplaceholder.typicode.com/comments",
        "https://help.x.com/ru/using-x",
    ]

    async with aiohttp.ClientSession() as session:
        # Запуск запросов параллельно
        tasks = [get_data(url, session) for url in urls]
        results = await asyncio.gather(*tasks)

    # Вывод результатов
    for url, data in zip(urls, results):
        if data is not None:
            logger.info(f"Получены данные с {url}: {len(data)} записей")
        else:
            logger.error(f"Не удалось получить данные с {url}")

if __name__ == "__main__":
    asyncio.run(main())
