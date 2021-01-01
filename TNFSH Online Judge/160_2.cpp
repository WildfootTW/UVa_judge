/*
 *  fail
 *
 *
 */
#include <iostream>
#include <queue>
#include <cstring>

#define MAXN 101
#define INF 2147483647
using namespace std;

int graph[MAXN][MAXN] = {0};

int min_array[MAXN];

int N;

int main()
{
    int T, M;
    cin >> T;
    while(T--)
    {
        memset(graph, 0, sizeof(graph));
        cin >> N >> M; 
        while(M--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if(u == v)
               continue;

            if(graph[u][v])
                graph[u][v] = min(w, graph[u][v]);
            else
                graph[u][v] = w;
        }

        /*
        for(int i = 1;i <= N;i++)
        {
            for(int j = 1;j <= N;j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        */
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
                for(int j = 1;j <= N;j++)
                {
                    if(graph[start][j])
                    {
                        if(graph[start][j] + min_array[start] < min_array[j])
                        {
                            min_array[j] = graph[start][j] + min_array[start];
                            q.push(j);
                        }
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
