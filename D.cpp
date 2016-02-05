#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> V[10001];
stack<int> qu;
bool used[10001],flag = 1;
void initial(int n)
{
    for(int i = 0;i <= n;i++)
    {
        V[i].clear();
    }
}
void initial_DFS(int n)
{
    for(int i = 0;i <= n;i++)
        used[i] = 0;
    flag = 1;
    while(!qu.empty())
        qu.pop();
}
void DFS(int n,int b)
{
    if(flag)
        qu.push(n);
    if(n == b)
        flag = 0;
    //cout << n << " ";
    used[n] = 1;
    for(int e : V[n])
    {
        if(!used[e])
        {
            DFS(e,b);
            if(flag)
                qu.pop();
        }   
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,Q;
    cin >> N >> Q;
    initial(N);
    for(int i = 1;i < N;i++)
    {
        int a,b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    while(Q--)
    {
        int a,b,Num;
        bool gNum;
        cin >> a >> b;
        initial_DFS(N);
        DFS(a,b);
        gNum = qu.size() % 2; //1 -> 1  0 -> 2
        if(gNum)
            Num = qu.size() / 2;
        else
            Num = qu.size() / 2 - 1;
        while(Num--)
            qu.pop();
        if(gNum)
        {
            cout << qu.top() << endl;
        }
        else
        {
            int x, y;
            x = qu.top();
            qu.pop();
            y = qu.top();
            if(x > y)
                swap(x,y);
            cout << x << " " << y << endl;
        }
        
        /*
        cout << qu.size() << endl;
        while(!qu.empty())
        {
            cout << qu.top() << " | ";
            qu.pop();
        }
        */

    }
    return 0;
}
