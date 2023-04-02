#include<bits/stdc++.h>
using namespace std;

// This is LRU algorithm for page replacement
// Here least recent pages will be replaced by new page
// We are using 3 frames here

vector<int> frames,faults,replaced,times(100,-1);

void show(vector<int> &v){
    for(auto it : v){
        cout << it << " ";
    }
    cout << "\n";
}

void LRU(){
    int fault_count = 0;
    vector<int> refer_str(7);
    refer_str = { 1, 3, 0, 3, 5, 6, 3 };

    set<int> st;

    int replace_of=0,ind;

    for(ind=0;ind<refer_str.size();ind++){
        times[refer_str[ind]]=ind;

        bool find=false;
        for(int i=0;i<frames.size();i++){
            if(refer_str[ind]==frames[i]) find = true;
        }
        if(find) continue;

        else{
            fault_count++;
            if(fault_count<=3){
                frames.push_back(refer_str[ind]);
                faults.push_back(refer_str[ind]);
                continue;
            }

            replace_of=-1;
            int mx_time=100;

            for(int k=0;k<100;k++){
                if(times[k]!=-1 && times[k]<mx_time){
                    replace_of=k;
                    mx_time=times[k];
                }
            }

            replaced.push_back(replace_of);

            for(int j=0;j<3;j++){
                if(frames[j]==replace_of){
                    times[replace_of]=-1;
                    frames[j]=refer_str[ind];
                    faults.push_back(refer_str[ind]);
                    break;
                }
            }
        }
    }

    cout << "Faults for pages : \n";
    show(faults);

    cout << "\nTotal faults : \n";
    cout << faults.size() << endl;

    cout << "Replaced pages : \n";
    show(replaced);


}

int main()
{
    LRU();
}