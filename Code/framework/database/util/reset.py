import pyorient
from framework.database.client import client
from framework.database.config import DB_NAME
from framework.database.model.static_actor import Road, StrongPoint

STORAGE_TYPE = pyorient.STORAGE_TYPE_PLOCAL


def reset():
    if client.db_exists(DB_NAME, STORAGE_TYPE):
        client.db_drop(DB_NAME)

    client.db_create(DB_NAME, pyorient.DB_TYPE_GRAPH, STORAGE_TYPE)
    Road.create_class()
    StrongPoint.create_class()

if __name__ == "__main__":
    reset()
