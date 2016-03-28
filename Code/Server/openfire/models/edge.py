from sqlalchemy import Column, Integer, Float, ForeignKey
from .base import Base


class Edge(Base):
    __tablename__ = 'edge'

    start_strongpoint_id = Column(Integer, ForeignKey('strongpoint.strongpoint_id'), primary_key=True)
    end_strongpoint_id = Column(Integer, ForeignKey('strongpoint.strongpoint_id'), primary_key=True)

    def __init__(self, start_strongpoint_id, end_strongpoint_id):
        self.start_strongpoint_id = start_strongpoint_id
        self.end_strongpoint_id = end_strongpoint_id
