#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

using ll = long long;

const int mod = 1e9 + 7;
const int MAXN = 100005;

void solve()
{
    int t;
    cin >> t;
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            int cnt = 0;
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j] == 1)
                    ++cnt;
            }
            cout << cnt << " ";
        }
    }
    else if (t == 2)
    {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j] == 1)
                    ++cnt;
            }
        }
        int m = cnt / 2;
        cout << n << " " << m << endl;

        vector<pair<int, int>> edges;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j] == 1 && i < j)
                {
                    edges.push_back({i, j});
                }
            }
        }
        for (auto items : edges)
        {
            cout << items.first << " " << items.second << endl;
        }
    }
}

int main()
{
    faster();
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    solve();
    return 0;
}