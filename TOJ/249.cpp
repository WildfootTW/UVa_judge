#include <iostream>
#define maxn 500000

using namespace std;

int main()
{
    int arr[maxn],sum = 0,n,ans = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> arr[i];
    }

    for(int i = 0;i < n;i++)
    {
        if(sum + arr[i] > 0)
        {
            sum = sum + arr[i];
            if(sum > ans)
            {
                ans = sum;
            }
        }
        else
        {
            sum = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
