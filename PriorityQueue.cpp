//Topics
//1. Priority Queue Declaration
//2. push()
//3. empty()
//4. size()
//5. top()
//6. pop()
//7. swap()
//8. emplace()
//9. value choto theke boro print

///Topic- 01 & 02 & 03
//---------------------------Priority queue Declaration & push() & empty()----------------------------//
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Declar
    priority_queue<int>pq;
    //Value Push
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);

    if (pq.empty())cout<<"Empty"<<endl;
    else cout<<"Not Empty"<<endl;
}*/

///Topic- 04
//-------------------------------------------size()-----------------------------------------//
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Declar
    priority_queue<int>pq;
    //Value Push
    pq.push(67);
    pq.push(20);
    pq.push(93);
    pq.push(49);

    cout<<pq.size()<<endl;
}*/

///Topic- 05
//------------------------------top()--------------------------//
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Declar
    priority_queue<int>pq;
    //Value Push
    pq.push(67);
    pq.push(20);
    pq.push(93);
    pq.push(49);

    cout<<pq.top()<<endl; //Default large value print korbe
}*/

///Topic- 06
//-------------------------------pop()-----------------------------------//
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Declar
    priority_queue<int>pq;
    //Value Push
    pq.push(67);
    pq.push(20);
    pq.push(93);
    pq.push(49);

    //pq.pop();
    //cout<<pq.top()<<endl;

    while(!pq.empty())//while(pq.size()>0)
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}*/

///Topic- 07
//---------------------------------------swap()----------------------------------------//
/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Declar
    priority_queue<int>pq1,pq2;
    //Value Push
    pq1.push(10);
    pq1.push(20);
    pq1.push(30);
    pq1.push(40);

    pq2.push(1);
    pq2.push(2);
    pq2.push(3);
    pq2.push(4);

    pq1.swap(pq2);//Swap

    while(pq1.size()>0)
    {
        cout<<pq1.top()<<endl;
        pq1.pop();
    }
}*/

///Topic- 08
//------------------------------------------------emplace()---------------------------------//
//emplace() function ar push() function same

///Topic- 09
//-----------------------------------------Value choto theke boro-----------------------------//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>  >pq;
    pq.push(67);
    pq.push(20);
    pq.push(93);
    pq.push(49);

    while(pq.size()>0)
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}
