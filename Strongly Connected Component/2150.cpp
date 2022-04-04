// Strongly Connected Component

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;

int v, e, a, b;
int id, d[MAX];
bool finished[MAX];
vector<int> g[MAX];
vector<vector<int>> SCC;
stack<int> s;

// dfs
int dfs(int x){

	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for (int i=0; i<g[x].size(); i++){
		int y = g[x][i];
		if (!d[y]) parent = min(parent, dfs(y));
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	if (parent == d[x]){
		vector<int> scc;
		while(1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

//bool compare (vector<vector<int>> l, vector<vector<int>> r){
//    return l > r;
//}

int main(void) {

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> v >> e;

	for (int i=0; i<e; i++){
		cin >> a >> b;
		g[a].push_back(b);
	}

	for (int i=1; i<=v; i++){
		if (!d[i]) dfs(i);
	}

	cout << SCC.size() << '\n';

    // sort
    for (int i=0; i<SCC.size(); i++){
        sort(SCC[i].begin(), SCC[i].end());
    }

    sort(SCC.begin(), SCC.end());

	for (int i=0; i<SCC.size(); i++){
		for (int j=0; j<SCC[i].size(); j++){
			cout << SCC[i][j] << ' ';
		}
		cout << -1 << '\n';
	}
	return 0;
}