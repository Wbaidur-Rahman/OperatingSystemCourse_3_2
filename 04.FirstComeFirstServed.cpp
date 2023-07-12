#include<bits/stdc++.h>
using namespace std;

struct process {
    char process_id[20];
    int burst_time;
    int arival_time;
    int waiting_time = 0;
};

// Comparison function for sorting processes
bool compare(const struct process& a, const struct process& b) {
    return a.arival_time < b.arival_time;
}

int main() {
    int n;
    cout << "Please enter the total number of processes: ";
    cin >> n;

    vector<process> processes(n); // Use a vector to store the processes

    cout << "Please enter process_id, burst_time, and arival_time:\n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].process_id >> processes[i].burst_time >> processes[i].arival_time;
    }

    sort(processes.begin(), processes.end(), compare); // Sort the vector of processes by arival_time

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time-processes[i].arival_time+processes[i-1].arival_time;
    }

    cout << "\n\nGantt Chart:\n";
    for (int i = 0; i < n; i++) {
        cout << "\t" << processes[i].process_id;
    }
    cout << "\n   "
        <<  processes[0].arival_time << "\t    ";
    for (int i = 0; i < n; i++) {
        cout << processes[i].arival_time+processes[i].waiting_time+processes[i].burst_time << "\t    ";
    }
    return 0;
}
