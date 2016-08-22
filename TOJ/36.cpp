#include <iostream>

using namespace std;

long long fun(long long A,long long B,long long C)
{
    if(B == 1)
        return A % C;
    if(B % 2)
        return fun((A * A) % C, B / 2, C) * A % C;
    else
        return fun((A * A) % C, B / 2, C);
}

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;
    if(B == 0)
        cout << "1" << endl;
    else
        cout << fun(A, B, C) << endl;
    return 0;
}
