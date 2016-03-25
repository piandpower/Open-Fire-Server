from flask import Blueprint
from .strongpoint_view import StrongPointView
from ..database import session

apis = Blueprint('apis', __name__)
apis.add_url_rule('/strongpoints', view_func=StrongPointView.as_view('strongpoints'))


@apis.after_request
def after_request(response):
    try:
        session.commit()
    except Exception as e:
        print(e)
    return response


@apis.errorhandler(Exception)
def errorhandler(e):
    print(e)
    session.rollback()


@apis.teardown_request
def teardown_request(exception=None):
    session.remove()
