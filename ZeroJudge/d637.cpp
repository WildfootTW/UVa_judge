#include <iostream>
#define INF 2147483647

using namespace std;

int main()
{
    int keyin[10001][2],dp[10001][101] = {0}, n, ans = 0;  //dp[i][j]=前面i個物品湊出剛好重量為j的價值為多少
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            cin >> keyin[i][j];
        }
    } 
    

    //初始值  
    //X  0 1 2 3 4 5 6 7 8 //重量
    //___________________                            V     W
    //0  0 - - 2 - - - - -   //初始第一個物品        2     3
    //1  0 - 3 2 - 5 - - -                           3     2
    //2  0 1 3 4 3 5 6 - -                           1     1
    //3  0 1 3 4 8 9 11 12 11                        8     4
    //前面幾個物品
    
    for(int i = 1;i <= 100;i++)   dp[1][i] = -INF;
    dp[1][0] = 0;
    dp[1][keyin[1][0]] = keyin[1][1]; 

    for(int i = 2;i <= n;i++)
    {   
        for(int j = 0;j <= 100;j++)
        {
            if(j < keyin[i][0])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i - 1][j - keyin[i][0]] + keyin[i][1];
                if(dp[i][j] < dp[i - 1][j])
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int i = 0;i <= 100;i++)
        if(ans < dp[n][i])
            ans = dp[n][i];

/* debug
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= 100;j++)
        {
            if(dp[i][j] < 0)
                cout << "- ";
            else
                cout << dp[i][j] << " ";
        }
        cout << endl;
    }
*/
    
    cout << ans << endl;
    return 0;
}
