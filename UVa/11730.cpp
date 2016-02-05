#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int ptr,Prime[169],level; //168+1
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
void initial_graph(int n)
{
    for(int i = 0;i <= n;i++)
    {
        V[i].clear();
        used[i] = 0;
        used_Prime[i] = 0;
    }
    level = 0;
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
        initial_graph(T);
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
                    //cout << node <<" + "<< Prime[i] <<" = "<< node + Prime[i] << endl;
                    V[node].push_back(node + Prime[i]);
                    //V[node + Prime[i]].push_back(node);
                    qu.push(node + Prime[i]);
                    //cout << Prime[i] << " ";
                }
            }
            qu.pop();
        }

        for(int i = 0;i <= 1000;i++)
        {
            
            for(int j:V[i])
            {
                cout << "from " << i << " to " << j << endl;
                //cout << "&&" << i << "&&";
                //cout <<"|"<< j << "|"<< endl;
            }
        }

        //cout << "Start BFS!!" << endl;
        //BFS
        pair<int,int> node_pair[1000];
        node_pair[S].first = S;
        node_pair[S].second = 0;
        queue<int> bfsqu;
        //bfsqu.push(S);
        bfsqu.push(node_pair[S].first);
        //used[S] = true;
        used[node_pair[S].first] = 1;
        while(!bfsqu.empty())
        {
            int node = bfsqu.front();
            bfsqu.pop();
            //cout << "node = " << node << "T = " << T << endl;
            if(node == T)
            {
                level = node_pair[node].second;
                flag = 0;
                break;
            }
            //cout << V[node][0];
            for( int i:V[node] )
            {
                //cout << i << " ";
                if( !used[i] )
                {
                    node_pair[i].first = i;
                    node_pair[i].second = node_pair[node].second + 1;
                    used[node_pair[i].first] = 1;
                    bfsqu.push(node_pair[i].first);
                }
            }
        }
        if(flag)
            level = -1;
        cout <<"Case "<< NN <<": "<< level << endl;
    }
    return 0;
}
