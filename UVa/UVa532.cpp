// 
// WildfootW 2018
// https://github.com/Wildfoot
// Wrong Answer

#include <iostream>
#include <ctime>

#define INF 2147483647
#define MAX 30

using namespace std;

bool cells[MAX][MAX][MAX];
//Levels Rows Columns
int Start_cell[3];
int End_cell[3];

void save_dungeon(int L, int R, int C)
{
    for(int i = 0;i < L;i++)
    {
        string s;
        getline(cin, s);
        for(int j = 0;j < R;j++)
        {
            getline(cin, s);
            for(int k = 0;k < C;k++)
            {
                switch(s[k])
                {
                    case '#':
                        cells[i][j][k] = false;
                        break;
                    case '.':
                        cells[i][j][k] = true;
                        break;
                    case 'S':
                        cells[i][j][k] = true;
                        Start_cell[0] = i;
                        Start_cell[1] = j;
                        Start_cell[2] = k;
                        break;
                    case 'E':
                        cells[i][j][k] = true;
                        End_cell[0] = i;
                        End_cell[1] = j;
                        End_cell[2] = k;
                        break;
                }
            }
        }
    }
    return;
}

void print_dungeon(int L, int R, int C)
{
    for(int i = 0;i < L;i++)
    {
        for(int j = 0;j < R;j++)
        {
            for(int k = 0;k < C;k++)
                cout << cells[i][j][k];
            cout << endl;
        }
        cout << endl;
    }
}

int solve_problem(int L, int R, int C)
{
    save_dungeon(L, R, C);
    print_dungeon(L, R, C);
    return -1;
}

int main()
{
    int level, row, column;
    while(cin >> level >> row >> column)
    {
        if(!level && !row && !column)
            break;

        int ans;
        ans = solve_problem(level, row, column);
        if(ans == -1)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << ans << " minute(s)." << endl;
    }

    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

