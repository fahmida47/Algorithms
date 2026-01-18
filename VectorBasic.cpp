//Vector =>Dynamic Array
Topics=>
1. Vector Declaration
2. push_back()
3. how to print vector value
4. size()
5. front()
6. back()
7. clear()
8. empty()
9. pop_back()
10. erase()
11. insert()
12. swap()
13. sort()
14. reverse()
15. iteration
//------------------------------------------------------------------BASIC START----------------------------------------------//


Topic- 01
//--------------------------------------Vector Declar----------------------------------//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //vector declar
    vector<int>v;
}

Topic-02
//----------------------------------------Push_back()-----------------------------------------------------------//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
     v.push_back(1); //v[0];
     v.push_back(2);//v[1];
     v.push_back(3);//v[2];
     v.push_back(4);//v[3];
     v.push_back(5);//v[4];
}

Topic- 03
//------------------------------------------How to print vector------------------------------------------------//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
     v.push_back(1); //v[0];
     v.push_back(2);//v[1];
     v.push_back(3);//v[2];
     v.push_back(4);//v[3];
     v.push_back(5);//v[4];

     // amra range er bahire print korle output zero(0) show korbe warning dibe na
     cout<<" vector index diye vector print "<<endl;
     cout<<v[0]<<"  ";
     cout<<v[1]<<endl;

     //--OR--//
     // at() er subhidha hocche amra jodi range er bahire print kori tahole amdr warning dicche je range er bahire
     cout<<" at() diye vector print "<<endl;
     cout<<v.at(0)<<"  ";
     cout<<v.at(1)<<endl;
}

Topic- 04
//-----------------------------------------------Size()-----------------------------------------//
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
     v.push_back(1); //v[0];
     v.push_back(2);//v[1];
     v.push_back(3);//v[2];
     v.push_back(4);//v[3];
     v.push_back(5);//v[4];
    
    cout<<v.size()<<endl;
}

