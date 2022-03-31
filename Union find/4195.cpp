// 친구 네트워크

// 시간 초과가 걸려 많이 고생한 문제이다
// 결국 map을 사용해서 해결할 수 있었다
// map을 쓰기 전 사용한 함수들도 의미가 있을 것 같아 넣었다

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int T;
int n;
int parent[1000001];
int sized[1000001];
string f1, f2;

vector<string> set_insert(vector<string> v, string f){
    bool flag = false;
    for (const auto &node: v){
        if(node == f){
            // 중복되면 flag 올리기
            flag = true;
        }
    }
    if(!flag){
        v.push_back(f);
    }
    return v;
}

int GetIndex(string f, vector<string> v)
{
    int idx = 1;
    for (const auto &u : v) {
        if (u == f){
            return idx;
        }
        idx++;
    }
    return -1;
}

// 경로 압축
int findParent(int x){
    if (parent[x] == x){
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

void Union(int a, int b){

    a = findParent(a);
    b = findParent(b);

    // 같으면 이미 같은 트리 합치지 않는다
    if (a == b){
        return;
    }

    if (a < b){
        sized[a] += sized[b];
        parent[b] = a;
    }
    else {
        sized[b] += sized[a];
        parent[a] = b;
    }

}

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    for (int t=0; t<T; t++){
//        vector<string> v;
        map<string, int> m;
        int nodeNum = 1;
        cin >> n;

        // 부모를 자기 자신으로 초기화
        // 최대 n*2
        for (int i=1; i<=n*2; i++){
            sized[i] = 1;
            parent[i] = i;
        }

        for (int i=0; i<n; i++){
            cin >> f1 >> f2;
            // 중복이 아니면 vector에 넣기
            if(m.count(f1) == 0){
                m[f1] = nodeNum++;
            }
            if(m.count(f2) == 0){
                m[f2] = nodeNum++;
            }

            Union(m[f1], m[f2]);

            cout << sized[findParent(m[f1])] << '\n';
        }
    }
    return 0;
}