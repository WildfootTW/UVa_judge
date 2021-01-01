#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Cat
{
    string name,identity;
    int age;
};

bool cmp_identity(string a, string b)
{
    int ss[2];
    string s[2] = {"a","b"};
    for(int i = 0;i < 2;i++)
    {
        switch(s[i])
        {                  
            case "elder":
                ss[i] = 1;
                break;           
            case "nursy":
                ss[i] = 2;
                break;           
            case "kit":
                ss[i] = 3;
                break;           
            case "warrior":
                ss[i] = 4;
                break;           
            case "appentice":
                ss[i] = 5;
                break;           
            case "medicent":
                ss[i] = 6;
                break;           
            case "deputy":
                ss[i] = 7;
                break;
            case "leader":
                ss[i] = 8;
                break;
        }
    }
    if(ss[0] < ss[1])
        return true;
    else
        return false;
}
bool name_cmp(string a,string b)
{
    for(int i = 0;i < a.size() && i < b.size();i++)
    {
        if(a[i] > b[i])
            return true;
        else if(a[i] < b[i])
            return false;
    }
}
bool age_cmp(int a,int b)
{
    if(a > b)
        return true;
    else
        return false;
}
int main()
{
    int n,m;
    cin >> n >> m;
    Cat cats[n];
    while(int i = 0;i < n;i++)
    {
        cin >> cats[i].name >> cats[i].identity >> cats[i].age;
    }
    

}
