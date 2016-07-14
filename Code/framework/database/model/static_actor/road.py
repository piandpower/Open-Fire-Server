from framework.database.client import client
from framework.database.config import DB_NAME, DB_ID, DB_PASSWORD
from framework.database.model.base import Base


class Road(Base):
    __name = 'Road'

    def __init__(self, start_id: str, end_id: str):
        self.start_id = start_id
        self.end_id = end_id

    @classmethod
    def create_class(cls):
        client.command("CREATE CLASS " + cls.__name + " EXTENDS E")

    def save(self):
        client.db_open(DB_NAME, DB_ID, DB_PASSWORD)
        sql = 'CREATE EDGE FROM ' + self.start_id + ' TO ' + self.end_id
        client.command(sql)

    @classmethod
    def read(cls):
        raise NotImplementedError
