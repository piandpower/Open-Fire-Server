from sqlalchemy import Column, ForeignKey, Integer
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class Strongpoint(Base):
    __tablename__ = 'strongpoint'

    id = Column(Integer, primary_key=True)


class Road(Base):
    __tablename__ = 'road'

    start = Column(Integer, ForeignKey('strongpoint.id'), primary_key=True)
    end = Column(Integer, ForeignKey('strongpoint.id'), primary_key=True)
