#include <iostream>
#include <algorithm>

using namespace std;

#define maxm 500005
#define maxn 10005

int n, m; // n = 點 m = 邊
struct Edge{
    int u, v, cost;
};
Edge es[maxm];

bool cmp(Edge a, Edge b)
{
    return a.cost < b.cost;
}

int pa[maxn];
int find(int x)
{
    if(pa[x] == x)
        return x;
    return pa[x] = find(pa[x]);
}
void U(int x, int y)
{
    pa[find(x)] = find(y);
}
int Kruskal()
{
    int ans = 0;
    for(int i = 0;i < n;i++)
        pa[i] = i;
    sort(es, es + m, cmp);
    for(int i = 0;i < m;i++)
    {
        Edge e = es[i];
        if(find(e.u) != find(e.v))
        {
            U(e.u, e.v);
            ans += e.cost;
        }
    }
    for(int i = 1;i < n;i++)
        if(find(i) != find(i - 1))
            return -1;
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 0;i < m;i++)
    {
        cin >> es[i].u >> es[i].v >> es[i].cost;
    }
    cout << Kruskal() << endl;
    return 0;
}
