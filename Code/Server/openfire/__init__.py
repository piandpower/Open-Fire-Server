from flask import Flask
from views import create_views

app = Flask(__name__)
create_views(app)
