from flask import Flask, render_template, request, session, jsonify
from fun import solve_cube

app = Flask(__name__)
app.secret_key = 'super secret key'

@app.route("/")
def hello():
    return render_template('index.html')

@app.route("/", methods=['POST'])
def task():
    print(type(request.form.get('str')))
    session["str"] = request.form.get('str') 
    return render_template("redirect.html")

@app.route("/slow/")
def slow():
    session["res"] = solve_cube(session["str"])
    return jsonify("oh so slow")

@app.route("/done/")
def done():
    return session.get("res")

