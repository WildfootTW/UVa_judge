#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int ptr,Prime[169],level[1001],ans = 2147483647; //168+1
vector<int> V[1001];
bool used[1001],flag,used_Prime[1001];
void Prime_factor(int n)
{
    for(unsigned int i = 2;i <= n;i++)
    {
        while(n % i == 0)
        {
            Prime[ptr] = i;
            ptr++;
            if(Prime[ptr - 1] == Prime[ptr - 2])
                ptr--;
            n = n / i;
        }
    }
}
void initial_Prime(int n)
{
    ptr = 1;
    for(int i = 0;i < n;i++)
    {
        Prime[i] = 0;
    }
}
void initial_graph(int n,int S)
{
    for(int i = 0;i <= n;i++)
    {
        V[i].clear();
        used[i] = 0;
        used_Prime[i] = 0;
    }
    for(int i = S;i <= n;i++)
        level[i] = 2147483647;
    level[S] = 0;
    flag = 1;
}

int main()
{
    int S,T,NN = 0;
    while(cin >> S >> T)
    {
        NN++;
        if(S == 0 || T == 0)
            break;
        queue<int> qu;
        qu.push(S);
        initial_graph(T,S);
        /*for(int i = S;i <= T;i++)
        {
            cout << "level[" << i << "] = " << level[i] << endl;
        }*/
        while(!qu.empty())
        {
           
            int node = qu.front();
            if(node < T && used_Prime[node] == 0)
            {
                initial_Prime(node);
                Prime_factor(node);
                used_Prime[node] = 1;
                for(int i = 1;i < ptr;i++)
                {
                    int Newnode = node + Prime[i];
                    V[node].push_back(Newnode);
                    qu.push(Newnode);
                    if(level[Newnode] > level[node] + 1)
                    {
                        level[Newnode] = level[node] + 1;
                        cout << "When node = " << node;
                        cout << " level [" << Newnode <<"] = " << level[Newnode] << endl;
                    }
                    if(Newnode == T)
                    {
                        flag = 0;
                        if(ans > level[Newnode])
                            ans = level[Newnode];
                    }
                }
            }
            qu.pop();
        }

        for(int i = S;i <= T;i++)
        {
            cout << "level[" << i << "] = " << level[i] << endl;
        }
        
        if(flag)
            ans = -1;
        cout <<"Case "<< NN <<": "<< ans << endl;
    }
    return 0;
}
