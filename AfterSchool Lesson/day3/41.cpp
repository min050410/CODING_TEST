#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int prefix_sum[1001];
vector<pair<int, int>> ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        prefix_sum[i] += prefix_sum[i - 1] + i;
    }
    // two pointer
    int s = 0;
    int e = 0;
    while (s <= n && e <= n)
    {
        if (prefix_sum[e] - prefix_sum[s] == n)
        {
            ans.push_back({s, e});
            e++;
        }
        else if (prefix_sum[e] - prefix_sum[s] > n)
        {
            s++;
        }
        else
        {
            e++;
        }
    }
    reverse(ans.begin(), ans.end());
    ans.erase(ans.begin());
    for (auto i : ans)
    {
        for (int j = i.first + 1; j <= i.second; j++)
        {
            if (j == i.first + 1)
                cout << j;
            else
                cout << " + " << j;
        }
        cout << " = " << n << '\n';
    }
    cout << ans.size();
}