// 분해합

#include <iostream>
using namespace std;

int n, m;
int parent[1000001];

int findParent(int x){
    // 만약 부모 노드가 아니라면
    if (parent[x] != x){
        // 부모의 root를 저장
        parent[x] = findParent(parent[x]);
    }
    // root return
    return parent[x];
}

void Union(int a, int b){

    a = findParent(a);
    b = findParent(b);

    if (a < b){
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int c, a, b;

    cin >> n >> m;

    // 부모를 자기 자신으로 초기화
    for (int i=0; i<=n; i++){
        parent[i] = i;
    }

    for (int i=0; i<m; i++){
        cin >> c >> a >> b;
        if (!c){
             Union(a, b);
        }
        else{
            if(findParent(a) == findParent(b)){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}