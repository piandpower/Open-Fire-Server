from tile import Tile
from position import Position


class World:
    def __init__(self):
        self.__tiles = [Tile(Position(1, 1)),
                        Tile(Position(1, 2)),
                        Tile(Position(2, 1)),
                        Tile(Position(2, 2))]

    def get_tiles(self):
        return self.__tiles
