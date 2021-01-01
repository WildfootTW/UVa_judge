// Sort
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>
#include <algorithm>

#define INF 2147483647
#define MAX 1001

using namespace std;

typedef struct var_job
{
    int days, index, fine;
} job;

job jobs[MAX];

bool cmp(job a, job b)
{
    return a.fine * b.days > b.fine * a.days;
}

void solve_problem(int m)
{
    for(int i = 0;i < m;i++)
    {
        cin >> jobs[i].days >> jobs[i].fine;
        jobs[i].index = i + 1;
    }
    sort(jobs, jobs + m, cmp);
    for(int i = 0;i < m;i++)
    {
        cout << jobs[i].index;
        if(!(i == m - 1))
            cout << " ";
    }
    cout << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    while(n--)
    {
        cin >> m;
        solve_problem(m);
        if(n)
            cout << endl;
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

