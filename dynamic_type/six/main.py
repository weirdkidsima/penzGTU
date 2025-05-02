import asyncio
from aiohttp import web
import string
import logging

# Глобальная очередь
queue = asyncio.Queue()

async def preprocess_text(text):
    text = text.lower()
    text = text.translate(str.maketrans('', '', string.punctuation))
    text = ' '.join(text.split())
    return text

async def handle_post(request):
    data = await request.json()
    user_info = data.get('user_info', {})
    text = data.get('text', '')
    
    processed_text = await preprocess_text(text)
    await queue.put({'user_info': user_info, 'text': processed_text})
    
    return web.json_response({'status': 'processed'})

async def analyze_text(text):
    if 'good' in text:
        return 'Positive'
    elif 'bad' in text:
        return 'Negative'
    else:
        return 'Neutral'

async def inference_service():
    while True:
        item = await queue.get()
        if item is None:
            break
        
        try:
            sentiment = await analyze_text(item['text'])
            logging.info(f"User: {item['user_info']}, Text: {item['text']}, Sentiment: {sentiment}")
        except Exception as e:
            logging.error(f"Error processing message: {e}")
            await asyncio.sleep(1)  # Повторная попытка через 1 секунду
            await queue.put(item)  # Возвращаем сообщение в очередь

# Запуск сервисов
async def start_services():
    app = web.Application()
    app.router.add_post('/process', handle_post)
    
    runner = web.AppRunner(app)
    await runner.setup()
    site = web.TCPSite(runner, 'localhost', 8080)
    await site.start()
    
    asyncio.create_task(inference_service())
    
    while True:
        await asyncio.sleep(3600)  # Бесконечный цикл для поддержания работы сервисов

if __name__ == '__main__':
    logging.basicConfig(level=logging.INFO)
    asyncio.run(start_services())