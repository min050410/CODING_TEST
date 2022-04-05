// N과 M

#include <iostream>

using namespace std;

int n, m;
int arr[100];

int backtracking(int x){
    for (int i=0; i<x; i++){
        if (arr[x] == arr[i]) return 0;
    }
    return 1;
}

void solve(int x){
    if(x == m){
        for (int i=0; i<m; i++){
            cout << arr[i]+1 << " ";
        }
        cout << '\n';
        return;
    }

    for (int i=0; i<n; i++){
        arr[x] = i;
        if (backtracking(x)) solve(x+1);
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    solve(0);
}