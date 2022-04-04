// Strongly Connected Component

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;

// dfs
int dfs(int x){
    // 고유 노드 번호 설정
    d[x] = ++id;
    s.push(x);

    int parent = d[x];
    for (int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        // 방문하지 않은 이웃 - dfs
        if (d[y] == 0) parent = min(parent, dfs(y));
            // 처리중인 이웃 - d[y] (already solved value)
        else if(!finished[y]) parent = min(parent, d[y]);
    }

    // 부모 노드가 자기 자신인 경우
    if (parent == d[x]){
        vector<int> scc;
        while(1){
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if(t == x) break;
        }
        SCC.push_back(scc);
    }
    return parent;
}

int main(void) {

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int v = 11;
    a[1].push_back(2);
    a[2].push_back(3);
    a[3].push_back(1);
    a[4].push_back(2);
    a[4].push_back(5);
    a[5].push_back(7);
    a[6].push_back(5);
    a[7].push_back(6);
    a[8].push_back(5);
    a[8].push_back(9);
    a[9].push_back(10);
    a[10].push_back(11);
    a[11].push_back(3);
    a[11].push_back(8);

    for (int i=1; i<=v; i++){
        if (d[i] == 0) dfs(i);
    }

    cout << "SCC의 갯수: " << SCC.size() << '\n';
    for (int i=0; i<SCC.size(); i++){
        cout << i+1 << "번째  SCC: ";
        for (int j=0; j< SCC[i].size(); j++){
            cout << SCC[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}