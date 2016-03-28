from sqlalchemy import Column, Integer, ForeignKey
from .base import Base


class Building(Base):
    __tablename__ = 'building'

    building_id = Column(Integer, primary_key=True)
    strongpoint_id = Column(Integer, ForeignKey('strongpoint.strongpoint_id'))

    def __init__(self, strongpoint_id):
        self.strongpoint_id = strongpoint_id
