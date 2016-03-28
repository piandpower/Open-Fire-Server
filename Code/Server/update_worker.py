import asyncio
from requests import post


async def update():
    while True:
        post('http://localhost:5000/apis/update')
        await  asyncio.sleep(5)

loop = asyncio.get_event_loop()
loop.run_until_complete(update())
