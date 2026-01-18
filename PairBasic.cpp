Topics
1. Pair Declaration
2. Hoe to push or insert value in pair
3. Swap()
4. '=='
5. '!='
6. '>='
7. '<='

Topic- 01 & 02
//---------------------------------------Pair Declaration & how to push-----------------------------------//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,int>p;
    //pair<int,char>p;
    //pair<int,int>p(10,20);
    p.first=10;
    p.second=20;
    //p.second='N'; //Character push

    cout<<p.first<<"  "<<p.second<<endl;
}

Topic- 03
//----------------------------------------Swap()----------------------------//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,int>p1(10,20);
    pair<int,int>p2(30,40);

    p1.swap(p2); //Swap

    cout<<"P2 print: "<<endl;
    cout<<p2.first<<"  "<<p2.second<<endl;
}

Topic- 04
//---------------------------------'=='-------------------------------------------//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,int>p1(10,20);
    pair<int,int>p2(30,40);

    if (p1==p2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

Topic- 05
//-----------------------------'!='-------------------------------------------------//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,int>p1(10,20);
    pair<int,int>p2(30,40);

    if (p1!=p2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

Topic- 06
//--------------------------------------'>='----------------------------------------------//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,int>p1(10,20);
    pair<int,int>p2(30,40);

    if (p1>=p2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

Topic- 07
//--------------------------------------'<='---------------------------------------------//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,int>p1(10,20);
    pair<int,int>p2(30,40);

    if (p1<=p2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

