// abbc

#include <iostream>
#include <string>

using namespace std;

char s[3000001];
string a;
char change[3000001];
int cnt;
int Bcnt;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> a;

	int i = 0;
	for(const auto &iter: a){
		s[i] = iter;
		i++;
	}
	int flag = 0;

	// 1. B, A 빼기
	for (i = a.length() - 1; i >= 0;i--){
		if (s[i] == 'B'){
			int j = i;
			while (s[j] != 'A'){
				j--;
				if (j == -1) break;
				if (s[j] == 'A'){
					flag = 1;
					break;
				}
			}
			if (flag){
				cnt++;
				s[i] = 'X';
				s[j] = 'X';
				flag = 0;
			}	
		}
	}
	
	// 2. C, B 빼기
	for (i = a.length()-1;i >= 0;i--){
		if (s[i] == 'C'){
			int j = i;
			while (s[j] != 'B'){
				j--;
				if (j == -1) break;
				if (s[j] == 'B'){
					flag = 1;
					break;
				}
			}
			if (flag){
				cnt++;
				s[i] = 'X';
				s[j] = 'X';
				flag = 0;
			}	
		}
	}

	cout << cnt;
}
