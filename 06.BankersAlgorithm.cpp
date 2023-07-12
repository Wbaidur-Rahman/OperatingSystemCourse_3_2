#include<bits/stdc++.h>

using namespace std;
const int n_res=3;
int j;

struct process{
    string t_id;
    vector<int> allocat,max_need,need;
};



bool check_safety(vector<int>avail,vector<process> pros){
    int t_count=pros.size();
    bool finish[t_count]={false};
    string seq=" ";

    while(true){
        bool flag=false;
        for(int i=0;i<t_count;i++){
            if(finish[i]==true) continue;
            for(j=0;j<n_res;j++)
                if(avail[j]<pros[i].need[j]) break;

            if(j==n_res){
                flag=true;
                for(j=0;j<n_res;j++)
                    avail[j]+=pros[i].allocat[j];
                    finish[i]=true;
                    seq+=pros[i].t_id+ "  ";
            }    
        }
        if(!flag){
            break;
        }
    }

    for(int i=0;i<t_count;i++){
        if(!finish[i]) return false;
    }
    cout << seq <<endl;
    return true;
}

int main(){
    vector<process> pros(5);
    vector<int> avail(n_res);
    cout << "Enter the available instances\n";
    for(int i=0;i<n_res;i++){
        cin>>avail[i];
    }

    cout << "Enter the available allocation and max_need\n";
    
    for(int i=0;i<5;i++){
        pros[i].allocat.resize(n_res);
        pros[i].max_need.resize(n_res);
        pros[i].need.resize(n_res);
        cin >> pros[i].t_id;
        for(int j=0;j<n_res;j++){
            cin >>pros[i].allocat[j];
        }
        for(int j=0;j<n_res;j++){
            cin >> pros[i].max_need[j];
            pros[i].need[j]=pros[i].max_need[j]-pros[i].allocat[j];
        }
    }

    // cout << "Enter the available allocation and max_need\n";
    

    if(check_safety(avail,pros)){
        cout << "The system is in safe state\n";
    }
    else{
        cout << "The system is not safe\n";
    }

    // New request algorithm

    int id;
    cin >> id; // id of new requesting process
    vector<int> want(n_res);
    for(int i=0;i<n_res;i++){
        cin >> want[i];
        if(want[i]>pros[id].max_need[i]){
            cout << "Request exceeds maximum need. Can't accept request!";
            return 0;
        }
        if(want[i]>avail[i]){
            cout << "Request exceeds available resources. Can't accept request!";
            return 0;
        }
        avail[i]-=want[i];
        pros[id].allocat[i]+=want[i];
        pros[id].need[i]-=want[i];
    }

    
    cout << endl;
    if(check_safety(avail,pros)){
        cout << "The system is in safe state\n";
    }
    else{
        cout << "The process must wait & old resource-allocation state is restored";
    }

}
