//-----------------------------------------------Vector input & output-----------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int n, x;

    cout << "Enter n: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    cout << "Vector elements: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}

//------------------------------------------------Vector sum & average---------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, sum = 0;
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
        sum += x;
    }

    cout << "Sum: " << sum << endl;
    cout << "Average: " << (double)sum / n << endl;
}

//-------------------------------------------Vector Maximum & Minimum ------------------------------------//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> v;

    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());

    cout << "Max: " << mx << endl;
    cout << "Min: " << mn << endl;
}

//-------------------------------------------------------Vector reverse------------------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> v;

    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    reverse(v.begin(), v.end());

    for(int val : v)
        cout << val << " ";
}

//---------------------------------------------------------Sort vector ascending & descending-----------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> v;

    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    cout << "Ascending: ";
    for(int val : v) cout << val << " ";
    cout << endl;

    sort(v.rbegin(), v.rend());
    cout << "Descending: ";
    for(int val : v) cout << val << " ";
}

//----------------------------------------------------------------Remove duplicates from vector----------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int val : v) cout << val << " ";
}

//--------------------------------------------------------------Count occurrence of a number--------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, num;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    cin >> num;
    int cnt = count(v.begin(), v.end(), num);
    cout << num << " occurs " << cnt << " times";
}

//------------------------------------------------------------------------Vector rotate-----------------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    cin >> k;
    k = k % n;

    rotate(v.begin(), v.begin() + k, v.end());

    for(int x : v)
        cout << x << " ";
}


