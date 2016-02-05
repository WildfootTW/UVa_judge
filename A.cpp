#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string L,S;
    bool flag = 0;
    getline(cin,L);
    getline(cin,S);
    for(int i = 0;i < L.size();i++)
    {
        flag = 0;
        for(int j = 0;j < S.size();j++)
        {
            if(L[i] == ' ')
            {
                flag = 1;
                break;
            }
            if(L[i] == S[j])
            {
                flag = 1;
                S[j] = 'z';
                break;
            }
        }
        if(flag)
            cout << L[i];
        else
            break;
    }
    cout << endl;
    return 0;
}
