import asyncio
from auth import create_session
from gigaAPI import get_gigachat_response
from database import save_message, init_db

async def handle_client(reader, writer):
    writer.write("Введите ваш логин: ".encode())
    await writer.drain()
    username = (await reader.read(100)).decode().strip()

    try:
        session_id = await create_session(username)
        writer.write(f"Сессия создана: {session_id}\n".encode())
        await writer.drain()
    except ValueError as e:
        writer.write(f"Ошибка: {e}\n".encode())
        await writer.drain()
        return

    while True:
        writer.write("Введите сообщение: ".encode())
        await writer.drain()
        message = (await reader.read(1024)).decode().strip()

        if message.lower() == "exit":
            break

        response = await get_gigachat_response(message)
        await save_message(session_id, username, message, response)

        writer.write(f"Бот: {response}\n".encode())
        await writer.drain()

    writer.close()
    await writer.wait_closed()

async def main():
    await init_db()
    server = await asyncio.start_server(handle_client, '127.0.0.1', 8888)
    async with server:
        await server.serve_forever()

if __name__ == "__main__":
    asyncio.run(main())
