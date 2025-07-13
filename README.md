#Greedy Job Scheduler (C++ Backend + Web Interface)

A full-stack project that implements the classic Greedy Job Scheduling algorithm using C++, integrated with a Web Interface using HTML, JavaScript, and Flask.


🚀 Features

Schedule jobs to maximize profit based on deadlines

Web form to input job details (ID, deadline, profit)

Backend server in Flask that calls C++ code

Displays scheduled job order and total profit


🛠 Tech Stack

Frontend: HTML, CSS, JavaScript

Backend: Python (Flask)

Core Logic: C++


📂 Project Structure

.
├── index.html           # Web interface

├── run_scheduler.py     # Flask backend

├── scheduler.cpp        # C++ job scheduler logic

├── input.txt            # Input file (auto-generated)

├── output.txt           # Output file (auto-generated)

└── README.md


✅ How to Run Locally

1. Compile the C++ code

g++ scheduler.cpp -o scheduler

2. Set up Python backend

Install Flask:

pip install flask

Run server:

python run_scheduler.py

3. Open the frontend

Open index.html in any web browser.

📋 Example

Input Jobs:

A, Deadline: 2, Profit: 100

B, Deadline: 1, Profit: 50

C, Deadline: 2, Profit: 10

Output:

Scheduled Jobs: A B
Total Profit: 150


📈 Future Enhancements

Deploy with Docker or on Render/Heroku

Add animations to the UI

Export results to PDF/CSV

Add job conflict visualizer


👨‍💻 Author

Sohit SolankiB.Tech IT, Delhi Technological University

Feel free to star the repo if you found it useful ⭐
