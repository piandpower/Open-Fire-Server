from framework import Vector
from framework.database.client import client
from framework.database.config import DB_NAME, DB_ID, DB_PASSWORD
from framework.database.model.base import Base
from typing import List


class Strongpoint(Base):
    __name = 'Strongpoint'

    def __init__(self, location: Vector, level: int):
        self.rid = None
        self.location = location
        self.level = level

    @classmethod
    def create_class(cls):
        client.command('CREATE CLASS ' + cls.__name + ' EXTENDS V')
        client.command('CREATE PROPERTY ' + cls.__name + '.x FLOAT (MANDATORY TRUE)')
        client.command('CREATE PROPERTY ' + cls.__name + '.y FLOAT (MANDATORY TRUE)')
        client.command('CREATE PROPERTY ' + cls.__name + '.level INTEGER (MANDATORY TRUE)')

    def save(self):
        client.db_open(DB_NAME, DB_ID, DB_PASSWORD)
        sql = 'INSERT INTO ' + self.__name + ' (x, y, level) VALUES ('\
              + str(self.location.x) + ', ' + str(self.location.y) + ', ' + str(self.level) + ')'
        client.command(sql)

    @classmethod
    def read(cls) -> List['Strongpoint']:
        client.db_open(DB_NAME, DB_ID, DB_PASSWORD)
        sql = 'SELECT * FROM ' + cls.__name
        strongpoints = []
        for raw_data in client.command(sql):
            strongpoints.append(cls.__to_model(raw_data))
        return strongpoints

    @staticmethod
    def __to_model(raw_data) -> 'Strongpoint':
        strong_point = Strongpoint(Vector(raw_data.oRecordData['x'], raw_data.oRecordData['y']), raw_data.oRecordData['level'])
        strong_point.rid = raw_data._rid
        return strong_point
