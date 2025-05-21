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
        cout << n << endl;
        set<int> se[n + 1];
        for (auto items : edges)
        {
            se[items.first].insert(items.second);
            se[items.second].insert(items.first);
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << se[i].size() << " ";
            for (int x : se[i])
                cout << x << " ";
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