/*
 *      failed
 *
 *                  Wildfoot
 */
//#include "special.h"
#include <iostream>
#include <cmath>
#include <queue>
#define MAXN 1048576
//int main()
//{
//    int K = Init();//K=2;
//    int s[] = {0,1,3,2};//2^K個
//    Answer(s);
//    return 0;
//}

using namespace std;

queue<int> Qu;

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

bool fun(int *s, int n)
{
    int T = Qu.size();

    if(!T)
    {
        if(check(s[n], s[0])) 
            return 1;
        else
            return 0;
    }

    while(T--)
    { 
        int e = Qu.front();
        Qu.pop(); 
        if(check(e, s[n])) 
        {
            s[n + 1] = e;
            if(fun(s, n + 1))
                return 1;
        }
        Qu.push(e);
    }
    return 0;
}

int main(        )
{
    int k = 7;
//    int k = Init();
    int max = pow(2, k);
    int s[ MAXN ];
    for(int i = 1;i < max;i++)
        Qu.push(i);

    s[0] = 0;
    fun(s, 0);
//    Answer(s);
    for(int i = 0;i < max;i++)
        cout << s[i] << " ";
    cout << endl;
    return 0;
}
