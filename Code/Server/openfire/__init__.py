from flask import Flask
from .database import create_session
from .views import create_views

app = Flask(__name__)
create_views(app)

session = create_session()
