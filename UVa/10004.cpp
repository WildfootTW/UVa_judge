#include <iostream>
#include <vector>
#include "memory.h"

using namespace std;

bool used[200],flag;
vector<int> V[200];
int color[200];

void initial(int n)
{
    for(int i = 0;i <= n;i++)
    {
        V[i].clear();
        used[i] = 0;
        color[i] = 0;
    }
    flag = 1;
    color[0] = 1;
    used[0] = 1;
}
void check(int n)
{
    for(int i:V[n])
    {
        if(color[i] == color[n])
        {
            flag = 0;
            cout << "{!!" << i << " " << n << "!!}";
        }
    }
}

void DFS(int n)
{
    //cout << n << " |" << ncolor << "| ";

    cout << n << " ";
    cout << "|" << color[n] << "| ";
    check(n);
    for(int e:V[n])
    {
        if(color[n] == 1)
            color[e] = 2;
        else
            color[e] = 1;
    }
    for(int e:V[n])
    {
        if(!used[e])
        {
            used[e] = true;
            DFS(e);
        }
    }
}
int main()
{
    int n,e;
    while(cin >> n)
    {
        if(!n)
            break;
        cin >> e;
        initial(n);
        while( e-- )
        {
            int a,b;
            cin >> a >> b;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        
        DFS(0);

        if(flag)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}
