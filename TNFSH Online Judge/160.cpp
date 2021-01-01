/*
 *  fail
 *
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAXN 101
#define INF 2147483647
using namespace std;

struct Edge
{
    int to, cost;
};

int min_array[MAXN];

int N;

int main()
{
    int T, M;
    cin >> T;
    vector<Edge> Vec[MAXN];
    while(T--)
    {
        cin >> N >> M; 
        while(M--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if(u == v)
               continue;

            for(Edge e:Vec[u])
            {
                if(e.to == v)
                {
                    if(e.cost > w)
                        e.cost = w;
                    continue;
                }
            }

            Vec[u].push_back({v, w});
        }

        int Q;
        cin >> Q;
        while(Q--)
        {
            int u, v;
            cin >> u >> v;
            
            //initial
            queue<int> q;
            q.push(u);
            for(int i = 0;i <= N;i++)
                min_array[i] = INF;
            min_array[u] = 0;

            while(!q.empty())
            {
                int start = q.front();
                q.pop();
                for(Edge e:Vec[start])
                {
                    if(min_array[start] + e.cost < min_array[e.to]) 
                    {
                        min_array[e.to] = min_array[start] + e.cost;
                        q.push(e.to);
                    }
                }
            }
            if(min_array[v] == INF)
                cout << -1 << endl;
            else
                cout << min_array[v] << endl;
        }
    }
    return 0;
}
