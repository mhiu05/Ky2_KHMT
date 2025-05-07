#include <bits/stdc++.h>
using namespace std;

void file()
{
    freopen("CT.in", "r", stdin);
    freopen("CT.out", "w", stdout);
}

vector<vector<int>> ans;
vector<int> path(105);
int vs[105];
int a[105][105];
int n, u;

void hamilton(int k)
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[path[k - 1]][i] == 1)
        {
            if (k == n && i == u)
            {
                vector<int> tmp;
                for (int i = 0; i < n; ++i)
                {
                    tmp.push_back(path[i]);
                }
                tmp.push_back(u);
                ans.push_back(tmp);
            }
            else if (!vs[i])
            {
                vs[i] = 1;
                path[k] = i;
                hamilton(k + 1);
                vs[i] = 0;
            }
        }
    }
}

int main()
{
    // file();
    cin >> n >> u;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    path[0] = u;
    vs[u] = 1;
    hamilton(1);
    cout << ans.size() << endl;
    if (ans.size() != 0)
    {
        for (int i = 0; i < ans.size(); ++i)
        {
            for (int x : ans[i])
                cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}