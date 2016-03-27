from sqlalchemy import Column, Integer, String, Float, ForeignKey
from sqlalchemy.ext.declarative import declarative_base


Base = declarative_base()


class StrongPoint(Base):
    __tablename__ = 'strongpoint'

    strongpoint_id = Column(Integer, primary_key=True)
    position_x = Column(Float)
    position_y = Column(Float)

    def __init__(self, position_x, position_y):
        self.position_x = position_x
        self.position_y = position_y


class Edge(Base):
    __tablename__ = 'edge'

    start_strongpoint_id = Column(Integer, ForeignKey('strongpoint.strongpoint_id'), primary_key=True)
    end_strongpoint_id = Column(Integer, ForeignKey('strongpoint.strongpoint_id'), primary_key=True)

    def __init__(self, start_strongpoint_id, end_strongpoint_id):
        self.start_strongpoint_id = start_strongpoint_id
        self.end_strongpoint_id = end_strongpoint_id
