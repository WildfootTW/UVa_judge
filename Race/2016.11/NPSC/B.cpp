#include <iostream>
#include <cstring>
#include <stack>
#include <set>

using namespace std;

//bool visit[9000][9000];
set<int> visit[90001];

int rangeN, rangeM;
stack<int> ANS;

inline bool check_legitimate(int n, int m)
{
    if(n < 1 || m < 1 || n > rangeN || m > rangeM)
        return false;
    return true;
}

bool backtracking(int n, int m)
{
    //cout << n << " " << m << " ";
    if(visit[n].find(m) != visit[n].end())
        return false;
    visit[n].insert(m);
    //if(visit[n][m])
    //    return false;
    //visit[n][m] = true;
    if(check_legitimate(n - 2, m + 1))      // 1
    {
        //cout << 1;
        ANS.push(1);
        if(n - 2 == rangeN && m + 1 == rangeM)
        {
            return true;
        }
        else
        {
            if(backtracking(n - 2, m + 1))
                return true;
            ANS.pop();
        }
    }
    if(check_legitimate(n - 1, m + 2))      // 2
    {
        //cout << 2;
        ANS.push(2);
        if(n - 1 == rangeN && m + 2 == rangeM)
        {
            return true;
        }
        else
        {
            if(backtracking(n - 1, m + 2))
                return true;
            ANS.pop();
        }
    }
    if(check_legitimate(n + 1, m + 2))      // 3
    {
        //cout << 3;
        ANS.push(3);
        if(n + 1 == rangeN && m + 2 == rangeM)
        {
            return true;
        }
        else
        {
            if(backtracking(n + 1, m + 2))
                return true;
            ANS.pop();
        }
    }
    if(check_legitimate(n + 2, m + 1))      // 4
    {
        //cout << 4;
        ANS.push(4);
        if(n + 2 == rangeN && m + 1 == rangeM)
        {
            return true;
        }
        else
        {
            if(backtracking(n + 2, m + 1))
                return true;
            ANS.pop();
        }
    }
    if(check_legitimate(n + 2, m - 1))      // 5
    {
        //cout << 5;
        ANS.push(5);
        if(n + 2 == rangeN && m - 1 == rangeM)
        {
            return true;
        }
        else
        {
            if(backtracking(n + 2, m - 1))
                return true;
            ANS.pop();
        }
    }
    if(check_legitimate(n + 1, m - 2))      // 6
    {
        //cout << 6;
        ANS.push(6);
        if(n + 1 == rangeN && m - 2 == rangeM)
        {
            return true;
        }
        else
        {
            if(backtracking(n + 1, m - 2))
                return true;
            ANS.pop();
        }
    }
    if(check_legitimate(n - 1, m - 2))      // 7
    {
        //cout << 7;
        ANS.push(7);
        if(n - 1 == rangeN && m - 2 == rangeM)
        {
            return true;
        }
        else
        {
            if(backtracking(n - 1, m - 2))
                return true;
            ANS.pop();
        }
    }
    if(check_legitimate(n - 2, m - 1))      // 8
    {
        //cout << 8;
        ANS.push(8);
        if(n - 2 == rangeN && m - 1 == rangeM)
        {
            return true;
        }
        else
        {
            if(backtracking(n - 2, m - 1))
                return true;
            ANS.pop();
        }
    }
    //cout << endl;
    return false;
}

int main()
{
    cin >> rangeN >> rangeM;
    //memset(visit, 0, sizeof(visit));
    if(backtracking(1, 1))
    {
        cout << "YES" << endl;
        stack<int> Ansout;
        while(!ANS.empty())
        {
            Ansout.push(ANS.top());
            ANS.pop();
        }
        while(!Ansout.empty())
        {
            cout << Ansout.top();
            Ansout.pop();
        }
        cout << endl;
     
    }
    else
        cout << "NO" << endl;
    return 0;
}

