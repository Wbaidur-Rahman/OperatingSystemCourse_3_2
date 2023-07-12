#include<bits/stdc++.h>
using namespace std;

void create(const string& filename){
    string path="E:/LAB_3_2/OperatingSystemCourse/New folder/Checking/"+filename;
    ofstream ofstr(path);
    if (ofstr) {  // Check if the file was successfully opened
        ofstr << "Hello, this is a file created by using ofstream\n";
        cout << "File created successfully: " << path << endl;
    } else {
        cout << "Failed to create the file: " << path << endl;
    }
}

void delet(const string& filename){
    string path="E:/LAB_3_2/OperatingSystemCourse/New folder/Checking/"+filename;
    if(remove(path.c_str())){
        cout << "cannot delete the file\n" << path;
    }
    else cout << "file deleted successfully\n";
}

void rename(const string& filename, string newname){
    string path="E:/LAB_3_2/OperatingSystemCourse/New folder/Checking/"+filename;
    string newpath="E:/LAB_3_2/OperatingSystemCourse/New folder/Checking/"+newname;

    if(!rename(path.c_str(),newpath.c_str())){
        cout << "Renamed successfully\n";
    }else{
        cout << "Failed to rename\n";
    }
}

void copy(const string& filename){
    string path="E:/LAB_3_2/OperatingSystemCourse/New folder/Checking/"+filename;
    string newpath="E:/LAB_3_2/OperatingSystemCourse/New folder/Checking/inside/"+filename;

    ofstream ofstr(newpath);
    ifstream ifstr(path);
    string str;
    while(ifstr>>str){
        ofstr<<str<< " ";
    }
}

void mov(const string& filename){
    string path="E:/LAB_3_2/OperatingSystemCourse/New folder/Checking/"+filename;
    string newpath="E:/LAB_3_2/OperatingSystemCourse/New folder/Checking/inside/"+filename;

    ofstream ofstr(newpath);
    ifstream ifstr(path);
    string str;
    while(ifstr>>str){
        ofstr<<str << " ";
    }
    ifstr.close();
    this_thread::sleep_for(chrono::milliseconds(100));  // Delay for 100 milliseconds
    delet(filename);
}


int main()
{
    cout << "To create a file in this \"E:\\LAB_3_2\\OperatingSystemCourse\\New folder\\Checking\" directory write \"create filename\"\n";
    cout << "To delte a file from this \"E:\\LAB_3_2\\OperatingSystemCourse\\New folder\\Checking\" directory write \"delete filename\"\n";
    cout << "To Rename a file in this \"E:\\LAB_3_2\\OperatingSystemCourse\\New folder\\Checking\" directory write \"rename filename newname\"\n";
    cout << "To Copy a file from this \"E:\\LAB_3_2\\OperatingSystemCourse\\New folder\\Checking\" directory write \"copy filename\"\n";
    cout << "To Move a file from this \"E:\\LAB_3_2\\OperatingSystemCourse\\New folder\\Checking\" directory write \"move filename\"\n\n";

    string operation,filename,newname;
    cin >> operation >> filename;

    if(operation=="create"){
        create(filename);
    }
    else if(operation=="delete"){
        delet(filename);
    }
    else if(operation=="rename"){
        cin >> newname;
        rename(filename,newname);
    }
    else if(operation=="copy"){
        copy(filename);
    }
    else if(operation=="move"){
        mov(filename);
    }
    return 0;
}