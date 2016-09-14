/*
 *  GCD
 *  Accepted
 *          wildfoot
 */
#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if(!b)
        return a;
    return GCD(b, a % b);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int A, B;
        cin >> A >> B;
        cout << GCD(A, B) << endl;
    }
    return 0;
}
