from model.engine import engine
from model.base import Base

Base.metadata.drop_all(engine)
Base.metadata.create_all(engine)
