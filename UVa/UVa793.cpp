// C++
// WildfootW 2018
// https://github.com/Wildfoot
// disjoint set
// Accepted

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define MAX 100000

int father[MAX];
int find(int n)
{
    if(father[n] == n)return n;
    father[n] = find(father[n]); //優化father[n] -> 最後的father
    return father[n];
}

int U(int a,int b)//融合兩個圖
{
    //優化：將小的接到大的 O(alpha(n))  約等於  O(1)
    //記路圖大小
    father[find(a)] = find(b);
}

void solve_function()
{
    int n, successfully = 0, unsuccessfully = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
        father[i] = i;
    string s;
    getline(cin, s);
    while(getline(cin, s) && !s.empty())
    {
        char op;
        int a, b;
        stringstream ss;
        ss << s;
        ss >> op >> a >> b;
        a--;
        b--;
        if(op == 'c')
        {
            U(a, b);
        }
        if(op == 'q')
        {
            if(find(a) == find(b))
                successfully++;
            else
                unsuccessfully++;
        }
    }
    cout << successfully << "," << unsuccessfully << endl;
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        solve_function();
        if(n)
            cout << endl;
    }
    return 0;   
}

