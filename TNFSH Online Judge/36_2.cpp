#include <iostream>

using namespace std;

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;
    long long FK = 1;

    if(!B)
    {
        cout << "1" << endl;
        goto END;
    }

    while(B != 1)
    {
        if(B % 2)
        {
            FK = FK * A % C;
            A = A * A % C;
            B = B / 2;
            
            //fun((A * A) % C, B / 2, C) * A % C;
        }
        else
        {
            //return fun((A * A) % C, B / 2, C);
            A = A * A % C;
            B = B / 2;
        }
    }
    A = A * FK % C;
    cout << A << endl;
    END:
    return 0;
}
