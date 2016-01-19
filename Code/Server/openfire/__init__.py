from flask import Flask
from openfire.admin import admin

app = Flask(__name__)
app.register_blueprint(admin, url_prefix='/admin')
