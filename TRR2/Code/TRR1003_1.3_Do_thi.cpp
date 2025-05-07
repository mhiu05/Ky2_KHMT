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
        vector<pair<int, int>> edges;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i < j && a[i][j] == 1)
                    edges.push_back({i, j});
            }
        }
        int m = edges.size();
        cout << n << " " << m << endl;
        int ans[n + 1][m + 1] = {0};
        for (int i = 0; i < m; ++i)
        {
            ans[edges[i].first][i + 1] = 1;
            ans[edges[i].second][i + 1] = 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    faster();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    solve();
    return 0;
}