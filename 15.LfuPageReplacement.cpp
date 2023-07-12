#include <bits/stdc++.h>

using namespace std;

void show(int page, vector<int> &frame,bool find){
    printf("%d -> ",page);
    if(find) {cout << endl; return;}
    for(int it : frame){
        if(it==-1) cout << "- ";
        else cout << it << " ";
    }

    cout << endl;
}

int main(){
    int frame_size,faults=0,t=0;
    vector<int> counts(100,-1);
    cout << "Enter frame size\n";
    cin >> frame_size;
    vector<int> frame(frame_size, -1);

    int page;

    while(cin>>page){
        if(page==-1) break;
        counts[page]++;
        bool find = false;
        
        for(int i=0;i<frame_size;i++){
            if(frame[i]==page) {
                find=true;
                show(page,frame,find);
            }
        }

        if(find==true) continue;

        int ind,k=1000;
        for(int i=0;i<frame_size;i++){
            if(frame[i]==-1) {ind=i; break;}
            if(counts[frame[i]]<k){
                k=counts[frame[i]];
                ind=i;
            }
        }
        frame[ind]=page;
        faults++;
        show(page,frame,find);
    }

    cout << "Total faults = " << faults << endl;
}

/*//... Input Output:

...............Input:
3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

..............Output:
7 -> 7 - -
0 -> 7 0 -
1 -> 7 0 1
2 -> 2 0 1
0 ->
3 -> 3 0 1
0 ->
4 -> 4 0 1
2 -> 2 0 1
3 -> 2 0 3
0 ->
3 ->
2 ->
1 -> 1 0 3
2 -> 2 0 3
0 ->
1 -> 2 0 1
7 -> 2 0 7
0 ->
1 -> 2 0 1
Total page fault = 13
---------------------------*/