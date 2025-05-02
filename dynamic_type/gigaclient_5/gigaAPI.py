import os
from dotenv import load_dotenv

load_dotenv()

from gigachat import GigaChat

async def get_gigachat_response(message):
    try:
        async with GigaChat(credentials=os.getenv("AUTH_KEY"), verify_ssl_certs=False) as giga:
            response = await giga.achat(message)
            return response.choices[0].message.content
    except Exception as e:
        return f"Ошибка при обращении к Gigachat API: {str(e)}"
