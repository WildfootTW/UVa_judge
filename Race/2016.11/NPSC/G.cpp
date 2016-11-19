#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> V[15];
int nodeN;
bool node[15];
bool ans[15];

void change_node(int n)
{
    static int count = 0;    
    count++;
    for(int i = 0;i < nodeN;i++)
    {
        int fix = pow(2, i);
        node[i] = count & fix;
    }
    for(int i = 0;i < nodeN;i++)
        cout << node[i] << " ";
    cout << endl;
}

bool check()
{
    for(int i = 0;i < nodeN;i++)
    {
        if(node[i])         //1 is deleted
            continue;
        else
        {
            for(int e:V[i])
            {
                if(node[e] == false)
                    return false;
            }
        }
    }
    cout << "****" << endl;
    return true;
}


int main()
{
    int edgeN, MIN = 2147483647;
    cin >> nodeN >> edgeN;
    for(int i = 0;i < edgeN;i++)
    {
        int a, b;
        cin >> a >> b;
        V[a - 1].push_back(b - 1);
        V[b - 1].push_back(a - 1);
    }
    for(int i = 0;i < pow(2, nodeN);i++)
    {
        change_node(nodeN);
        if(check())
        {
            int tempcount = 0;
            for(int j = 0;j < nodeN;j++)
            {
                if(node[j] == true)
                    tempcount++;
            }
            if(tempcount < MIN)
            {
                MIN = tempcount;
                for(int j = 0;j < nodeN;j++)
                {
                    ans[j] = node[j];
                }
            }
            if(tempcount == MIN)
            {
                bool flag = 0;
                for(int j = 0;j < nodeN;j++)
                {
                    if(ans[j] < node[j])
                    {
                        flag = true;
                        break;
                    }
                    if(ans[j] > node[j])
                        break;
                }
                if(flag)
                    for(int j = 0;j < nodeN;j++)
                    {
                        ans[j] = node[j];
                    }
            }
        }
    }
    cout << MIN << endl;
    for(int i = 0;i < nodeN;i++)
    {
        if(ans[i])
            cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}
