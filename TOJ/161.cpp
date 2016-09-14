#include <iostream>
#define INF 2147483647
using namespace std;


int M, A[10000001];

int K(int n, int p)
{
    int k = n / p;
    double w = double(n) / double(p);
    //cout << n << " / " << p << " = " << w << endl;
    //cout << (k + 1) - w << " " << (w - k) << endl;
    //if(w - k >= 0.5)
        //return k + 1;
    return k;
}

long long fun(int n)
{
    if(A[n] != INF)
        return A[n];
    return A[n] = ((fun(K(n, 2)) + fun(K(n, 3)) + fun(K(n, 4))) * fun(K(n, 5))) % M;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> A[0] >> A[1] >> M >> n;
        for(int i = 2;i <= n;i++)
            A[i] = INF;
        cout << fun(n) << endl;

//        for(int i = 0;i <= n;i++)
//            cout << A[i] << " ";
//        cout << endl;
    }
    return 0;
}
