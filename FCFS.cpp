#include<bits/stdc++.h>

using namespace std;

struct Process{
    char processid[10];
    int order;
    int burst_time;
    int waiting_time;
};

int compareProc(const void* a,const void* b){
    struct Process* p1 = (struct Process*)a;
    struct Process* p2 = (struct Process*)b;
    // Sort by order
    return p1->order - p2->order;
}

void find_waiting_time(struct Process* pros,int n){
    pros[0].waiting_time=0;
    for(int i=1;i<n;i++)
        pros[i].waiting_time=pros[i-1].waiting_time+pros[i-1].burst_time;
}


void findGanttChart(){
    int n;
    Process pros[50];
    cout << "Please enter total number of processes \n";
    cin >> n;

    cout << "Please enter Process_id Order Burst_time\n";
    for(int i=0;i<n;i++){
        cin >> pros[i].processid >> pros[i].order >> pros[i].burst_time;
    }

    qsort(pros,n,sizeof(struct Process),compareProc);
    find_waiting_time(pros,n);

    cout << "\nGantt Chart : \n   ";
    for(int i=0;i<n;i++)
    {
        cout << pros[i].processid << "    ";
    }

    cout << "\n";

    for(int i=0;i<n;i++)
    {
        cout << pros[i].waiting_time << "    ";
    }

    cout << pros[n-1].waiting_time+pros[n-1].burst_time << endl;
}

int32_t main(){
    findGanttChart();
    
    
}