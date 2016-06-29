from sqlalchemy import Column, ForeignKey, Integer, Float
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class Node(Base):
    __tablename__ = 'nodes'

    id = Column(Integer, primary_key=True)
    location_x = Column(Float, nullable=False)
    location_y = Column(Float, nullable=False)
    level = Column(Integer, nullable=False)

    def __init__(self, x: float, y: float, level: int):
        self.location_x = x
        self.location_y = y
        self.level = level

    def to_dict(self):
        return {
            'id': self.id,
            'location': {
                'x': self.location_x,
                'y': self.location_y
            },
            'level': self.level
        }


class Edge(Base):
    __tablename__ = 'edges'

    def __init__(self, start_strong_point_id, end_strong_point_id):
        self.start_strong_point_id = start_strong_point_id
        self.end_strong_point_id = end_strong_point_id

    start_strong_point_id = Column(Integer,
                                   ForeignKey('nodes.id'),
                                   primary_key=True, autoincrement=False,
                                   nullable=False)
    end_strong_point_id = Column(Integer,
                                 ForeignKey('nodes.id'),
                                 primary_key=True,
                                 autoincrement=False,
                                 nullable=False)


class Actor(Base):
    __tablename__ = 'actors'

    node_id = Column(Integer, ForeignKey('nodes.id'), primary_key=True, autoincrement=False)
    id = Column(Integer, primary_key=True, autoincrement=False)
    actor_type = Column(Integer, nullable=False)

