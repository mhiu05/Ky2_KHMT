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

void process()
{
    int t;
    cin >> t;
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    if (t == 1)
    {
        int deg[n + 1] = {0};
        for (auto items : edges)
        {
            deg[items.first]++;
            deg[items.second]++;
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << deg[i] << " ";
        }
    }
    else if (t == 2)
    {
        int m = edges.size();
        cout << n << " " << m << endl;
        int a[n + 1][m + 1] = {0};
        int j = 1;
        for (auto items : edges)
        {
            a[items.first][j] = 1;
            a[items.second][j] = 1;
            ++j;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                cout << a[i][j] << " ";
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

    process();
    return 0;
}