from flask import Flask, request, render_template
from solve import solve

app = Flask(__name__)

@app.route("/")
def hello_world():
    return render_template('home.html')

@app.route('/', methods=["GET", "POST"])
def handle_data():
    res = solve()
    return res