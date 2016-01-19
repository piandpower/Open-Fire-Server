from flask import Blueprint

admin = Blueprint('admin', __name__, template_folder='templates')


@admin.route('/')
@admin.route('/index')
def index():
    return 'Admin page'
