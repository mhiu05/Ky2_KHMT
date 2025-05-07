#include <bits/stdc++.h>
using namespace std;

void file()
{
    freopen("CT.in", "r", stdin);
    freopen("CT.out", "w", stdout);
}

int a[105][105];
int vs[105];
int t, n, m, x;

void dfs(int u)
{
    vs[u] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (!vs[i] && a[u][i] == 1)
        {
            dfs(i);
        }
    }
}

void solve1()
{
    cin >> n >> m;
    memset(vs, 0, sizeof(vs));
    // danh sách cạnh -> ma trận kề
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    // kiểm tra liên thông
    int tplt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!vs[i])
        {
            dfs(i);
            ++tplt;
        }
    }
    if (tplt == 1)
    {
        // kiểm tra xem bậc của tất cả các đỉnh có chẵn không
        int deg[n + 5] = {0};
        for (int i = 1; i <= n; ++i)
        {
            int cnt = 0;
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j] == 1)
                    cnt++;
            }
            deg[i] = cnt;
        }
        int count = 0; // đếm số đỉnh bậc lẻ
        for (int i = 1; i <= n; ++i)
        {
            if (deg[i] % 2 != 0)
                ++count;
        }
        if (count == 0)
            cout << 1;
        else if (count <= 2)
        {
            cout << 2;
        }
        else
            cout << 0;
    }
    else
        cout << 0;
}

void solve2()
{
    cin >> n >> m >> x;
    // danh sách cạnh -> ma trận kề
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    // chu trình ueler
    vector<int> ce;
    stack<int> st;
    st.push(x);
    while (!st.empty())
    {
        int u = st.top();
        int check = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[u][i] == 1)
            {
                check = 1;
                st.push(i);
                a[u][i] = 0;
                a[i][u] = 0;
                break;
            }
        }
        if (!check)
        {
            ce.push_back(u);
            st.pop();
        }
    }
    for (int i = ce.size() - 1; i >= 0; --i)
    {
        cout << ce[i] << " ";
    }
}

int main()
{
    // file();
    cin >> t;
    if (t == 1)
        solve1();
    else
        solve2();
    return 0;
}