from sqlalchemy.orm import sessionmaker

from framework.database.core.engine import engine

Session = sessionmaker(bind=engine)
