#include <iostream>

using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s == "\0")
            break;
        long long total = 0;
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == ' ')
                total++;
        }
        cout << total + 1 << endl;
    }

    return 0;
}
