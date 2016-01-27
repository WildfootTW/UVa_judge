#include <iostream>

using namespace std;

int main()
{
    int k = 0;
    while(1)
    {
        k++;
        int n,m;
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;

        int arr[n + 1],brr[m + 1],LCS[n + 1][m + 1];
        //arr[0] = 0;
        //brr[0] = 0;
        for(int i = 1;i <= n;i++)
        {
            cin >> arr[i];
            //LCS[i][0] = 0;
        }
        for(int i = 1;i <= m;i++)
        {
            cin >> brr[i];
            //LCS[0][i] = 0;
        }
        //LCS[0][0] = 0;
        for(int i = 0;i <= n;i++)
        {
            for(int j = 0;j <= m;j++)
            {
                LCS[i][j] = 0;
            }
        } 
        /*for(int j = 0;j <= n;j++)
        {
            for(int i = 0;i <= m;i++)
            {
                cout << LCS[i][j] << " " ;
            }
            cout << endl;
        } */

        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(arr[i] == brr[j])
                {
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                }
                else
                {
                    LCS[i][j] = LCS[i][j - 1];                
                }
            }
        }
        cout << "Twin Towers #" << k << endl;
        cout <<"Number of Tiles : "<< LCS[n][m] << endl << endl;
        
    }
    return 0;
}

