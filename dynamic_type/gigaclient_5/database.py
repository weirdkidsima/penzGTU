import aiosqlite

DB_NAME = "chat_history.db"

async def init_db():
    async with aiosqlite.connect(DB_NAME) as db:
        await db.execute('''
            CREATE TABLE IF NOT EXISTS messages (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                session_id TEXT NOT NULL,
                username TEXT NOT NULL,
                user_message TEXT NOT NULL,
                bot_response TEXT NOT NULL,
                timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
            )
        ''')
        await db.commit()

async def save_message(session_id, username, user_message, bot_response):
    async with aiosqlite.connect(DB_NAME) as db:
        await db.execute('''
            INSERT INTO messages (session_id, username, user_message, bot_response)
            VALUES (?, ?, ?, ?)
        ''', (session_id, username, user_message, bot_response))
        await db.commit()
