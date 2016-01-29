#include <iostream>
#define sum 500000
using namespace std;
int total;
void swapx(long long &a,long long &b)
{
    long long temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(!n)
            break;

        total = 0;
        long long arr[n];
        for(int i = 0;i < n;i++)
        {
            cin >> arr[i];
        }
        for(int i = 0;i < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                if(arr[i] > arr[j])
                {
                    swapx(arr[i],arr[j]);
                    total++;
                }
            }
        }
        cout << total << endl;
    }
    return 0;
}
