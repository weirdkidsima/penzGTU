import asyncio

async def chat_client():
    reader, writer = await asyncio.open_connection('127.0.0.1', 8888)

    while True:
        data = await reader.read(1000)
        print(data.decode(), end='')

        message = input()
        writer.write(message.encode())
        await writer.drain()

        if message.lower() == "exit":
            break

    writer.close()
    await writer.wait_closed()

if __name__ == "__main__":
    asyncio.run(chat_client())
