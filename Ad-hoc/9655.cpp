// 돌 게임 - ad hoc 풀이

#include <iostream>
using namespace std;

int main() {
	int n;           // 돌의 개수
	cin >> n;
    
	if (n % 2 == 1) {
		cout << "SK";
	}

	else {
		cout << "CY";
	}

	return 0;
}