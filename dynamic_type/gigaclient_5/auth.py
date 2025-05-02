from uuid import uuid4

active_sessions = {}

async def create_session(username):
    if username in active_sessions:
        raise ValueError("Ошибка: Пользоватеь уже в сессии")
    session_id = str(uuid4())
    active_sessions[username] = session_id
    return session_id

async def get_session(username):
    return active_sessions.get(username)
