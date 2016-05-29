from sqlalchemy import Column, Integer, Float
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class StrongPoint(Base):
    __tablename__ = 'strong_points'

    id = Column(Integer, primary_key=True)
    location_x = Column(Float)
    location_y = Column(Float)

    def to_dict(self):
        return {
            'id': self.id,
            'location': {
                'x': self.location_x,
                'y': self.location_y
            }
        }
