////Topic////

1. Map Declaration
2. insert( )
3. size( ) and max_size( )
4. begin( ),end( )
5. empty( )
6. erase( )
7. clear( )
8. count( )
9. find( )
10. swap( )
11. Upper_bound( )
12. Lower_bound( )

//-----------------------------Now START Code ----------------------------------//

Topic-1
//-------------------------------------Map-Declaration---------------------------//
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int ,string>mp;

    //mp[key]="Value";
    mp[47]="Nadia";
    for (auto it:mp)
    {
        cout<<it.first<<" -> "<<it.second<<endl;
    }
}

Topic- 2
//--------------------------------Insert()------------------------------//
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,string>mp;
    mp.insert ({47,"Nadia"});
    mp.insert ({74,"Afrin"});
    mp.insert ({4774,"Fahmida"});

    for(auto it:mp)
    {
        cout<<it.first<<" -> "<<it.second<<endl;
    }
}

Topic- 3
//---------------------------------------size() and max_size()--------------------//
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,string>mp;
    mp.insert ({47,"Nadia"});
    mp.insert ({74,"Afrin"});
    mp.insert ({4774,"Fahmida"});

    cout<<mp.size()<<endl;
    cout<<mp.max_size()<<endl;


    for(auto it:mp)
    {
        cout<<it.first<<" -> "<<it.second<<endl;
    }
}

Topic- 4
//-------------------------------------begin() and end()--------------------//
#include<bits/stdc++.h>
using namespace std;

int main()
{

    map<int,string>mp;
    mp.insert ({47,"Nadia"});
    mp.insert ({74,"Afrin"});
    mp.insert ({4774,"Fahmida"});

    map<int,string>::iterator it;

    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<"   "<<it->second<<endl;
    }
}

Topic- 5
//-------------------------------------empty()------------------------//
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,string>mp;
    mp.insert ({47,"Nadia"});
    mp.insert ({74,"Afrin"});
    mp.insert ({4774,"Fahmida"});

    if (mp.empty( ))cout<<" Show Empty "<<endl;
    else cout<<" Not Show Empty " <<endl;

    for(auto it:mp)
    {
        cout<<it.first<<" -> "<<it.second<<endl;
    }
}

Topic- 6
//--------------------------------------------erase()--------------------------//
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,string>mp;
    mp.insert ({47,"Nadia"});
    mp.insert ({74,"Afrin"});
    mp.insert ({4774,"Fahmida"});

    mp.erase(47);
    for(auto it:mp)
    {
        cout<<it.first<<" -> "<<it.second<<endl;
    }
}

Topic- 7
//---------------------------------------clear()--------------------//
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,string>mp;
    mp.insert ({47,"Nadia"});
    mp.insert ({74,"Afrin"});
    mp.insert ({4774,"Fahmida"});

    mp.clear();// eta clear kore dibe shob key,value--->so,porobortite empty show krbe
    if (mp.empty( ))cout<<" Show Empty "<<endl;
    else cout<<" Not Show Empty " <<endl;

    for(auto it:mp)
    {
        cout<<it.first<<" -> "<<it.second<<endl;
    }
}

Topic- 8
//-------------------------------------count()---------------------------//
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,string>mp;
    mp.insert ({47,"Nadia"});
    mp.insert ({74,"Afrin"});
    mp.insert ({4774,"Fahmida"});

    int count_map=mp.count(4774);
    cout<<count_map<<endl;
}

Topic- 9
//-------------------------find()------------------------//
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,string>mp;
    mp.insert ({47,"Nadia"});
    mp.insert ({74,"Afrin"});
    mp.insert ({4774,"Fahmida"});

    auto it= mp.find(74);
    if (it!=mp.end())cout<<" Found "<<endl;
    else cout<<" Not Found "<<endl;

}

Topic- 10
//------------------------------swap()---------------------------------//
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,string>mp,mp1;
    mp.insert ({47,"Nadia"});
    mp.insert ({74,"Afrin"});
    mp.insert ({4774,"Fahmida"});

    mp1[1]="Aaaaaa";
    mp1[2]="Bbbbbb";
    mp1[3]="Cccccc";

    mp.swap(mp1);
    for(auto it:mp1)
    {
        cout<<it.first<<" -> "<<it.second<<endl;
    }
}



//--------------------------------------------------------Pass / Fail list---------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout <<"Enter num: ";
    cin >> n;

    map<string,int> mp;
    for(int i = 0; i < n; i++){
        string name;
        int marks;
        cin >> name >> marks;
        mp[name] = marks;
    }

    cout << "        PASS STUDENTS         \n";

    for(auto p : mp){
        if(p.second >= 40){
            cout << "Name  : " << p.first << endl;
            cout << "Marks : " << p.second << endl;
        }
    }

    cout << "        FAIL STUDENTS         \n";

    for(auto p : mp){
        if(p.second < 40){
            cout << "Name  : " << p.first << endl;
            cout << "Marks : " << p.second << endl;
        }
    }

    return 0;
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





