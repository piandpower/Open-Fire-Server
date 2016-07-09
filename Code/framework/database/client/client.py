import pyorient

client = pyorient.OrientDB('localhost', 2424)
client.connect('root', 'secret')
