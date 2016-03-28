from sqlalchemy import Column, Integer, Float
from .base import Base


class StrongPoint(Base):
    __tablename__ = 'strongpoint'

    strongpoint_id = Column(Integer, primary_key=True)
    position_x = Column(Float)
    position_y = Column(Float)

    def __init__(self, position_x, position_y):
        self.position_x = position_x
        self.position_y = position_y
