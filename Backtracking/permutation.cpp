// 순열

#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long
#define INF 0x7fffffff

using namespace std;
int n, m;
int v[100];

bool is_used(int a, int x){
    for (int i=0; i<a; i++){
        if (v[i] == x){
            return true;
        }
    }
    return false;
}

void recursion(int a) {

    // 최대값일 때
    if (a == m){
        // 출력
        for (int i=0; i<m; i++){
            cout << v[i]+1 << " ";
        }
        cout << '\n';
    }

    for (int i=0; i<n; i++){
        v[a] = i;
        if (!is_used(a, i)){
            recursion(a+1);
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    recursion(0);
}


// 조합

#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long
#define INF 0x7fffffff

using namespace std;
int n, m;
int v[100];

bool is_used(int a, int x){
    for (int i=0; i<a; i++){
        if (v[i] == x){
            return true;
        }
    }
    return false;
}

void recursion(int a) {

    // 최대값일 때
    if (a == m){
        // 출력
        for (int i=0; i<m; i++){
            cout << v[i]+1 << " ";
        }
        cout << '\n';
    }

    for (int i=0; i<n; i++){
        v[a] = i;
        if (!is_used(a, i)){
            recursion(a+1);
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    recursion(0);
}