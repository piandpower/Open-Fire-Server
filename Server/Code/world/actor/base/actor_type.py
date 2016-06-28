from enum import Enum


class ActorType(Enum):
    # unknown
    unknown = 0

    # unit
    unit = 1
    worker = 2

    # building
    building = 100000
    castle = 100001
    farm = 100002
