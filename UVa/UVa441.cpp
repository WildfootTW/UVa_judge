// backtracking
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

#define MAX 13

static int arr[MAX], ans[6], k;

void backtrack(int remain_num, int ptr)
{
    if(!remain_num)
    {
        for(int i = 0;i < 6;i++)
        {
            cout << ans[i];
            if(i != 5)
                cout << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 0;i <= k - remain_num - ptr;i++)
    {
        //cout << "remain : " << remain_num;
        //cout << " ptr : " << ptr;
        //cout << " k-remain-ptr = " << k - remain_num - ptr << endl;
        ans[6 - remain_num] = arr[ptr + i];
        backtrack(remain_num - 1, ptr + i + 1);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Case = 0;
    while(cin >> k && k)
    {
        if(Case++) 
			cout << endl;
        for(int i = 0;i < k;i++)
        {
            cin >> arr[i];
        }
        backtrack(6, 0);
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

