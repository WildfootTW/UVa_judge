#include <iostream>

#define MAXN 101
using namespace std;
// O(n^4)
int main()
{

        int n = 0;
        //prefix 
        //1 2 3 4 5   ->    1 3 6 10 15
        //prefix_ex
        //1 2 3 4 5         1 3 6 10 15
        //2 3 4 5 6   ->    3 8 15 24 35  //左上角到點的面積
        //3 4 5 6 7         6 15 27 42 60
    while(cin >> n)
    {
        int in[MAXN][MAXN] = {0}; 
        for(int i = 1;i <= n;i++)
        {
            int temp = 0;
            for(int j = 1;j <= n;j++)
            {
                cin >> in[i][j];
                temp = temp + in[i][j];
                in[i][j] = temp;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            int temp = 0;
            for(int j = 1;j <= n;j++)
            {
                temp = temp + in[j][i];
                in[j][i] = temp;
            }
        }
        

        /*
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                cout << in[i][j] << " ";
            }
            cout << endl;
        }
        //*/

        int ans = -2147483647,Tans = 0;

        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                for(int k = 1;k <= i;k++)
                {
                    for(int f = 1;f <= j;f++)
                    {
                        Tans = in[i][j] + in[k - 1][f - 1];
                        Tans = Tans - in[i][f - 1];
                        Tans = Tans - in[k - 1][j];
                        if(Tans > ans)
                            ans = Tans;
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
