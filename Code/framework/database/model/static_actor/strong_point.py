from framework.database.model.base import Base
from framework.database.client import client


class StrongPoint(Base):
    name = 'StrongPoint'

    @classmethod
    def create_class(cls):
        client.command("CREATE CLASS " + cls.name + " EXTENDS V")
