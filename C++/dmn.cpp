// script for exercise "Domino" from contest ilocamp 3 grupa srenia
// its content you can find there: https://szkopul.edu.pl/
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

int n, base = 1;
int d[3000009], a[1000009];
ll odl[3000009];
void zad(int x);
int znajdz(int x);
int dok(ll x, int l, int r, int v);
void ustaw(int v, int l, int r, int x, int y, int val);

//===============================================================================================
int main()
{
    scanf("%d", &n);
    while (base < n)
        base <<= 1;
    for (int i = 0; i < base * 2; i++)
        d[i] = INT_MAX, odl[i] = LLONG_MAX;
    for (int i = 0, temp; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1, temp; i < n; i++)
    {
        scanf("%d", &temp);
        odl[i + base] = temp;
        if (i > 1)
            odl[i + base] += odl[i + base - 1];
    }
    odl[base] = 0;
    for (int i = base - 1; i; i--)
        odl[i] = min(odl[i * 2], odl[i * 2 + 1]);
    for (int i = 0; i < n; i++)
        zad(i);
    printf("%d\n", n - znajdz(n - 1) - 1);
}
//===============================================================================================
void zad(int x)
{
    int y = znajdz(x) + 1;
    if (!x)
        y = 1;
    ll z = (ll)a[x] + odl[base + x];
    int dokiedy = min(dok(z, 0, base - 1, 1), base - 1);
    ustaw(1, 0, base - 1, x + 1, dokiedy, y);
}
int znajdz(int x)
{
    x += base;
    int ret = INT_MAX;
    while (x)
    {
        ret = min(ret, d[x]);
        x >>= 1;
    }
    return ret;
}
int dok(ll x, int l, int r, int v)
{
    if (x <= odl[v])
        return -1;
    if (l == r)
        return r;
    return max(dok(x, l, (l + r) / 2, v * 2), dok(x, (l + r) / 2 + 1, r, v * 2 + 1));
}
void ustaw(int v, int l, int r, int x, int y, int val)
{
    if (l > y || r < x)
        return;
    if (l >= x && r <= y)
    {
        d[v] = min(d[v], val);
        return;
    }
    ustaw(v * 2, l, (l + r) / 2, x, y, val);
    ustaw(v * 2 + 1, (l + r) / 2 + 1, r, x, y, val);
}
