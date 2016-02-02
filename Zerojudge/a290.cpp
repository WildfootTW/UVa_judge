#include <iostream>
#include <vector>
#include <stack>
#include "memory.h"

using namespace std;
typedef long long ll;

bool used[10001];
vector<int> V[801];
bool flag = 0;

void DFS(int n,int q)
{
    if(n == q)
        flag = 1;
    for(int e:V[n])
    {
        if(!used[e])
        {
            used[e] = true;
            DFS(e,q);
        }
    }
}
int main()
{
    int n, m, Q1, Q2;
    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
    }
    memset(used,0,sizeof(used));
    cin >> Q1 >> Q2;
    DFS(Q1,Q2);
    if(flag)
        cout << "Yes!!!" << endl;
    else
        cout << "No!!!" << endl;
}


