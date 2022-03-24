// 부녀회장이 될 테야!

#include <iostream>
#include <vector>

using namespace std;

int T;
int n, m;
int arr[100][100];
vector<int> res;


int main(){

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    for (int t; t<T; t++){
        // n: 층 m: 호
        cin >> n >> m;
        for (int i=0; i<m; i++){
            if(arr[0][i]==0){
                arr[0][i] = i+1;
            }
        }

        for (int i=1; i<=n; i++){
            for (int j=0; j<m; j++){
                if(arr[i][j]==0){
                    if(j==0){
                        arr[i][j] = 1;
                    }
                    else{
                        arr[i][j] = arr[i-1][j] + arr[i][j-1];
                    }
                }
            }
        }

        res.push_back(arr[n][m-1]);
    }

    // print
    for(const auto &r: res){
        cout << r << '\n';
    }
}