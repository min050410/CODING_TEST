// 서로 다른 문자열의 개수

#include <iostream>
#include <set>

using namespace std;

string s;
char a[1000];
set<string> se;

int main() {
    cin >> s;
    for (int i=1; i<=s.length(); i++) {
        for (int j=0; j<s.length()-i+1; j++) {
            se.insert(s.substr(j, i));
        }
    }
    cout << se.size();
}
