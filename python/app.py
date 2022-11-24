from flask import Flask, render_template, request, session, jsonify, url_for, redirect
from fun import solve_cube

app = Flask(__name__)
app.secret_key = 'super secret key'

@app.route("/", methods=["GET", "POST"])
def hello():
    session.clear()
    if request.method == "POST":
        session["str"] = request.form.get('str') 
        return redirect(url_for("task"))
    return render_template('index.html')

@app.route("/redirect")
def task():
    return render_template("redirect.html")
    

@app.route("/slow/")
def slow():
    session["res"] = solve_cube(session["str"])
    return jsonify("oh so slow")

@app.route("/done/")
def done():
    res = session.get("res")
    return render_template("done.html", res=res)
