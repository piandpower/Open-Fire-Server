from enum import Enum


class ActorType(Enum):
    # unknown
    unknown = 0

    # unit
    worker = 1

    # building
    castle = 100001
    farm = 100002
