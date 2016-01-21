from flask import Flask

from openfire.gameoflife import gameoflife_bp

app = Flask(__name__)
app.register_blueprint(gameoflife_bp, url_prefix='/gameoflife')
