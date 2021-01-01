// 
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>
#include <algorithm>

#define INF 2147483647

#define MAX 10005

using namespace std;

void print_board(unsigned int arr[],unsigned int n)
{
    for(unsigned int i = 0;i <= n;i++)
        cout << arr[i] << " ";
    cout << endl;
    return;
}

int main()
{
    unsigned int arr[MAX], i = 0;
    while(cin >> arr[i])
    {
        sort(arr, arr + i + 1);
        //print_board(arr, i);

        if(!(i % 2))
            cout << arr[int(i / 2)] << endl;
        else
            cout << int((arr[int(i / 2)] + arr[int((i / 2) + 1)]) / 2) << endl;

        i++;
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

