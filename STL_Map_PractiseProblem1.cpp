////Topic////
1. Pass/Fail Problem
2. Highest marks find
3. Search student by name
4. Lab online(01) ques solve
5. Lab online(02) ques solve
6. Lab online(03) ques solve
7. Lab online(04) ques solve

//----------------------------------------Now START Code-------------------------------//

Topic- 1
//---------------------------------------------Pass/Fail Problem------------------------------------------//
#include<bits/stdc++.h>
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
}

Topic- 2
//------------------------------------------------------------Highest marks student--------------------------------------------------------//
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

    string topStudent;
    int maxMarks = -1;
    for(auto it : mp){
        if(it.second > maxMarks){
            maxMarks = it.second;
            topStudent = it.first;
        }
    }

    cout << "Top Student: " << topStudent << " -> " << maxMarks;
}

Topic- 3
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

///Topic- 4
//Suppose, you want to store the information of some employees of an organization. The information consists of employee ID, Name, age, and salary.
//Now, create 3 options for the users:
//1. insert new employee and save it to the existing container,
//2. if any employee ID is provided show the salary of that person
//3. sort all existing data according to age.
//Implement this scenario using the concepts of STL.

#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, vector<string>> mp;
    int CountNo;

    while (true) {
        cout << " Count No: ";
        cin >> CountNo;

        // 1️.Insert new employee
        if (CountNo == 1) {
            int id;
            string name, age, salary;

            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Name: ";
            /*cin >> ws;
            getline(cin, name);*///full name.
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Salary: ";
            cin >> salary;

            mp[id] = {name, age, salary};
            cout << "Employee inserted successfully!\n";
        }

        // 2️.Show salary by employee ID
        else if (CountNo == 2) {
            int id;
            cout << "Enter Employee ID: ";
            cin >> id;

            if (mp.find(id) != mp.end()) {
                cout << "Salary: " << mp[id][2] << endl;
            } else {
                cout << "Employee not found!\n";
            }
        }

        // 3️.Sort employees by age
        else if (CountNo == 3) {
            // Convert map to vector for sorting
            vector<pair<int, vector<string>>> v(mp.begin(), mp.end());

            sort(v.begin(), v.end(),
                 [](auto a, auto b) {
                     return stoi(a.second[1]) < stoi(b.second[1]);
                 });

            cout << "\nEmployees sorted by age:\n";
            for (auto p : v) {
                cout << "ID: " << p.first
                     << ", Name: " << p.second[0]
                     << ", Age: " << p.second[1]
                     << ", Salary: " << p.second[2] << endl;
            }
        }

        // 4.Exit
        else if (CountNo == 4) {
            cout << "Program terminated.\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}



