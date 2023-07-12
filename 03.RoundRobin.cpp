#include<bits/stdc++.h>
using namespace std;

vector<string> v;
vector<int> t;

struct process{
    char process_id[20];
    int burst_time;
    int waiting_time = 0;
};

queue<process> q;

void RoundRobin(int quantum){
    int total_time=0;
    while(!q.empty()){
        t.push_back(total_time);
        struct process now = q.front();
        q.pop();
        v.push_back(now.process_id);
        int run_time=min(now.burst_time,quantum);
        total_time+=run_time;
        now.burst_time-=run_time;
        if(now.burst_time) q.push(now);
        else{
            now.waiting_time=total_time-now.burst_time;
        }
    }
    t.push_back(total_time);
}

int main(){
    vector<process> processes(10);
    cout << "Enter total process and time quantum : ";
    int n,quantum;
    cin >> n >> quantum;
    cout << "\nEnter process_id burst_time\n";
    for(int i=0;i<n;i++){
        cin >> processes[i].process_id >> processes[i].burst_time;
        q.push(processes[i]);
    }

    RoundRobin(quantum);

    cout << "\n\nGantt Chart:\n";
    for (auto it: v) {
        cout << "\t" << it;
    }
    cout << "\n   ";
    for (auto it: t) {
        cout << it << "\t    ";
    }
   
}