from flask import Blueprint

bp = Blueprint('gameoflife', __name__)


@bp.route('/')
@bp.route('/index')
def index():
    return 'Helo World!'
