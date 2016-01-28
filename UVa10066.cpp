#include <iostream>

using namespace std;

int main()
{
    int k = 0;
    while(1)
    {
        int n,m,ans = 0;
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        
        //if(k)
        //    cout << endl;
        k++;

        int arr[n + 1],brr[m + 1],LCS[n + 1][m + 1];
        for(int i = 1;i <= n;i++)
        {
            cin >> arr[i];
        }
        for(int i = 1;i <= m;i++)
        {
            cin >> brr[i];
        }
        for(int i = 0;i <= n;i++)
        {
            for(int j = 0;j <= m;j++)
            {
                LCS[i][j] = 0;
            }
        } 
        /*
        for(int j = 0;j <= n;j++)
        {
            for(int i = 0;i <= m;i++)
            {
                cout << LCS[i][j] << " " ;
            }
            cout << endl;
        } 
        */

        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(arr[i] == brr[j])
                {
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                }
                else if(LCS[i - 1][j] > LCS[i][j - 1])
                    LCS[i][j] = LCS[i - 1][j];
                else
                {
                    LCS[i][j] = LCS[i][j - 1];                
                }
            }
        }

        /*
        for(int i = 1;i <= n;i++)
        {
            if(ans < LCS[i][m])
                ans = LCS[i][m];
        }
        */
        cout << "Twin Towers #" << k << endl;
        cout <<"Number of Tiles : "<< LCS[n][m] << endl << endl;
        /*
        for(int j = 0;j <= n;j++)
        {
            for(int i = 0;i <= m;i++)
            {
                cout << LCS[i][j] << " " ;
            }
            cout << endl;
        } 
        */
    }
    return 0;
}

