from flask import Flask
from openfire.gameoflife import gameoflife_bp


def create_app(test=False):
    app = Flask(__name__)
    app.register_blueprint(gameoflife_bp, url_prefix='/gameoflife')

    if test:
        from models import create_test_database
        create_test_database()

    return app
