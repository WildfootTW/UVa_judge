#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(long long a,long long b)
{
    if(a < b)
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L,Q;
    cin >> L >> Q;
    long long arr[L];
    for(int i = 0;i < L;i++)
    {
        cin >> arr[i];
    }
    while(Q--)
    {
        int l,r,PTR = 1;
        long long Tarr[L],ans = 0;
        cin >> l >> r;
        l--;    r--;
        for(int i = l;i <= r;i++)
            Tarr[i] = arr[i];
        sort(Tarr + l,Tarr + r + 1,cmp);
        for(int i = l;i <= r;i++)
        {
            if(!(Tarr[i] == Tarr[i - 1]) && !(i == l))
                PTR++;
            //cout << Tarr[i] << " -> "<< PTR << endl;
            //Tarr[i] = PTR;
            
            ans += PTR;
        }
        cout << ans << endl;
    }
    return 0;
}
