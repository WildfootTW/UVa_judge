// DFS
// WildfootW 2018
// https://github.com/Wildfoot
// Time limit exceeded

#include <iostream>
#include <ctime>

#define INF 2147483647
#define MAX 30

using namespace std;

typedef struct var_cell
{
    bool is_empty;
    //bool used;
    int how_far;
} cell;

cell cells[MAX][MAX][MAX];
//Levels Rows Columns
int Start_cell[3];
int End_cell[3];
int MAX_LEVEL, MAX_ROW, MAX_COLUMN;

void save_dungeon()
{
    for(int i = 0;i < MAX_LEVEL;i++)
    {
        string s;
        getline(cin, s);
        for(int j = 0;j < MAX_ROW;j++)
        {
            getline(cin, s);
            for(int k = 0;k < MAX_COLUMN;k++)
            {
                switch(s[k])
                {
                    case '#':
                        cells[i][j][k].is_empty = false;
                        break;
                    case '.':
                        cells[i][j][k].is_empty = true;
                        cells[i][j][k].how_far = INF;
                        break;
                    case 'S':
                        cells[i][j][k].is_empty = true;
                        cells[i][j][k].how_far = 0;
                        Start_cell[0] = i;
                        Start_cell[1] = j;
                        Start_cell[2] = k;
                        break;
                    case 'E':
                        cells[i][j][k].is_empty = true;
                        cells[i][j][k].how_far = INF;
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

void print_dungeon()
{
    cout << "Start cell = " << Start_cell[0] << " " << Start_cell[1] << " " << Start_cell[2] << endl;
    cout << "End cell = " << End_cell[0] << " " << End_cell[1] << " " << End_cell[2] << endl;
    for(int i = 0;i < MAX_LEVEL;i++)
    {
        for(int j = 0;j < MAX_ROW;j++)
        {
            for(int k = 0;k < MAX_COLUMN;k++)
                if(cells[i][j][k].how_far == INF)
                    cout << "F";
                else if(!cells[i][j][k].is_empty)
                    cout << "#";
                else
                    cout << cells[i][j][k].how_far;
            cout << endl;
        }
        cout << endl;
    }
}

int DFS(int L, int R, int C)
{
    if(L == End_cell[0] && R == End_cell[1] && C == End_cell[2])
        return cells[L][R][C].how_far;

    int new_L, new_R, new_C;
    for(int i = 0;i < 6;i++)
    {
        switch(i)
        {
            case 0:
                new_L = L - 1; new_R = R; new_C = C;
                break;
            case 1:
                new_L = L; new_R = R - 1; new_C = C;
                break;
            case 2:
                new_L = L; new_R = R; new_C = C - 1;
                break;
            case 3:
                new_L = L + 1; new_R = R; new_C = C;
                break;
            case 4:
                new_L = L; new_R = R + 1; new_C = C;
                break;
            case 5:
                new_L = L; new_R = R; new_C = C + 1;
                break;
        }
        if(new_L >= 0 && new_R >= 0 && new_C >=0 && new_L < MAX_LEVEL && new_R < MAX_ROW && new_C < MAX_COLUMN)
            if(cells[new_L][new_R][new_C].is_empty && cells[new_L][new_R][new_C].how_far > cells[L][R][C].how_far + 1)
            {
                cells[new_L][new_R][new_C].how_far = cells[L][R][C].how_far + 1;
                DFS(new_L, new_R, new_C);
            }
    }

    if(cells[End_cell[0]][End_cell[1]][End_cell[2]].how_far == INF)
        return -1;
    else
        return cells[End_cell[0]][End_cell[1]][End_cell[2]].how_far;
}

int solve_problem()
{
    save_dungeon();
    //print_dungeon();
    
    return DFS(Start_cell[0], Start_cell[1], Start_cell[2]);
}

int main()
{
    while(cin >> MAX_LEVEL >> MAX_ROW >> MAX_COLUMN)
    {
        if(!MAX_LEVEL && !MAX_ROW && !MAX_COLUMN)
            break;

        int ans;
        ans = solve_problem();
        //print_dungeon();
        if(ans == -1)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << ans << " minute(s)." << endl;
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

