#include<bits/stdc++.h>
using namespace std;

struct process {
    char process_id[20];
    int burst_time;
    int waiting_time = 0;
};

bool compare(struct process& a, struct process&b){
    return a.burst_time<b.burst_time;
}

int main(){
    int n;
    cout << "Please enter the total number of processes: ";
    cin >> n;

    vector<process> processes(n); // Use a vector to store the processes

    cout << "Please enter process_id, burst_time:\n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].process_id >> processes[i].burst_time;
    }

    sort(processes.begin(),processes.end(),compare);

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }

    cout << "\n\nGantt Chart:\n";
    for (int i = 0; i < n; i++) {
        cout << "\t" << processes[i].process_id;
    }
    cout << "\n   ";
    for (int i = 0; i < n; i++) {
        cout << processes[i].waiting_time << "\t    ";
    }
    cout << processes[n - 1].waiting_time + processes[n - 1].burst_time;

    return 0;
}
