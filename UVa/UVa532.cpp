// BFS
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>
#include <queue>

#define INF 2147483647
#define MAX 30

using namespace std;

typedef struct var_cell
{
    bool is_empty;
    bool used;
    int how_far;
} cell;

typedef struct var_cell_position
{
    int level, row, column;
} cell_position;

queue<cell_position> qu;
cell cells[MAX][MAX][MAX];
//Levels Rows Columns
cell_position Start_cell, End_cell;
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
                cells[i][j][k].used = false;
                cells[i][j][k].how_far = 0;
                switch(s[k])
                {
                    case '#':
                        cells[i][j][k].is_empty = false;
                        break;
                    case '.':
                        cells[i][j][k].is_empty = true;
                        break;
                    case 'S':
                        cells[i][j][k].is_empty = true;
                        cells[i][j][k].how_far = 0;
                        Start_cell.level = i;
                        Start_cell.row = j;
                        Start_cell.column = k;
                        break;
                    case 'E':
                        cells[i][j][k].is_empty = true;
                        End_cell.level = i;
                        End_cell.row = j;
                        End_cell.column = k;
                        break;
                }
            }
        }
    }
    return;
}

void print_dungeon()
{
    cout << "Start cell = " << Start_cell.level << " " << Start_cell.row << " " << Start_cell.column << endl;
    cout << "End cell = " << End_cell.level << " " << End_cell.row << " " << End_cell.column << endl;
    for(int i = 0;i < MAX_LEVEL;i++)
    {
        for(int j = 0;j < MAX_ROW;j++)
        {
            for(int k = 0;k < MAX_COLUMN;k++)
                if(!cells[i][j][k].is_empty)
                    cout << "#";
                else if(cells[i][j][k].how_far == INF)
                    cout << "F";
                else 
                    cout << cells[i][j][k].how_far;
            cout << endl;
        }
        cout << endl;
    }
}

void print_cell(cell_position current_cell)
{
    cout << current_cell.level << " " << current_cell.row << " " << current_cell.column << endl;
    cout << cells[current_cell.level][current_cell.row][current_cell.column].how_far << " " << cells[current_cell.level][current_cell.row][current_cell.column].used << endl;
    return;
}

int BFS()
{
    while( !qu.empty() )
    {
        cell_position current_cell = qu.front();
        //cout << current_cell.level << " " << current_cell.row << " " << current_cell.column << endl;
        qu.pop();
        if(current_cell.level == End_cell.level && current_cell.row == End_cell.row && current_cell.column == End_cell.column)
            return cells[End_cell.level][End_cell.row][End_cell.column].how_far;

        for(int i = 0;i < 6;i++)
        {
            cell_position next_cell;
            switch(i)
            {
                case 3:
                    next_cell.level = current_cell.level - 1; next_cell.row = current_cell.row; next_cell.column = current_cell.column;
                    break;
                case 4:
                    next_cell.level = current_cell.level; next_cell.row = current_cell.row - 1; next_cell.column = current_cell.column;
                    break;
                case 5:
                    next_cell.level = current_cell.level; next_cell.row = current_cell.row; next_cell.column = current_cell.column - 1;
                    break;
                case 0:
                    next_cell.level = current_cell.level + 1; next_cell.row = current_cell.row; next_cell.column = current_cell.column;
                    break;
                case 1:
                    next_cell.level = current_cell.level; next_cell.row = current_cell.row + 1; next_cell.column = current_cell.column;
                    break;
                case 2:
                    next_cell.level = current_cell.level; next_cell.row = current_cell.row; next_cell.column = current_cell.column + 1;
                    break;
            }
            if(next_cell.level >= 0 && next_cell.row >= 0 && next_cell.column >=0 && next_cell.level < MAX_LEVEL && next_cell.row < MAX_ROW && next_cell.column < MAX_COLUMN)
                if(cells[next_cell.level][next_cell.row][next_cell.column].is_empty && !cells[next_cell.level][next_cell.row][next_cell.column].used) 
                {
                    cells[next_cell.level][next_cell.row][next_cell.column].how_far = cells[current_cell.level][current_cell.row][current_cell.column].how_far + 1;
                    cells[next_cell.level][next_cell.row][next_cell.column].used = true;
                    qu.push(next_cell);
                    //print_cell(current_cell);
                    //print_cell(next_cell);
                    //cout << endl;
                }
        }
    }
    return -1;
}

int solve_problem()
{
    save_dungeon();
    //print_dungeon();

    while(!qu.empty())
        qu.pop();
    
    qu.push(Start_cell);
    cells[Start_cell.level][Start_cell.row][Start_cell.column].used = true;
    
    return BFS();
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

