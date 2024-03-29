// 알고스팟 
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define INF 0x7fffffff

using namespace std;

int n, m, a;
int v[100][100];
int dis[100][100];
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};

// weight, y_position, x_position
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>> ,greater<>> pq;

void dijkstra(int sx, int sy) {
    // 초기 위치 비용 설정
    dis[sy][sx] = v[sy][sx];
    // pq에 초깃값 푸시
    pq.push({v[sy][sx], sy, sx});
    while (!pq.empty()) {
        // 가중치
        int w = get<0>(pq.top());
        // y_position, x_position
        pair<int, int> temp = make_pair(get<1>(pq.top()), get<2>(pq.top()));
        // 변수에 담았으므로 pop()
        pq.pop();
        for (int i=0; i<4; i++){
            // 이동한 뒤 좌표
            int nx = temp.second + mx[i];
            int ny = temp.first + my[i];
            // 범위 설정
            if (ny >= 0 && ny < m && nx >= 0 && nx < n){
                // dis 배열 초기화 min(dis[][], w + v[ny][nx]) 
                if (dis[ny][nx] > w + v[ny][nx]){
                    dis[ny][nx] = w + v[ny][nx];
                    // 결과 푸시 (가중치를 제일 앞에)
                    pq.push({dis[ny][nx], ny, nx});
                }
            }
        }
    }
}

int main(){

    scanf("%d %d", &n, &m);

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            scanf("%1d", &a);
            v[i][j] = a;
        }
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            dis[i][j] = INF;
        }
    }

    dijkstra(0, 0);

// 출력 test
//    for (int i=0; i<m; i++){
//        for (int j=0; j<n; j++){
//            cout << dis[i][j];
//        }
//        cout << '\n';
//    }

    printf("%d", dis[m-1][n-1]);
}

// 입력 cin 이랑 scanf 동시에 써서 틀렸음. 다음에 scanf("%1d", &a)를 사용할 때 하나로 통일하자.

