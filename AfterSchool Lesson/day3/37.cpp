#include <iostream>
#include <queue>
using namespace std;
int n, m;
int a;
deque<int> cache(5, 0);
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (cache[j] == a)
            {
                cache.erase(cache.begin() + j);
                cache.push_front(a);
                flag = 1;
                break;
            }
        }
        if (!flag)
            cache.push_front(a);
    }
    int j = 0;
    for (int i : cache)
    {
        cout << i << ' ';
        j++;
        if (j == n)
            break;
    }
}