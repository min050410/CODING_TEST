// codeup - 정렬 기준

#include <iostream>
#include <queue>

using namespace std;
int n;
int a, b;
int j;
priority_queue<pair<int, int>> pq;
vector<pair<int,int>> v;
int visited[10000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a >> b;
        pq.push(make_pair(a, b));
        v.push_back(make_pair(a,b));
    }

    for (int i=0; i<n; i++){
        pair<int, int> temp = pq.top();

        for (j=0; j<n; j++){

            if(v[j]==temp && visited[j]==0){
                visited[j] = 1;
                break;
            }

        }

        cout << j+1 << ' ' << temp.first << ' ' << temp.second << '\n';

        pq.pop();
    }
}
