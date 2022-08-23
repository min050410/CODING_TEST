// 거짓말

// 실수한점 : 진실을 아는 사람을 판별할 때 
// parent[vec] == parent[t_man[i]] 가 아닌 부모를 거슬러 올라가서
// Find(parent[vec])==Find(parent[t_man[i]]) 로 판별해야 맞는 테스트 케이스가 있다

#include <iostream>
#include <vector>
using namespace std;

#define inf 0x7fffffff
#define ll long long

int n, m;
int t, p, a;
int cnt;
int t_man[1000];
int parent[1000];
vector<int> v[1000];

int Find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

int match (int vec) {
    for (int i=0; i<t; i++) {
        // 자객
        if(Find(parent[vec])==Find(parent[t_man[i]])) {
            return 1;
        }
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }

    cin >> t;
    // 진실을 아는 사람 입력
    for (int i=0; i<t; i++) {
        cin >> t_man[i];
    }

    // union find
    int before;
    for (int i=0; i<m; i++) {
        cin >> p;
        for (int j=0; j<p; j++) {
            cin >> a;
            v[i].push_back(a);
            if (j!=0) Union(before, a);
            before = a;
        }
    }

    // parent배열
//    for (int i=1; i<=n; i++) {
//        cout << parent[i] << ' ';
//    }
//    cout << '\n';

    int flag = 1;
    for (int i=0; i<m; i++) {
        for (const auto &vec:v[i]) {
            // 거짓말이 들통났을 때
            if(match(vec)){
                flag = 0;
            }
        }
        if (flag) {
            cnt++;
        }
        flag = 1;
    }

    cout << cnt;
}


