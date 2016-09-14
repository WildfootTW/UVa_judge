#include <iostream>

using namespace std;

int array[3][3];
bool flag[3];

inline void fun()
{
    if(array[0][0] == array[0][1] && array[0][1] == array[0][2]) 
        flag[array[0][0]] = 1;
    if(array[1][0] == array[1][1] && array[1][1] == array[1][2]) 
        flag[array[1][1]] = 1;
    if(array[2][0] == array[2][1] && array[2][1] == array[2][2]) 
        flag[array[2][2]] = 1;
    if(array[0][0] == array[1][0] && array[1][0] == array[2][0]) 
        flag[array[0][0]] = 1;
    if(array[0][1] == array[1][1] && array[1][1] == array[2][1]) 
        flag[array[1][1]] = 1;
    if(array[0][2] == array[1][2] && array[1][2] == array[2][2]) 
        flag[array[2][2]] = 1;
    if(array[0][0] == array[1][1] && array[1][1] == array[2][2]) 
        flag[array[1][1]] = 1;
    if(array[0][2] == array[1][1] && array[1][1] == array[2][0]) 
        flag[array[1][1]] = 1;
    return;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s[2];
        getline(cin, s[0]);
        getline(cin, s[0]);
        getline(cin, s[1]);
        flag[0] = 0;
        flag[1] = 0;
        flag[2] = 0;
        for(int i = 0;i < 3;i++)
            for(int j = 0;j < 3;j++)
                cin >> array[i][j];
        fun();
        
        if(flag[0] && flag[1])
            cout << "Impossible" << endl;
        else if(!flag[0] && !flag[1])
            cout << "Not yet" << endl;
        else if(flag[0])
            cout << s[1] << endl;
        else
            cout << s[0] << endl;
    }
    return 0;
}
