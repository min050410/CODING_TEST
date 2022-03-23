// 트리의 부모 찾기

#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
int parent[100001];
int n, a, b;
int visited[100001];

void dfs(int s){
    visited[s] = 1;
    for(const auto &v_each:v[s]){
        if(visited[v_each]==0){
            parent[v_each] = s;
            dfs(v_each);
        }
    }
}


int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n-1; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for (int i=2; i<=n; i++){
        cout << parent[i] << '\n';
    }
}