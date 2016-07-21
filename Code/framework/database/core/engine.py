from sqlalchemy import create_engine
engine = create_engine('mysql+pymysql://root:secret@127.0.0.1:3306/openfire', echo=True)
