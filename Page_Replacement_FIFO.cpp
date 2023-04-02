#include<bits/stdc++.h>
using namespace std;

// This is FIFO algorithm for page replacement
// Here oldest page in queue will be replaced by new page
// We are using 3 frames here

vector<int> frames(3,-1),faults,replaced;

void show(vector<int> &v){
    for(auto it : v){
        cout << it << " ";
    }
    cout << "\n";
}

void FIFO(){
    vector<int> refer_str(7);
    refer_str = { 1, 3, 0, 3, 5, 6, 3 };

    int replace_of=0;

    for(int ind=0;ind<refer_str.size();ind++){
        bool find=false;
        replace_of%=frames.size();

        for(int i=0;i<frames.size();i++){
            if(refer_str[ind]==frames[i]) find = true;
        }

        if(find) continue;
        else{
            if(frames.size()>0 && frames[replace_of]!=-1){
            replaced.push_back(frames[replace_of]);
            }
            frames[replace_of]=refer_str[ind];
            faults.push_back(refer_str[ind]);
            replace_of++;
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
    FIFO();
}