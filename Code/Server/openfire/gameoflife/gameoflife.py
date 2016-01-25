from flask import Blueprint, render_template

bp = Blueprint('gameoflife', __name__, template_folder='templates', static_folder='static')


@bp.route('/')
@bp.route('/index')
def index():
    return render_template('index.html')
