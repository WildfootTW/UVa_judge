#include <iostream>

using namespace std;

int main()
{
    int keyin = 0,sum = 0,n,ans = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {

        cin >> keyin;
        if(sum + keyin > 0)
        {
            sum = sum + keyin;
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
