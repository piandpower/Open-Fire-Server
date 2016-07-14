from framework import Vector
from framework.database.client import client
from framework.database.config import DB_NAME, DB_ID, DB_PASSWORD
from framework.database.model.base import Base


class StrongPoint(Base):
    __name = 'StrongPoint'

    def __init__(self, location: Vector, level: int):
        self.location = location
        self.level = level

    @classmethod
    def create_class(cls):
        client.command('CREATE CLASS ' + cls.__name + ' EXTENDS V')
        client.command('CREATE PROPERTY ' + cls.__name + '.location_x FLOAT (MANDATORY TRUE)')
        client.command('CREATE PROPERTY ' + cls.__name + '.location_y FLOAT (MANDATORY TRUE)')
        client.command('CREATE PROPERTY ' + cls.__name + '.level INTEGER (MANDATORY TRUE)')

    def save(self):
        client.db_open(DB_NAME, DB_ID, DB_PASSWORD)
        sql = 'INSERT INTO ' + self.__name + ' (location_x, location_y, level) VALUES ('\
              + str(self.location.x) + ', ' + str(self.location.y) + ', ' + str(self.level) + ')'
        client.command(sql)

    @classmethod
    def read(cls):
        client.db_open(DB_NAME, DB_ID, DB_PASSWORD)
        sql = 'SELECT * FROM ' + cls.__name
        return client.command(sql)
