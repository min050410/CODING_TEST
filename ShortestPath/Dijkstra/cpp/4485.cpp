// 녹색옷 입은 애가 젤다지??

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string.h>
#define INF 0x7fffffff

using namespace std;

int n, a, t;
int v[130][130];
int dis[130][130];
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};

// weight, y_position, x_position
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>> ,greater<>> pq;

void dijkstra(int sx, int sy) {
    dis[sy][sx] = v[sy][sx];
    pq.push({v[sy][sx], sy, sx});
    while (!pq.empty()) {
        int w = get<0>(pq.top());
        pair<int, int> temp = make_pair(get<1>(pq.top()), get<2>(pq.top()));
        pq.pop();
        for (int i=0; i<4; i++){
            // 이동한 뒤 좌표
            int nx = temp.second + mx[i];
            int ny = temp.first + my[i];
            if (ny >= 0 && ny < n && nx >= 0 && nx < n){
                if (dis[ny][nx] > w + v[ny][nx]){
                    dis[ny][nx] = w + v[ny][nx];
                    pq.push({dis[ny][nx], ny, nx});
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    while (true){
        t++;
        cin >> n;
        if (n == 0){
            break;
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin >> a;
                v[i][j] = a;
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                dis[i][j] = INF;
            }
        }

        dijkstra(0, 0);

//    for (int i=0; i<m; i++){
//        for (int j=0; j<n; j++){
//            cout << dis[i][j];
//        }
//        cout << '\n';
//    }

        cout << "Problem " << t << ": " << dis[n-1][n-1] << '\n';

        // reset
        memset(v, 0, sizeof(v));
        memset(dis, 0, sizeof(dis));
    }

    return 0;
}