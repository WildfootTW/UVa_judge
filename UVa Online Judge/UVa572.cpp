// 
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>

#define INF 2147483647
#define MAX 100

using namespace std;

typedef struct var_plot
{
    bool used;
    bool oil;
} plot;

plot plots[MAX][MAX];
int m, n;


void fill_up_grid()
{
    string s;
    getline(cin, s);
    for(int i = 0;i < m;i++)
    {
        getline(cin, s);
        for(int j = 0;j < n;j++)
        {
            plots[i][j].used = false;
            if(s[j] == '*')
                plots[i][j].oil = false;
            else
                plots[i][j].oil = true;
        }
    }
    return;
}

void DFS(int row, int column)
{
    for(int i = 0;i < 8;i++)
    {
        int new_row, new_column;
        switch(i)
        {
            case 0:
                new_row = row; new_column = column + 1;
                break;
            case 1:
                new_row = row + 1; new_column = column + 1;
                break;
            case 2:
                new_row = row - 1; new_column = column + 1;
                break;
            case 3:
                new_row = row; new_column = column - 1;
                break;
            case 4:
                new_row = row + 1; new_column = column - 1;
                break;
            case 5:
                new_row = row - 1; new_column = column - 1;
                break;
            case 6:
                new_row = row + 1; new_column = column;
                break;
            case 7:
                new_row = row - 1; new_column = column;
                break;
        }
        if(new_row >= 0 && new_column >= 0 && new_row < m && new_column < n)
            if(!plots[new_row][new_column].used && plots[new_row][new_column].oil)
            {
                plots[new_row][new_column].used = true;
                DFS(new_row, new_column);
            }
    }
    return;
}

int solve_problem()
{
    fill_up_grid();
    int total = 0;
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(!plots[i][j].used && plots[i][j].oil)
            {
                total++;
                DFS(i, j);
            }
        }
    }
    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    while(cin >> m >> n)
    {
        if(!m)
            break;
        cout << solve_problem() << endl;
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

