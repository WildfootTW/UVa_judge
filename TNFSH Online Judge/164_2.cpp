/*
 *      failed
 *
 *                      by Wildfoot
 */
//#include "special.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#define MAXN 1048576
//int main()
//{
//    int K = Init();//K=2;
//    int s[] = {0,1,3,2};//2^K個
//    Answer(s);
//    return 0;
//}

using namespace std;

vector<int> Vec[MAXN];
bool visit[MAXN];
int MAX;

//if (11101 ^ 11111) = (00010) return 1
bool check(int a, int b)
{
    int c = a ^ b;

    do 
    {
        if(c == 1) 
            return 1;
        if(c % 2 == 1)
            return 0;
    }
    while(c /= 2);

    return 0;
}

void build_graph(int max)
{
    for(int i = 0;i < max;i++)
        for(int j = i + 1;j < max;j++)
            if(check(i, j))
            {
                Vec[i].push_back(j);
                Vec[j].push_back(i);
            }
}

void print_graph(int max)
{
    for(int i = 0;i < max;i++)
    {
        cout << "\"" << i << "\" ";
        for(int e:Vec[i])
            cout << e << " ";
        cout << endl;
    }
}


bool backtrack(int *s, int n)
{
    if(n == MAX) 
    {
        if(check(s[0], s[n - 1]))
        {
            return 1;
        }
        return 0;
    }
    
    int previous = s[n - 1];

    for(int e:Vec[previous])
    {
        if(!visit[e])
        {
            visit[e] = true;
            s[n] = e;
            if(backtrack(s, n + 1))
                return 1;
            else
                visit[e] = false;
            
        }
    }
    return 0;
}

int main(        )
{
    int k = 5;
//    int k = Init();
    int max = pow(2, k);
    MAX = max;
    int s[ MAXN ];

    build_graph(max);
    //print_graph(max);
    memset(visit, 0, sizeof(visit));
    visit[0] = true;
    s[0] = 0;

    backtrack(s, 1);

//    Answer(s);
    for(int i = 0;i < max;i++)
        cout << s[i] << " ";
    cout << endl;
    return 0;
}
