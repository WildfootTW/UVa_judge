// DP
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>
#include <cstring>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

#define MAX 10000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //5 types of coins: 50-cent, 25-cent, 10-cent, 5-cent, 1-cent
    
    int n, dp[MAX];
    int coin_type[5] = {1, 5, 10, 25, 50};
    while(cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int value:coin_type)
        {
            for(int i = value;i <= n;i++)
            {
                dp[i] += dp[i - value];
            }

            //for(int i = 0;i <= n;i++)
            //{
            //    cout << dp[i] << " ";
            //}
            //cout << endl;
        }
        cout << dp[n] << endl;
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

