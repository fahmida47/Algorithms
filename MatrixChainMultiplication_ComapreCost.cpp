#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// MCM DP
void matrixChainOrder(vector<int> &p, vector<vector<int>> &m, vector<vector<int>> &s) {
    int n = p.size() - 1;
    for(int i=1;i<=n;i++) m[i][i]=0;

    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}

// Print parenthesis
void printOptimalParens(vector<vector<int>> &s, int i, int j){
    if(i==j) cout<<"A"<<i;
    else{
        cout<<"(";
        printOptimalParens(s,i,s[i][j]);
        printOptimalParens(s,s[i][j]+1,j);
        cout<<")";
    }
}

// Function to create middle matrix if needed
vector<int> createChainWithMiddle(int r1,int c1,int r2,int c2){
    vector<int> p;
    if(c1==r2){
        cout<<"Direct multiplication possible\n";
        cout<<"A1 = "<<r1<<"x"<<c1<<"\n";
        cout<<"A2 = "<<r2<<"x"<<c2<<"\n";
        p = {r1,c1,c2};
    }else{
        int mid_r = c1;
        int mid_c = r2;
        cout<<"Direct multiplication not possible\n";
        cout<<"Middle matrix created: "<<mid_r<<"x"<<mid_c<<"\n";
        cout<<"A1 = "<<r1<<"x"<<c1<<"\n";
        cout<<"Middle = "<<mid_r<<"x"<<mid_c<<"\n";
        cout<<"A2 = "<<r2<<"x"<<c2<<"\n";
        p = {r1,c1,mid_c,c2};
    }
    return p;
}

int main(){
    int r1,c1,r2,c2;

    // Original order input
    cout<<"Enter first matrix (row col): ";
    cin>>r1>>c1;
    cout<<"Enter second matrix (row col): ";
    cin>>r2>>c2;

    cout<<"\n--- Original Order ---\n";
    vector<int> p_orig = createChainWithMiddle(r1,c1,r2,c2);
    int n1 = p_orig.size()-1;
    vector<vector<int>> m1(n1+1, vector<int>(n1+1));
    vector<vector<int>> s1(n1+1, vector<int>(n1+1));
    matrixChainOrder(p_orig,m1,s1);
    int cost_orig = m1[1][n1];
    cout<<"Minimum number of multiplications: "<<cost_orig<<"\n";
    cout<<"Optimal Parenthesization: ";
    printOptimalParens(s1,1,n1);
    cout<<"\n";

    // Reverse order input
    int r1_rev,c1_rev,r2_rev,c2_rev;
    cout<<"\nEnter reverse order matrices (row col) one by one:\n";
    cout<<"First reverse matrix: ";
    cin>>r1_rev>>c1_rev;
    cout<<"Second reverse matrix: ";
    cin>>r2_rev>>c2_rev;

    cout<<"\n--- Reverse Order ---\n";
    vector<int> p_rev = createChainWithMiddle(r1_rev,c1_rev,r2_rev,c2_rev);
    int n2 = p_rev.size()-1;
    vector<vector<int>> m2(n2+1, vector<int>(n2+1));
    vector<vector<int>> s2(n2+1, vector<int>(n2+1));
    matrixChainOrder(p_rev,m2,s2);
    int cost_rev = m2[1][n2];
    cout<<"Minimum number of multiplications: "<<cost_rev<<"\n";
    cout<<"Optimal Parenthesization: ";
    printOptimalParens(s2,1,n2);
    cout<<"\n";

    // Compare
    if(cost_orig<cost_rev)
        cout<<"\nMinimum cost achieved by Original order: "<<cost_orig<<"\n";
    else if(cost_rev<cost_orig)
        cout<<"\nMinimum cost achieved by Reverse order: "<<cost_rev<<"\n";
    else
        cout<<"\nBoth orders give same minimum cost: "<<cost_orig<<"\n";

    return 0;
}

