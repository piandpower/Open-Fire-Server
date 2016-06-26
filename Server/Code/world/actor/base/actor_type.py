from enum import Enum


class ActorType(Enum):
    # unknown
    unknown = 0

    # unit
    worker = 1

    # building
    building = 100000
    farm = 100001
