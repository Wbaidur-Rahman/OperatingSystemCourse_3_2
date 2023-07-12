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
    int frame_size,faults=0;
    cout << "Enter frame size\n";
    cin >> frame_size;
    vector<int> frame(frame_size, -1);

    int page;

    while(cin>>page){
        if(page==-1) break;
        bool find = false;
        int ind = faults%frame_size;

        for(int i=0;i<frame_size;i++){
            if(frame[i]==page) {
                find=true;
                show(page,frame,find);
            }
        }
        if(find==true) continue;
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
3 -> 2 3 1
0 -> 2 3 0
4 -> 4 3 0
2 -> 4 2 0
3 -> 4 2 3
0 -> 0 2 3
3 ->
2 ->
1 -> 0 1 3
2 -> 0 1 2
0 ->
1 ->
7 -> 7 1 2
0 -> 7 0 2
1 -> 7 0 1
Total page fault = 15

*/