import pyorient

client = pyorient.OrientDB('localhost', 2424)
client.connect('root', 'secret')

db_name = 'OpenFire'
storage_type = pyorient.STORAGE_TYPE_MEMORY

if client.db_exists(db_name, storage_type):
    client.db_drop(db_name)

client.db_create(db_name, pyorient.DB_TYPE_GRAPH, storage_type)
