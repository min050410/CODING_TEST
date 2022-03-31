// 여행 가자

#include <iostream>
using namespace std;

int n, m;
int parent[1000001];
int arr_input[1000000];
int arr[1000];
bool isBreak = false;
int flag;

// 경로 압축
int findParent(int x){
    // 만약 부모 노드가 아니라면
    if (parent[x] == x){
        return x;
    }
    else {
        return parent[x] = findParent(parent[x]);
    }
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

    cin >> n >> m;

    // 부모를 자기 자신으로 초기화
    for (int i=1; i<=n; i++){
        parent[i] = i;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> arr_input[j];
            if (arr_input[j]){
                Union(j, i);
            }
        }
    }

    for (int i=1; i<=m; i++){
        cin >> arr[i];
    }

    for (int i=1; i<m; i++){
        if (parent[arr[i]] != parent[arr[i+1]]){
            isBreak = true;
            break;
        }
    }

    if (isBreak){
        cout << "NO";
    }
    else {
        cout << "YES";
    }
//
//    for (int i=1; i<=n; i++){
//        cout << parent[i] << " ";
//    }

    return 0;
}