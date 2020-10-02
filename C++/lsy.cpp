// script for exercise "Las" from contest ilocamp 3 grupa srednia
// its contents you can find there: https://szkopul.edu.pl/
#include <bits/stdc++.h>
#define pc putchar
#define gc getchar
#define gcu getchar_unlocked
#define fi first
#define se second
#define pb push_back
#define mod ((ll)1e9 + 7)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
//===============================================================================================

int n, d, ans;
int a[1009][1009];
pair<int, pair<int, int>> f[1009][1009];
vector<pair<int, pair<int, int>>> v;
void find(pair<int, int> p);
pair<int, int> koniec(int x, int y);

//===============================================================================================
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            v.pb({a[i][j], {i, j}});
            f[i][j] = {0, {i, j}};
        }
    sort(v.begin(), v.end());
    for (int i = 0; i < n * n; i++)
    {
        find(v[i].se);
        if (ans)
        {
            cout << v[i].fi;
            return 0;
        }
    }
}
//===============================================================================================
void find(pair<int, int> p)
{
    vector<pair<int, int>> vec;
    int x = p.fi, y = p.se;
    if (x - 1 >= 0)
        if (a[x - 1][y] <= a[x][y])
            vec.pb(koniec(x - 1, y));
    if (y + 1 < n)
        if (a[x][y + 1] <= a[x][y])
            vec.pb(koniec(x, y + 1));
    if (y - 1 >= 0)
        if (a[x][y - 1] <= a[x][y])
            vec.pb(koniec(x, y - 1));
    if (x + 1 < n)
        if (a[x + 1][y] <= a[x][y])
            vec.pb(koniec(x + 1, y));
    vec.pb({x, y});
    sort(vec.begin(), vec.end());
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] == vec[i - 1])
        {
            vec.erase(vec.begin() + i);
            i--;
        }
    }
    for (int i = 1; i < vec.size(); i++)
    {
        f[vec[0].fi][vec[0].se].fi += f[vec[i].fi][vec[i].se].fi;
        f[vec[i].fi][vec[i].se] = {0, {vec[0].fi, vec[0].se}};
    }
    f[vec[0].fi][vec[0].se].fi++;
    if (f[vec[0].fi][vec[0].se].fi >= d)
        ans++;
}
pair<int, int> koniec(int x, int y)
{
    if (f[x][y].se == make_pair(x, y))
        return {x, y};
    f[x][y].se = koniec(f[x][y].se.fi, f[x][y].se.se);
    return f[x][y].se;
}
