////Topic////
/*
1. Pass/Fail Problem
2. Highest marks find
3. Search student by name
4. Lab online(01) ques solve
5. Lab online(02) ques solve
6. Lab online(03) ques solve
7. Lab online(04) ques solve
*/

///Topic- 1
//---------------------------------------------Pass/Fail Problem------------------------------------------//
/*#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Num: ";
    cin>>n;
    map<string,int>mp;

    for(int i=0;i<n;i++)
    {
        string name;
        int marks;
        cin>>name>>marks;
        mp[name]=marks;
    }

    cout<<"-------------------------Pass Students------------------------\n";
    for(auto it:mp)
    {
        if (it.second>=40)
        {
            cout<<"Name : "<<it.first<<endl;
            cout<<"Marks : "<<it.second<<endl;
        }
    }

    cout<<"-----------------------------------------Fail Students----------------\n";
    for(auto it:mp)
    {
        if (it.second<40)
        {
            cout<<"Name : "<<it.first<<endl;
            cout<<"Marks : "<<it.second<<endl;
        }
    }
    return 0;
}*/

///Topic- 2
//------------------------------------------------------------Highest marks student--------------------------------------------------------//
/*#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter Num: ";
    cin >> n;

    map<string,int> mp;
    for(int i = 0; i < n; i++){
        string name;
        int marks;
        cin >> name >> marks;
        mp[name] = marks;
    }

    string topStudent;
    int maxMarks = -1;
    for(auto it : mp){
        if(it.second > maxMarks){
            maxMarks = it.second;
            topStudent = it.first;
        }
    }

    cout << "Top Student: " << topStudent << " -> " << maxMarks;
}*/

///Topic- 3
//----------------------------------------------------------Search student by name--------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter Num: ";
    cin >> n;

    map<string,int> mp;
    for(int i = 0; i < n; i++){
        string name;
        int marks;
        cin >> name >> marks;
        mp[name] = marks;
    }

    string searchName;
    cout<<"Search name: ";
    cin >> searchName;

    if(mp.find(searchName) != mp.end())
        cout << searchName << " -> " << mp[searchName];
    else
        cout << "Student not found";
}

