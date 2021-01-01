#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, K;
        cin >> n >> K;
        int arr[n];
        for(int i = 0;i < n;i++)
        {
            cin >> arr[i]; 
            if(arr[i] < 0)
                arr[i] = -arr[i];
        }

        bool dp[n][K];
        memset(dp, 0, sizeof(dp));
        dp[0][ arr[0] % K ] = true;
        for(int i = 1;i < n;i++)
        {
            for(int j = 0;j < K;j++)
            {
                if(dp[i - 1][j])
                {
                    dp[i][(j + arr[i]) % K ] = true;
                    dp[i][((j - arr[i] % K) + K) % K] = true;
                }
            }
        }
        
        /*
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < K;j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        */

        if(dp[n - 1][0])
            cout << "Divisible" << endl;
        else
            cout << "Not divisible" << endl;
    }
    return 0;
}
