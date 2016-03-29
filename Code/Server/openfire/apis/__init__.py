from flask import Blueprint

from openfire.apis.update.update_view import UpdateView
from .building_view import BuildingView
from .strongpoint_view import StrongPointView
from .unit_view import UnitView
from ..database import session

apis = Blueprint('apis', __name__)
apis.add_url_rule('/update', view_func=UpdateView.as_view('update'))
apis.add_url_rule('/strongpoints', view_func=StrongPointView.as_view('strongpoints'))
apis.add_url_rule('/buildings', view_func=BuildingView.as_view('buildings'))
apis.add_url_rule('/units', view_func=UnitView.as_view('units'))


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
