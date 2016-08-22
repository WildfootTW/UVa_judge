/*
 *  dp
 *  窮舉最後一段
 *              by Wildfoot
 */
#include <iostream>
#include <cstring>
#define MAX 50

using namespace std;

int m;
long long dp[MAX + 1][MAX + 1];
bool visit[MAX + 1][MAX + 1];

long long BC(int n,int k)
{
    if(n < 0 || k < 0)
        return 0;
    if(visit[n][k])
        return dp[n][k];
    visit[n][k] = true;
    //cout << n << " " << k << " " << m << endl;
    if(k * m < n)
        return dp[n][k] = 0;
    if(k > n)
        return dp[n][k] = 0;
    if(n == 1 || k == 1)  
    {    
        return dp[n][k] = 1;
    }
    else
    {
        long long sum = 0;
        //窮舉最後一個顏色的大小 (大小從1~m) 
        for(int i = 1;i <= m;i++)
            sum += BC(n - i, k - 1);  
        return dp[n][k] = sum;
    }
    return dp[n][k] = -1;
}

int main()
{
    int n, k;
    while(cin >> n >> k >> m)
    {
        memset(visit, false, sizeof(visit));
        cout << BC(n, k) << endl;
    }
    return 0;
}
