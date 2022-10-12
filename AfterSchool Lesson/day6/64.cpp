#include <iostream>
#include <vector>
using namespace std;
int n, m;
int a, b;
vector<int> v[10000];
vector<int> s;
int cnt = 0;
int visited[10000];

void dfs(int x) {
    visited[x] = true;
    s.push_back(x);
    if(x == n){
        cnt++;
        s.pop_back();
        return;
    }
    for(int i: v[x]){
        if(!visited[i]){
            dfs(i);
            visited[i] = 0;
        }
    }
    s.pop_back();
}

int main() {
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        cin>>a>>b;
        v[a].push_back(b);
    }
    dfs(1);
    cout<<cnt;
}
