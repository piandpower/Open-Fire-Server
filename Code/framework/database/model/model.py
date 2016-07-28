from framework import Vector
from sqlalchemy import Column, Float, ForeignKey, Integer
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class Strongpoint(Base):
    __tablename__ = 'strongpoint'

    id = Column(Integer, primary_key=True)
    location_x = Column(Float)
    location_y = Column(Float)
    level = Column(Integer)

    def __init__(self, location: Vector, level: int):
        self.location_x = location.x
        self.location_y = location.y
        self.level = level


class Road(Base):
    __tablename__ = 'road'

    start_strongpoint_id = Column(Integer, ForeignKey('strongpoint.id'), primary_key=True)
    end_strongpoint_id = Column(Integer, ForeignKey('strongpoint.id'), primary_key=True)

    def __init__(self, start_strongpoint_id, end_strongpoint_id):
        self.start_strongpoint_id = start_strongpoint_id
        self.end_strongpoint_id = end_strongpoint_id
