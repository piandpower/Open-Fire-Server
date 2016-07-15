from framework.database.client import client
from framework.database.config import DB_NAME, DB_ID, DB_PASSWORD
from framework.database.model.base import Base
from typing import List


class Road(Base):
    __name = 'Road'

    def __init__(self, start_id: str, end_id: str):
        self.rid = None
        self.start_id = start_id
        self.end_id = end_id

    @classmethod
    def create_class(cls):
        client.command("CREATE CLASS " + cls.__name + " EXTENDS E")

    def save(self):
        client.db_open(DB_NAME, DB_ID, DB_PASSWORD)
        sql = 'CREATE EDGE ' + self.__name + ' FROM ' + self.start_id + ' TO ' + self.end_id
        client.command(sql)

    @classmethod
    def read(cls) -> List['Road']:
        client.db_open(DB_NAME, DB_ID, DB_PASSWORD)
        sql = 'SELECT * FROM ' + cls.__name
        roads = []
        temp = client.command(sql)
        for raw_data in client.command(sql):
            roads.append(cls.__to_model(raw_data))
        return roads

    @staticmethod
    def __to_model(raw_data) -> 'Road':
        road = Road(str(raw_data.oRecordData['in']), str(raw_data.oRecordData['out']))
        road.rid = raw_data._rid
        return road
