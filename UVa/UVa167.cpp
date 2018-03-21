// backtrack
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>
#include <cstring>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

static int board[8][8], conflict[8][8];
//if the queen on row 0, then the portion which will threaten by the queen will mark(in conflict array) with "0"
static int maximun_ans;

inline void initial()
{
    maximun_ans = 0;
    memset(conflict, -1, sizeof(conflict));
    return;
}

void fill_conflict(int row, int column)
{
    for(int i = row + 1, j = column + 1;i < 8, j < 8;i++, j++)
        if(conflict[i][j] == -1)
            conflict[i][j] = row;

    for(int i = row + 1; i < 8;i++)
        if(conflict[i][column] == -1)
            conflict[i][column] = row;

     for(int i = row + 1, j = column - 1;i < 8, j >= 0;i++, j--)
        if(conflict[i][j] == -1)
            conflict[i][j] = row;

     return;
}

void erase_conflict(int row)
{
    for(int i = row + 1;i < 8;i++)
    {
        for(int j = 0;j < 8;j++)
            if(conflict[i][j] == row)
                conflict[i][j] = -1;
    }
    return;
}
void solve_problem(int row, int sum)
{
    for(int i = 0;i < 8;i++)
    {
        if(conflict[row][i] == -1)
        {
            if(row == 7)
            {
                maximun_ans = max(maximun_ans, sum + board[row][i]);
                return;
            }
            fill_conflict(row, i);
            solve_problem(row + 1, sum + board[row][i]);
            erase_conflict(row);
        }
    }
    return;
}
inline void print_justified()
{
    string s = to_string(maximun_ans);
    for(int j = 0;j < 5 - s.length();j++)
        cout << " ";
    cout << maximun_ans << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--)
    {
        for(int i = 0;i < 8;i++)
            for(int j = 0;j < 8;j++)
                cin >> board[i][j];
        initial();
        solve_problem(0, 0);
        print_justified();
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

