// build table(dp)
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

#define MAX 10001

static int table[MAX];

void build_table()
{
    for(int i = 1;i < MAX;i++)
        table[i] = i;
    for(int i = 0;i * i <= MAX;i++)
        table[i * i] = 1;
    for(int i = 2;i < MAX;i++)
    {
        for(int j = 1;j <= i / 2;j++)
        {
            table[i] = min(table[i], table[j] + table[i - j]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    build_table();

    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        cout << table[N] << endl;
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

