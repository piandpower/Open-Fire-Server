from flask import Flask
from .apis import apis

app = Flask(__name__)
app.register_blueprint(apis, url_prefix='/apis')
