// BFS
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>
#include <queue>

#define INF 2147483647

#define MAX 1000

typedef struct var_square
{
    bool is_wall;
    int fire_reach_time;
    bool joe_used;
    int joe_reach_time;
} square;

typedef struct var_square_position
{
    int row, column;
} square_position;

using namespace std;

square squares[MAX][MAX];
square_position JOE;
int MAX_ROW, MAX_COLUMN;
queue<square_position> qu;
queue<square_position> fire_start_qu;

inline void erase_qu()
{
    while(!qu.empty())
        qu.pop();
    return;
}
inline void erase_fire_qu()
{
    while(!fire_start_qu.empty())
        fire_start_qu.pop();
    return;
}

void fill_up_maze()
{
    string s;
    getline(cin, s);
    for(int i = 0;i < MAX_ROW;i++)
    {
        getline(cin, s);
        for(int j = 0;j < MAX_COLUMN;j++)
        {
            squares[i][j].fire_reach_time = INF;
            squares[i][j].joe_used = false;
            squares[i][j].joe_reach_time = INF;
            switch(s[j])
            {
                case '#':
                    squares[i][j].is_wall = true;
                    break;
                case '.':
                    squares[i][j].is_wall = false;
                    break;
                case 'J':
                    squares[i][j].is_wall = false;
                    squares[i][j].joe_reach_time = 0;
                    JOE.row = i; JOE.column = j;
                    break;
                case 'F':
                    squares[i][j].is_wall = false;
                    squares[i][j].fire_reach_time = 0;
                    square_position fire_s;
                    fire_s.row = i; fire_s.column = j;
                    fire_start_qu.push(fire_s);
                    break;
            }
        }
    }
    return;
}
inline bool position_valid(square_position p)
{
    return (p.row >= 0 && p.column >= 0 && p.row < MAX_ROW && p.column < MAX_COLUMN);
}
void fire_BFS(square_position fire_s)
{
    erase_qu();
    qu.push(fire_s);
    while(!qu.empty())
    {
        square_position current_p = qu.front();
        qu.pop();
        for(int i = 0;i < 4;i++)
        {
            square_position next_p = current_p;
            switch(i)
            {
                case 0:
                    next_p.row++;
                    break;
                case 1:
                    next_p.row--;
                    break;
                case 2:
                    next_p.column++;
                    break;
                case 3:
                    next_p.column--;
                    break;
            }
            if(position_valid(next_p))
            {
                square next_square = squares[next_p.row][next_p.column], current_square = squares[current_p.row][current_p.column];
                if(!next_square.is_wall && next_square.fire_reach_time > current_square.fire_reach_time + 1)
                {
                    squares[next_p.row][next_p.column].fire_reach_time = current_square.fire_reach_time + 1;
                    qu.push(next_p);
                }
            }
        }
    }
    return;
}
int joe_BFS()
{
    erase_qu();
    qu.push(JOE);
    while(!qu.empty())
    {
        square_position current_p = qu.front();
        if(current_p.row == 0 || current_p.column == 0 || current_p.row == MAX_ROW - 1 || current_p.column == MAX_COLUMN - 1)
            return squares[current_p.row][current_p.column].joe_reach_time;
        qu.pop();
        for(int i = 0;i < 4;i++)
        {
            square_position next_p = current_p;
            switch(i)
            {
                case 0:
                    next_p.row++;
                    break;
                case 1:
                    next_p.row--;
                    break;
                case 2:
                    next_p.column++;
                    break;
                case 3:
                    next_p.column--;
                    break;
            }
            if(position_valid(next_p))
            {
                square next_square = squares[next_p.row][next_p.column], current_square = squares[current_p.row][current_p.column];
                if(!next_square.is_wall && !next_square.joe_used && next_square.fire_reach_time > current_square.joe_reach_time + 1)
                {
                    squares[next_p.row][next_p.column].joe_reach_time = current_square.joe_reach_time + 1;
                    squares[next_p.row][next_p.column].joe_used = true;
                    qu.push(next_p);
                }
            }
        }
    }
    return -1;
}
void solve_problem()
{
    cin >> MAX_ROW >> MAX_COLUMN;
    erase_fire_qu();
    fill_up_maze();
    while(!fire_start_qu.empty())
    {
        fire_BFS(fire_start_qu.front());
        fire_start_qu.pop();
    }

    int flag;
    flag = joe_BFS();
    if(flag == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << flag + 1 << endl;
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
        solve_problem();
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

