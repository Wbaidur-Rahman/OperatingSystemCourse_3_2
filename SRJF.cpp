#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define ll long long
#define rep(s,e) for(int i=s;i<e;i++)


struct Process{
    char p_id[20];
    int br_t;
    int ar_t;
    int wt_t;
};

void calculate(struct Process* pros,int n){
    vector<string> process_id;
    vector<int> time_interval(1000);
    time_interval[0]=0;
    vi r_t(n);

    rep(0,n) r_t[i] = pros[i].br_t;

    int complete=0,t=0,minm=INT_MAX,shortest=0,finish_time,interval=2,indx=1;
    bool check=false;

    while(complete!=n){
        minm=INT_MAX;
        for(int j=0;j<n;j++){
            if((pros[j].ar_t <= t) && (r_t[j]<minm && r_t[j]>0)){
                minm=r_t[j];
                shortest=j;
                check=true;
            }
        }

        if(check==false) { 
            process_id.push_back("NN");
            time_interval[indx]=t+interval;
            indx++;
            t+=interval; continue; 
        }

        if(r_t[shortest]>=interval)
            {
                time_interval[indx]=t+interval;
                r_t[shortest]-=interval;
            }
        else{
            time_interval[indx]=t+r_t[shortest];
            r_t[shortest]=0;
        }
        process_id.push_back(pros[shortest].p_id);

        if(r_t[shortest]==0){
            complete++;
            check=false;
            finish_time=time_interval[indx];
            pros[shortest].wt_t=max(0,finish_time-pros[shortest].br_t-pros[shortest].ar_t);
        }
        t=time_interval[indx];
        indx++;
    }

    int cnt=0,p=0;
    cout << "\nGantt chart : \n          ";
    for(auto it : process_id)
        {
            cout << it << "       ";
            cnt++;
            if(cnt%12==0) {
                cout << "\n      ";
                rep(p,cnt+1)
                {cout << time_interval[i];
                if(i>9)cout<< "       ";
                else cout<<"        ";}
                cout << "\n\n\n   "; 
                p=cnt+1;  
            }
        }
    
    cout << "\n   ";
    rep(p,cnt+1){
        cout << time_interval[i] << "       ";
    }
}

void find_gantt_chart(){
    int n;
    struct Process pros[20]; 
    cout << "Please enter total number of processes\n";
    cin >> n;

    cout << "Please enter  process_id burst_time arrival_time\n";
    rep(0,n)
        cin >> pros[i].p_id >> pros[i].br_t >> pros[i].ar_t;

    calculate(pros,n);
    
}


int main()
{
    find_gantt_chart();
    // cout << "\nAverage waiting time : " << (float)tot_w_t/(float)n << endl;
    // cout << "Average turn_around time : " << (float)t_t_t/(float)n << "\n\n\n";
}



