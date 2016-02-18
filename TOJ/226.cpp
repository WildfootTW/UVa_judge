#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int cmp(int a, int b)
{
    if(a > b)
        return 1;
    return 0;
}

int main()
{
    int T,arr[MAX];
    bool flag_0 = 0,flag_3x = 0;
    cin >> T;
    string s;
    getline(cin ,s);
    while( T-- )
    {
        int total = 0;
        //cout << T << endl;
        getline(cin,s);
        //* 
        for(int i = 0;i < s.length();i++)
        {
            arr[i] = s[i] - '0';
            //s[i] = s[i] - '0';
            total += arr[i];
            if(!arr[i])
                flag_0 = 1;
        }
        if(!(total % 3))
            flag_3x = 1;
        //*/
        //cout << endl << "flag_0 = " << flag_0 << endl;
        //cout << endl << "flag_3x = " << flag_3x << endl;
        if(flag_0 && flag_3x)
        {
            sort(arr,arr + s.length(),cmp);
            //* 
            for(int i = 0;i < s.length();i++)
            {
                cout << arr[i];
            }
            //*/
            cout << endl;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}
