from random import random


class Tile:
    def __init__(self, position):
        self.position = position
        self.type = random()

    def __str__(self):
        return 'Tile: {0}, {1}'.format(self.position, self.type)
