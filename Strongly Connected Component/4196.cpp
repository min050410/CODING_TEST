// 도미노

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

#define MAX 1000000

using namespace std;

vector<vector<int>> SCC;
stack<int> s;
vector<int> v[MAX];
int p[MAX];
bool finished[MAX];
int indegree[MAX];
int sn[MAX];
int T, n, m, a, b;
int sv;
int id;
int cnt;

int dfs(int x){
    p[x] = ++id;
    s.push(x);

    int parent = p[x];
    for (int i=0; i<v[x].size(); i++){
        int y = v[x][i];
        if (!p[y]){
            parent = min(parent, dfs(y));
        }
        else if (!finished[y]) parent = min(parent, p[y]);
    }

    if (parent == p[x]){
        vector<int> scc;
        while(1){
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            // sn 배열을 통해 어떤 scc에 속해 있는지 알 수 있음
            sn[t] = sv;
            if (t == x) break;
        }
        SCC.push_back(scc);
        // scc의 idx
        sv++;
    }
    return parent;
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> T;
    for (int t=0; t<T; t++) {

        // 초기화
        SCC.clear();
        while(!s.empty()) s.pop();
        for (int i = 0; i < n*2; i++)	v[i].clear();
        sv = 0;
        id = 0;
        cnt = 0;
        memset(indegree,0,sizeof(indegree));
        memset(finished,false,sizeof(finished));
        memset(sn,0,sizeof(sn));
        memset(p,0,sizeof(p));

        cin >> n >> m;

        // input
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            v[a].push_back(b);
        }

        // Tarjan's algorithm
        for (int i = 1; i <= n; i++) {
            if (!p[i]) dfs(i);
        }

        // 출력 test
        //    for (int i=0; i<SCC.size(); i++) {
        //        for (int j = 0; j < SCC[i].size(); j++) {
        //            cout << SCC[i][j] << " ";
        //        }
        //        cout << '\n';
        //    }

        // scc 안같으면 진입차수 + 1
        for (int i = 1; i <= n; i++) {
            for (auto j: v[i]) {
                if (sn[i] != sn[j]) indegree[sn[j]]++;
            }
        }

        // 진입차수가 0인 scc의 개수 세기
        for (int i = 0; i < sv; i++) {
            if (indegree[i] == 0) {
                cnt++;
            }
        }

        // 출력
        cout << cnt << '\n';
    }
}