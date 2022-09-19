#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n, a;
int m;
set<int> s1;
vector<int> ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s1.insert(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        if (s1.count(a) != 0)
            ans.push_back(a);
    }
    sort(ans.begin(), ans.end());
    for (int i : ans)
    {
        cout << i << ' ';
    }
}