// 이번학기 평점은 몇점?

#include <iostream>
#include <cmath>

using namespace std;

string s;
float n;
float a, b;
float cnt;
float total;

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s >> a >> s;
		cnt += a;
		if (s == "A+") total += a*4.3;
		else if (s == "A0") total += a*4.0;
		else if (s == "A-") total += a*3.7;
		else if (s == "B+") total += a*3.3;
		else if (s == "B0") total += a*3.0;
		else if (s == "B-") total += a*2.7;
		else if (s == "C+") total += a*2.3;
		else if (s == "C0") total += a*2.0;
		else if (s == "C-") total += a*1.7;
		else if (s == "D+") total += a*1.3;
		else if (s == "D0") total += a*1.0;
		else if (s == "D-") total += a*0.7;
		else total += a*0.0;
	}
	total = (total/cnt)*1000;
	total+=(int)total%10>4;
	total/=1000;
	printf("%.2f", total);
}