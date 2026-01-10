//-----------------------------------------------------------------Simple key-value store----------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,string> mp;

    // insert
    mp[1] = "apple";
    mp[2] = "banana";
    mp[3] = "cherry";

    // print
    for(auto p : mp){
        cout << p.first << " -> " << p.second << endl;
    }
}

//---------------------------------------------------------Access a value by key------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,string> mp;
    mp[10] = "cat";
    mp[20] = "dog";

    int key;
    cin >> key;

    cout << mp[key] << endl; // if key exists, print value
}

//-----------------------------------------------------------Iterators (basic)-------------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,string> mp;
    mp[1] = "x";
    mp[2] = "y";

    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " : " << it->second << endl;
    }
}

//-----------------------------------------------------Delete a key-------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int,string> mp;
    mp[1] = "a";
    mp[2] = "b";
    mp[3] = "c";

    mp.erase(2); // delete key 2

    for(auto p : mp)
        cout << p.first << " -> " << p.second << endl;
}

//--------------------------------------------------------Pass / Fail list---------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string,int> mp;
    for(int i = 0; i < n; i++){
        string name;
        int marks;
        cin >> name >> marks;
        mp[name] = marks;
    }

    cout << "Pass Students:\n";
    for(auto p : mp){
        if(p.second >= 40)
            cout << p.first << " -> " << p.second << endl;
    }

    cout << "Fail Students:\n";
    for(auto p : mp){
        if(p.second < 40)
            cout << p.first << " -> " << p.second << endl;
    }
}

//------------------------------------------------------------Highest marks student--------------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
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
    for(auto p : mp){
        if(p.second > maxMarks){
            maxMarks = p.second;
            topStudent = p.first;
        }
    }

    cout << "Top Student: " << topStudent << " -> " << maxMarks;
}

//----------------------------------------------------------Search student by name--------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string,int> mp;
    for(int i = 0; i < n; i++){
        string name;
        int marks;
        cin >> name >> marks;
        mp[name] = marks;
    }

    string searchName;
    cin >> searchName;

    if(mp.find(searchName) != mp.end())
        cout << searchName << " -> " << mp[searchName];
    else
        cout << "Student not found";
}

