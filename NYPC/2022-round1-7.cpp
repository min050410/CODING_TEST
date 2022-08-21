// 달팽이 - 17

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T;
int n, A, B;
int arr[3001][3001];
int mx[4] = {1,1,-1,-1};
int my[4] = {1,-1,1,-1};
pair<int, int> a_pos;

void check_pos(int a, int i, int j) {
	if (a == A) {
		a_pos.first = i;
		a_pos.second = j;
	}
}

int main() {
	cin >> T;
	for (int t=0; t<T; t++) {
		
	    cin >> n >> A >> B;

	    int i = 0;
	    int j = 0;
	    arr[i][j] = 1;
	    int a = 2;
	
	    while (a <= n*n) {
	        while (j+1 < n && arr[i][j + 1] == 0) {
	            j++;
				check_pos(a, i, j);
	            arr[i][j] = a;
	            a++;
	        }
	        while (i+1 < n && arr[i + 1][j] == 0) {
	        	i++;
				check_pos(a, i, j);
	        	arr[i][j] = a;
	        	a++;
	        }
	        while (j-1>=0 && arr[i][j - 1] == 0) {
	        	j--;
				check_pos(a, i, j);
	        	arr[i][j] = a;
	        	a++;
	        }
	        while (i-1>=0&&arr[i - 1][j] == 0) {
	        	i--;
				check_pos(a, i, j);
	        	arr[i][j] = a;
	        	a++;
	        }
	    }
	
		int flag = 0;
		int av = 1;
		int k = 0;
		
		while (av) {
			av = 0;
			for (int i=0; i<4; i++) {
				int cx = a_pos.second + mx[i]*k;
				int cy = a_pos.first + my[i]*k;
				if (cx >= 0 && cx < n && cy >= 0 && cy < n) {
					// 가능
					av = 1;
					if (arr[cy][cx] == B) {
						flag = 1;
						// 끝냄
						av = 0;
					}
				}
			}
			k++;
		}
	
		if (flag) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
		
		// 초기화
		a_pos.first = 0;
		a_pos.second = 0;

		for(int i=0; i<n; i++)
		{
			memset(arr[i], 0, sizeof(arr[i]));
		}
		
	}
}