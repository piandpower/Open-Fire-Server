from sqlalchemy import Column, Integer
from sqlalchemy.ext.declarative import declarative_base

Base = declarative_base()


class Strongpoint(Base):
    __tablename__ = 'strongpoint'

    id = Column(Integer, primary_key=True)
