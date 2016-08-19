/* hungarian algorithm
 * Done!
 *
 *          Wildfoot
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#define MAXN_1 505
#define MAXN_2 505

using namespace std;

int n1, n2;
int match[MAXN_2]; //每個n2裡的點匹配到哪裡

vector<int> g[MAXN_1];
bool visit[MAXN_2];

struct place{
    double x, y;
};

double distance(place a, place b)
{
    //cout << sqrt(pow(a.x - b.x, 2) + pow(a.x - b.x, 2)) << endl;
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool DFS(int u)
{
    for(int v:g[u])
    {
        if(visit[v])
            continue;
        visit[v] = 1;
        if(match[v] == -1 || DFS(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}
inline int max_match()
{
    int ans = 0;
    memset(match, -1, sizeof(int) * n2);
    for(int i = 0;i < n1;i++)
    {
        memset(visit, 0, sizeof(bool) * n2);
        if(DFS(i))
            ans++;
    }
    return ans;
}


int main()
{
    int n, m, s, v;
    while(cin >> n >> m >> s >> v)  //n gophers ,m g hole
    {
        n1 = n; n2 = m;
        
        int max_distance = (s * v);
        place gophers[n], gopher_h[m];
        for(int i = 0;i < n;i++)
        {
            cin >> gophers[i].x >> gophers[i].y;
        }
        for(int i = 0;i < m;i++)
        {
            cin >> gopher_h[i].x >> gopher_h[i].y;
        }

        for(int i = 0;i < n;i++)
        {
            g[i].clear();
            for(int j = 0;j < m;j++)
            {
                if(distance(gophers[i], gopher_h[j]) < max_distance)
                {
                    g[i].push_back(j);
                    //cout << "creat edge between " << i << ", " << j << endl;
                }
            }
        }
        int ANS = max_match();
        cout << n - ANS << endl;
    }
    return 0;
}
