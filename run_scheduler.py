# run_scheduler.py
from flask import Flask, request
import subprocess
import json

app = Flask(__name__)

@app.route('/schedule', methods=['POST'])
def schedule():
    data = request.json
    jobs = data.get("jobs", [])

    # Write input.txt
    with open("input.txt", "w") as f:
        f.write(f"{len(jobs)}\n")
        for job in jobs:
            f.write(f"{job['id']} {job['deadline']} {job['profit']}\n")

    # Run C++ binary (make sure it's compiled to ./scheduler)
    try:
        subprocess.run(["./scheduler"], check=True)
    except subprocess.CalledProcessError as e:
        return "Error running C++ scheduler.", 500

    # Read output.txt
    try:
        with open("output.txt", "r") as f:
            result = f.read()
    except FileNotFoundError:
        return "Output file not found.", 500

    return result

if __name__ == '__main__':
    app.run(debug=True)
