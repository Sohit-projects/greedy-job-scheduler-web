#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>

using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

bool comp(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        input >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), comp);

    int maxDeadline = 0;
    for (Job j : jobs) maxDeadline = max(maxDeadline, j.deadline);

    vector<string> slot(maxDeadline + 1, "");
    int totalProfit = 0;

    for (Job j : jobs) {
        for (int d = j.deadline; d > 0; --d) {
            if (slot[d] == "") {
                slot[d] = j.id;
                totalProfit += j.profit;
                break;
            }
        }
    }

    output << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; ++i) {
        if (slot[i] != "") output << slot[i] << " ";
    }
    output << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}
