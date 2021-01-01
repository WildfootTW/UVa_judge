#include <iostream>
#include <vector>
using namespace std;
bool used[100001],flag = 1;//lone
vector<int> V[100001];
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
    {
        used[i] = 0;
    }
    flag = 1;
}
void DFS(int n,int last)
{
    used[n] = true;
    for(int e:V[n])
    {
        if(!used[e])
        {
            DFS(e,n);
        }
        else
        {
            //cout << "last " << last << " e " << e << endl;
            if(!(e == last))
                flag = 0;       //team
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
    while(Q--)
    {
        char q;
        cin >> q;
        if(q == 'L')    //link
        {
            int a,b;
            cin >> a >> b;
            bool flagL = 1;
            for(int e:V[a])
            {
                if(e == b)
                    flagL = 0;
            }
            if(a == b)
                flagL = 0;
            if(flagL)
            {
                V[a].push_back(b);
                V[b].push_back(a);
            }
        }
        else            //question
        {
            int a;
            cin >> a;
            DFS(a,-1);
            if(flag)
                cout << a << " is lone" << endl;
            else
                cout << a << " is team" << endl;
            initial_DFS(N);
        }
    }
    return 0;
}
