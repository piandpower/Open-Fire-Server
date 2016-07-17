from framework import Vector
from framework.database.client import client
from framework.database.config import DB_NAME, DB_ID, DB_PASSWORD
from framework.database.model.base import Base
from framework.type import Request
from typing import List


class Strongpoint(Base):
    __name = 'Strongpoint'

    def __init__(self, location: Vector, level: int, request: Request = Request.none):
        super().__init__()
        self.x = location.x
        self.y = location.y
        self.level = level
        self.request = request.value

    @classmethod
    def create_class(cls):
        client.command('CREATE CLASS ' + cls.__name + ' EXTENDS V')
        client.command('CREATE PROPERTY ' + cls.__name + '.x FLOAT (MANDATORY TRUE)')
        client.command('CREATE PROPERTY ' + cls.__name + '.y FLOAT (MANDATORY TRUE)')
        client.command('CREATE PROPERTY ' + cls.__name + '.level INTEGER (MANDATORY TRUE)')
        client.command('CREATE PROPERTY ' + cls.__name + '.request INTEGER (MANDATORY TRUE)')

    def save(self):
        client.db_open(DB_NAME, DB_ID, DB_PASSWORD)
        sql = 'INSERT INTO ' + self.__name + ' (' + self._generate_proerty_keys_string() + ') VALUES ('\
              + self._generate_property_values_string() + ')'
        return client.command(sql)

    @classmethod
    def read(cls, rid: str = None) -> List['Strongpoint']:
        client.db_open(DB_NAME, DB_ID, DB_PASSWORD)
        if rid is None:
            sql = 'SELECT * FROM ' + cls.__name
            strongpoints = []
            for data in client.command(sql):
                strongpoints.append(cls.__to_model(data))
            return strongpoints

        sql = 'SELECT * FROM ' + cls.__name + ' WHERE rid = ' + rid
        data = client.command(sql)
        return cls.__to_model(data)

    def update(self):
        client.db_open(DB_NAME, DB_ID, DB_PASSWORD)
        sql = 'UPDATE ' + self.__name + ' ' + self._generate_update_string() + ' WHERE rid IS ' + self.rid
        return client.command(sql)

    @staticmethod
    def __to_model(data) -> 'Strongpoint':
        strong_point = Strongpoint(
            Vector(data.oRecordData['x'], data.oRecordData['y']),
            data.oRecordData['level'],
            Request(data.oRecordData['request']))
        strong_point.rid = data._rid
        return strong_point
