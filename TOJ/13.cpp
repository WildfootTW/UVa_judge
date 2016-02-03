#include <iostream>
#define INF 2147483647
//#define MAX 100000    //MAX10000000

using namespace std;

int main()
{

    int V;
    while(cin >> V)
    {
        int ans = 0, n;
        cin >> n;
        int item[n][2], dp[2][V + 1];
        for(int i = 0;i < n;i++)
            for(int j = 0;j < 2;j++)
                cin >> item[i][j];
        
        for(int i = 0;i <= V;i++)   dp[0][i] = -INF;
        dp[0][0] = 0;
        dp[0][item[0][0]] = item[0][1]; 

        for(int i = 0;i < n;i++)
        {

            int temp = V / item[i][0];
            //cout << "V = " << V << " item[i][0] = " << item[i][0] << endl;
            //cout << "temp[" << i <<"] = " << temp << endl;
            for(int k = 0;k < temp;k++)
            {
                for(int j = 0;j <= V;j++)
                {
                    if(j < item[i][0])
                        dp[1][j] = dp[0][j];
                    else
                    {
                        dp[1][j] = dp[0][j - item[i][0]] + item[i][1];
                        if(dp[1][j] < dp[0][j])
                            dp[1][j] = dp[0][j];
                    }
                }
                for(int j = 0;j <= V;j++)
                {
                    swap(dp[1][j],dp[0][j]);
                }
            }
        }
        for(int i = 0;i <= V;i++)
            if(ans < dp[0][i])
                ans = dp[0][i];

        /*
        cout << "count = " << count << endl;    
        for(int i = 0;i <= count;i++)
        {
            for(int j = 0;j <= V;j++)
            {
                if(dp[i][j] < 0)
                    cout << "- ";
                else
                    cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        //*/
        cout << ans << endl;
    }
    return 0;
}
