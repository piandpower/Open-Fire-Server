from flask import Blueprint, render_template

gameoflife_bp = Blueprint('gameoflife', __name__, template_folder='templates', static_folder='static')


@gameoflife_bp.route('/index')
@gameoflife_bp.route('/')
def index():
    return render_template('index.html')
