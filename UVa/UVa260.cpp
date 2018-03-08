// 
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted
// DFS

#include <iostream>
#include <ctime>
#include <cstring>

#define INF 2147483647
#define MAX 205

using namespace std;

bool board[MAX][MAX];
bool used[MAX][MAX];
int n;

void set_board()
{
    string s;
    getline(cin, s);
    for(int i = 0;i < n;i++)
    {
        getline(cin, s);
        for(int j = 0;j < n;j++)
            board[i][j] = (s[j] == 'b');
    }
    return;
}
void print_board()
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
            cout << used[i][j];
        cout << endl;
    }
}
bool DFS(int row, int column)
{
    if(row == (n - 1))
        return true;
    used[row][column] = true;
    int new_row, new_column;
    for(int i = 0;i < 6;i++)
    {
        switch(i)
        {
            case 0:
                new_row = row - 1; new_column = column - 1;
                break;
            case 1:
                new_row = row - 1; new_column = column;
                break;
            case 2:
                new_row = row; new_column = column - 1;
                break;
            case 3:
                new_row = row + 1; new_column = column + 1;
                break;
            case 4:
                new_row = row + 1; new_column = column;
                break;
            case 5:
                new_row = row; new_column = column + 1;
                break;
        }
        //&& operater left to right associativity
        if((new_row >= 0 && new_column >= 0 && new_row < n && new_column < n) && !used[new_row][new_column] && board[new_row][new_column])
        {
            if(DFS(new_row, new_column))
                return true;
        }
    }
    return false;
}
bool solve_problem()
{
    bool black_win = false;
    set_board();
    memset(used, false, sizeof(used));
    for(int column = 0;column < n;column++)
    {
        if(board[0][column])
            black_win = DFS(0, column);
        if(black_win)
            break;
    }
    return black_win;
}
int main()
{
    int i = 0;
    while(cin >> n)
    {
        if(!n)
            break;

        bool flag;
        flag = solve_problem();
        if(flag)
            cout << ++i << " B" << endl;
        else
            cout << ++i << " W" << endl;
    }


    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

