#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a;
vector<int> v;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    cout << lower_bound(v.begin(), v.end(), m) - v.begin() + 1;
}