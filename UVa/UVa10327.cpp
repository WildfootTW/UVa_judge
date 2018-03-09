//Accepted
//bubble sort
#include <iostream>
#include <utility>
#define MAX 1005

using namespace std;

int Flip_Sort(int N)
{
    int arr[MAX], num = 0;
    for(int i = 0;i < N;i++)
        cin >> arr[i];

    for(int i = 0;i < N - 1;i++)
    {
        for(int j = 0;j < N - 1 - i;j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                num++;
            }
        }
    }

//    for(int i = 0;i < N;i++)
//        cout << arr[i] << " ";
//    cout << endl;

    return num;
}

int main()
{
    int n;
    while(cin >> n)
    {
        cout << "Minimum exchange operations : " << Flip_Sort(n) << endl;
    }
    return 0;   
}

