#include <iostream>
#include <queue>
using namespace std;
int n, a;
int m;
priority_queue<int, vector<int>, greater<>> pq;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        pq.push(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        pq.push(a);
    }
    while (!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
}