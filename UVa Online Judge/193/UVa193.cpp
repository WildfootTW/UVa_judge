#include <iostream>
#include <vector>
#include "memory.h"

using namespace std;

bool used[200];
vector<int> V[200];
int color[200],colorAns[200];
int MaxAns,Tans;

void initial(int n)
{
    for(int i = 1;i <= n;i++)
    {
        V[i].clear();
    }
    MaxAns = 0;
}
void initial_small(int n)
{
    for(int i = 1;i <= n;i++)
    {
        used[i] = 0;
        color[i] = 0;
    }
    Tans = 0;
}
bool Check(int n)
{
    for(int i:V[n])
        if(color[i] == 1)
            return 0;

    return 1;
}
void DFS(int n)
{
    used[n] = true;
    if(Check(n))
    {
        color[n] = 1;
        Tans++;
    }
    else 
        color[n] = 2;
    //cout << n << " |" << color[n] << "| ";
    for(int e:V[n])
    {
        if(!used[e])
        {
            DFS(e);
        }
    }
}
int main()
{
    int m;
    cin >> m;
    while( m-- )
    {
        int n,k;
        cin >> n >> k;
        initial(n + 1);
        while( k-- )
        {
            int a,b;
            cin >> a >> b;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        
        for(int i = 1;i <= n;i++)
        {
            initial_small(n + 1);
            DFS(i);
            for(int j = i;j <= n + i;j++)
            {
                int temp = j;
                if(temp > n)
                    temp = temp - n;
                if(used[temp] == 0)
                    DFS(temp);
                if(Tans > MaxAns)
                {
                    MaxAns = Tans;
                    for(int k = 1;k <= n;k++)
                    {
                        colorAns[k] = color[k];
                    }
                }
            }
            //cout << endl;
        }
        cout << MaxAns << endl;
        for(int i = 1;i <= n;i++)
        {
            if(colorAns[i] == 1)
                cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
