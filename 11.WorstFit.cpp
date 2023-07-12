#include<bits/stdc++.h>
using namespace std;

int main(){
    int no_of_hole;
    cout << "Enter total no of holes : ";
    cin >> no_of_hole;
    vector<int> holes(no_of_hole);
    cout << "\nEnter the hole sizes\n";
    for(int i=0;i<no_of_hole;i++){
        cin >> holes[i];
    }
    int p_size;
    cout << "Enter process size : ";
    cin >> p_size;
    sort(holes.begin(),holes.end(),greater<int>());
    for(int i=0;i<no_of_hole;i++){
        if(p_size<=holes[i]){
            cout << "\nProcess is fitted to " << holes[i] << " MegaByte hole\n";
            return 0;
        }
    }

    cout << "\nThere are not enough space to accomodate the process\n";
}