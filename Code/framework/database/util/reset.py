from framework.database.core.engine import engine
from framework.database.model import Base


def reset():
    Base.metadata.drop_all(engine)
    Base.metadata.create_all(engine)

if __name__ == "__main__":
    reset()
