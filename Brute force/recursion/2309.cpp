// 일곱 난쟁이 - 순열로 모든 경우의 수를 구하여 해결

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Select[1000];
int arr[1000];
vector<int> ans;

void Print() {
    if (ans.size()) return;
    for (int i=0; i<9; i++) {
        if (Select[i] == 1) {
            ans.push_back(arr[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (const auto &a: ans) {
        cout << a << '\n';
    }
}

void DFS(int idx, int s, int size) {
    if (s == 100 && size == 7) {
        Print();
        return;
    }
    for (int i=idx; i<9; i++) {
        if (Select[i] == 1) continue;
        Select[i] = 1;

        DFS(i, s+arr[i], size+1);
        Select[i] = 0;
    }
}

int main() {
    for (int i=0; i<9; i++) {
        cin >> arr[i];
    }
    DFS(0, 0, 0);
}