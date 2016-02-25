#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct cat
{
    string n,w;
    int indexi,y;
};
cat c[10010];
bool cmp(cat a,cat b)
{
    if(a.indexi < b.indexi)
        return true;
    else if(a.indexi > b.indexi)
        return false;
    else
    {
        if(a.indexi != 5)
        {
            if(a.y > b.y)   
                return true;
            else if(a.y < b.y)
                return false;
            else
                if(a.n < b.n)
                    return true;
                else
                    return false;
        }
        else
        {
            if(a.y < b.y)
                return true;
            else if(a.y > b.y)
                return false;
            else
                if(a.n < b.n)
                    return true;
                else
                    return false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);  
    int n, m;
    while(cin >> n >> m)
    {
        for(int i = 0;i < n;i++)
        {
            cin >> c[i].n >> c[i].w >> c[i].y;
            if(c[i].w == "elder")           c[i].indexi = 1;
            else if(c[i].w == "nursy")      c[i].indexi = 2;
            else if(c[i].w == "kit")        c[i].indexi = 3;
            else if(c[i].w == "warrior")    c[i].indexi = 4;
            else if(c[i].w == "appentice")  c[i].indexi = 5;
            else if(c[i].w == "medicent")   c[i].indexi = 6;
            else if(c[i].w == "deputy")     c[i].indexi = 7;
            else
                c[i].indexi=8;
        }
        sort(c,c + n,cmp);
        if(n < m)
            m = n;
        for(int i = 0;i < m;i++)
            cout << c[i].n << '\n';
    }
    return 0;
}
