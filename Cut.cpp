/**
*** This file contains a class with three functions.
*** re_name() funcion will rename a file
*** copy() function will copy a file from this directory to a new directory
*** cut() function will cut a file from this directory to another directory
**/



#include<bits/stdc++.h>
using namespace std;

class os{
public:
    void re_name(){
        char old_name[50],new_name[50];
        cout << "Please enter the file-name to rename\n";
        cin >> old_name;
        cout << "Please enter the new-name\n";
        cin >> new_name;

        if(rename(old_name,new_name)){
            cout << "Error\n";
        }

        else cout << "Successfully Renamed the file " << old_name << endl; 
    }

    void copy(){
        string path,filename,str;
        cout << "Please enter the filename to copy\n";
        cin >> filename;
        cout << "Please enter the path\n";
        cin >> path;

        for(int i=0;path[i];i++){
            if(path[i]=='\\') path[i]='/'; 
        }
        path+='/'+filename;
        ifstream ifstr(filename);
        ofstream ofstr(path);

        bool ok=true;
        while(getline(ifstr,str)){
            if(ok){
                cout << "Successfully Copied\n";
                ok=false;
            }
            ofstr << str << endl;
        }

        if(ok){
                cout << "Failed to copy\n";
                ok=false;
            }

        ifstr.close();
        ofstr.close();
    }


    void cut(){
        string path,str;
        char filename[60];
        cout << "Please enter the filename to cut\n";
        cin >> filename;
        cout << "Please enter the path\n";
        cin >> path;

        for(int i=0;path[i];i++){
            if(path[i]=='\\') path[i]='/'; 
        }
        path+='/'+filename;
        ifstream ifstr(filename);
        ofstream ofstr(path);

        bool ok=false;
        while(getline(ifstr,str)){
            ofstr << str << endl;
        }

        ifstr.close();
        ofstr.close();

        if(remove(filename)){
            cout << "Can't delete\n";
            ok=true;
        }

        else cout << "Successfully cutted\n";

        if(ok){
                cout << "Failed to cut\n";
                ok=false;
            }

    }
};

int main()
{
    os s1;
    // s1.re_name();
    // s1.cut();
}