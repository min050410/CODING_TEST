// 외판원 순회

#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long
#define INF 0x7fffffff

using namespace std;
int n;
int v[100];
int m[100][100];
int cost = INF;
int cnt;

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
    if (a == n){
        // count
        int flag = 0;
        for (int i=0; i<n; i++){
            if (m[i][v[i]] == 0){
                flag = 1;
                break;
            }
            cnt += m[i][v[i]];
        }
        if(!flag){
            cost = min(cost, cnt);
        }
        cnt = 0;
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

    cin >> n;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> m[i][j];
        }
    }
    recursion(0);
    cout << cost;
}