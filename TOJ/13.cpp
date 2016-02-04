#include <iostream>
#define INF 2147483647
//#define MAX 100000    //MAX10000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V;
    while(cin >> V)
    {
        long long ans = 0;
        int n;
        cin >> n;
        long long item[n][2], dp[V + 1];
        for(int i = 0;i < n;i++)
            for(int j = 0;j < 2;j++)
                cin >> item[i][j];
        
        for(int i = 0;i <= V;i++)   dp[i] = -INF;
        dp[0] = 0;
        dp[item[0][0]] = item[0][1]; 

        for(int i = 0;i < n;i++)
        {

            //int temp = V / item[i][0];
            //cout << "V = " << V << " item[i][0] = " << item[i][0] << endl;
            //cout << "temp[" << i <<"] = " << temp << endl;
            //for(int k = 0;k < temp;k++)
            //{
                for(int j = 0;j <= V;j++)
                {
                    if(!(j < item[i][0]))
                    {
                        if(dp[j] < dp[j - item[i][0]] + item[i][1])
                            dp[j] = dp[j - item[i][0]] + item[i][1];
                    }
                }
                //for(int j = 0;j <= V;j++)
                //{
                //    swap(dp[1][j],dp[0][j]);
                //}
            //}
        }
        for(int i = 0;i <= V;i++)
            if(ans < dp[i])
                ans = dp[i];

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
