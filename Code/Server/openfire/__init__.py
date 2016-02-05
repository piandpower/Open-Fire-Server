from flask import Flask

from openfire.gameoflife import gameoflife_bp


def create_app():
    app = Flask(__name__)
    app.register_blueprint(gameoflife_bp, url_prefix='/gameoflife')
    return app
