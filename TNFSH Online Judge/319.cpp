//AC WA WA TLE TLE
#include <iostream>
#include <algorithm>

using namespace std;

#define maxm 50005
#define maxn 505

int n, m; // n = 點 m = 邊
struct Edge{
    int u, v, cost;
};
Edge es[maxm];
bool ban[maxm];

void initial()
{
    for(int i = 0;i < maxm;i++)
        ban[i] = 1;
}


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
int Kruskal(int banM)
{
    int ans = 0;
    for(int i = 0;i < n;i++)
        pa[i] = i;
    sort(es, es + m, cmp);
    for(int i = 0;i < m;i++)
    {
        if(i == banM)
            continue;

        Edge e = es[i];
        if(find(e.u) != find(e.v))
        {
            U(e.u, e.v);
            ans += e.cost;
        }
        else
        {
            if(banM == -1)
            {
                ban[i] = 0;
                //cout << "ban[" << i << "] = 0" << endl;
            }
        }
    }
    for(int i = 1;i < n;i++)
        if(find(i) != find(i - 1))
            return -1;
    return ans;
}

int main()
{
    initial();
    cin >> n >> m;
    for(int i = 0;i < m;i++)
    {
        cin >> es[i].u >> es[i].v >> es[i].cost;
    }
    int real = Kruskal(-1);
    
    for(int i = 0;i < m;i++)
    {
        if(ban[i])
        {
            //cout << "Kruskal(ban" << i << ")" << Kruskal(ban[i]) << endl;
            if(Kruskal(i) == real)
            {

                ban[i] = 0;
                //cout << "ban[" << i << "] = 0" << endl;
            }
        }
    }
    int ans_sum = 0;
    int ans = 0;
    for(int i = 0;i < m;i++)
    {
        //if(ban[i])
        //    cout << i << " ";
        //cout << ban[i] << " ";
        if(ban[i])
        {
            ans++;
            ans_sum += es[i].cost;
        }

    }
    cout << ans << " " << ans_sum << endl;
    
    return 0;
}
