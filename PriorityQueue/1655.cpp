// 가운데를 말해요

// 1. 처음에 max_heap에 값 넣기
// 2. min_heap과 max_heap의 사이즈 1이 차이나게 번갈아가며 넣기
// 3. max_heap의 top이 min_heap의 top보다 크다면 top 변경
// 4. max_heap의 top은 중간값

#include <iostream>
#include <queue>

using namespace std;

int n;
int a;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<>> min_heap;
vector<int> ans;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;

        if (i==0) {
            max_heap.push(a);
        }
        else {
            if (max_heap.size() > min_heap.size()) {
                min_heap.push(a);
            } else {
                max_heap.push(a);
            }

            if (max_heap.top() > min_heap.top()) {
                int mt = max_heap.top();
                int mit = min_heap.top();
                max_heap.pop();
                min_heap.pop();
                min_heap.push(mt);
                max_heap.push(mit);
            }
        }
        ans.push_back(max_heap.top());
    }
    for (const auto A: ans) {
        cout << A << '\n';
    }
}