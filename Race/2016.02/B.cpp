#include <iostream>

using namespace std;

int main()
{
    string L;
    int n = 0;
    getline(cin, L);
    if(L.size() > 9)
    {
        n = L.size() - 9;
        n = n / 2;
        n = n + 9;
    }
    else
        n = L.size();
    cout << n;
}
