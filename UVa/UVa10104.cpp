// 
// WildfootW 2018
// https://github.com/Wildfoot
// Wrong Answer

#include <iostream>
#include <ctime>

#define INF 2147483647

using namespace std;

int exGCD(int a, int b, int &X, int &Y)
{
    if(!b)
    {
        X = 1; Y = 0; 
        return a;
    }
    else
    {
        int ret = exGCD(b, a % b, X, Y);
        swap(X, Y);
        Y = Y - (a / b) * X;
        return ret;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, x, y;
    while(cin >> a >> b)
    {
        int ans = exGCD(a, b, x, y);
        cout << x << " " << y << " " << ans << endl;
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

