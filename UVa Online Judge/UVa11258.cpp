/*  fail
 *      dp
 *      
 *                  by Wildfoot
 */
#include <iostream>
#include <cstring>
#define MAXINT 2147483647
#define MAXLEN 10

using namespace std;

string s;

long long dp[201][201];
bool visit[201][201];

long long s_to_int(int start, int length)
{
    long long ANS = 0;
    while(length--)
    {
        long long N = s[start] - '0';
        for(int i = 0;i < length;i++)
        {
            N *= 10;
        }
        start++;
        ANS += N;
    }
    return ANS;
}

long long fun(int n,int k)
{
//    cout << n << " " << k << " " << s_to_int(k, n) << endl;
    if(visit[n][k])
        return dp[n][k];
    visit[n][k] = true;
    if(n <= MAXLEN)
    {
        if(s_to_int(k, n) <= MAXINT)
            return dp[n][k] = s_to_int(k, n);
    }
    long long max_ans = 0;
    for(int i = 1;i <= MAXLEN;i++)
    {
        if(n - i == 0)
            break;
        long long T = fun(n - i, 0) + fun(i, n - i);
        max_ans = max(max_ans, T);
    }
    return dp[n][k] = max_ans;
}

int main()
{
    int t;
    cin >> t;
    
    getline(cin, s);

    while(t--)
    {
        memset(visit, 0, sizeof(visit));
        getline(cin, s);
        int n = s.length();
        //cout << n << " " << s << endl;
        cout << fun(n, 0) << endl;
    }
    return 0;
}
