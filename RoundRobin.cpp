/*
**This code works for round robin sheduling
*/



#include<bits/stdc++.h>
using namespace std;

struct Process{
    char p_id[20];
    int b_t;
    int a_t;
    int w_t;
};

void find_gantt_chart(){
    cout << "Enter number of processes\n";
    int n;
    cin >> n;
    struct Process pros[20];
    vector<int> v(n);
    cout << "Please enter Process_id burst_time arrival_time\n";
    for(int i=0;i<n;i++){
        cin >> pros[i].p_id >> pros[i].b_t >> pros[i].a_t;
        v[i]=pros[i].b_t;
    } 


    vector<string> vec;

    int time=0,interval=2;
    queue<Process> q;
    bool check[n];
    vector<int> time_interval;
    time_interval.push_back(0);
    struct Process pr;
    bool ck=false;

    while(true){
        for(int i=0;i<n;i++){
            if(pros[i].a_t<=time && pros[i].b_t!=0 &&!check[i])
                {q.push(pros[i]); check[i]=true;}
        }
        if(ck) q.push(pr);

        if(q.empty()) break;
        pr=q.front();
        q.pop();
        vec.push_back(pr.p_id);
        if(pr.b_t>interval){
            pr.b_t-=interval;
            time+=interval;
            time_interval.push_back(time);
            ck=true;
        }
        else{
            time+=pr.b_t;
            time_interval.push_back(time);
            pr.b_t=0;
            pr.w_t=time;
            ck=false;
        }
    }

    for(int i=0;i<n;i++){
        pros[i].b_t=v[i];
        pros[i].w_t-=v[i];
    }

    int cnt=0,p=0;
    cout << "Gantt chart : \n   ";
    for(auto it: vec){
        cout << it << "    ";
        cnt++;
        if(cnt%12==0){
            if(cnt<13)
            cout << "\n";
            else cout << "\n   ";
            for(int j=p;j<=cnt;j++){
                if(time_interval[j]<=9)cout << time_interval[j] << "     ";
                else cout << time_interval[j] << "    ";
            }
            p=cnt+1;
            cout << "\n";
        }
    }

    cout << "\n   ";
    for(int j=p;j<=cnt;j++){
        cout << time_interval[j] << "    ";
    }
    cout << "\n";
}

int main(){
    find_gantt_chart();
}


