// LCS
// WildfootW 2018
// https://github.com/Wildfoot
// Wrong Answer

#include <iostream>
#include <ctime>
#include <vector>
#include <stack>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

#define MAX 100

typedef string word;
struct LCS_node
{
    bool visit;
    int longest;
};
static vector<word> sequence_of_word[2];
static stack<word> LCS_output;
static LCS_node LCS[MAX][MAX];

void clear_stack( stack<word> &st )
{
    stack<word> empty;
    swap(st, empty);
}

void initial()
{
    sequence_of_word[0].clear();
    sequence_of_word[1].clear();
    clear_stack(LCS_output);
    for(int i = 0;i < MAX;i++)
    {
        for(int j = 0;j < MAX;j++)
        {
            LCS[i][j].visit = false;
            LCS[i][j].longest = 0;
        }
    }
}

int find_LCS(int m, int n)
{
    if(m == -1 || n == -1)
        return 0;
    if(LCS[m][n].visit)
        return LCS[m][n].longest;
    LCS[m][n].visit = true;
    if(sequence_of_word[0][m] == sequence_of_word[1][n])
        return LCS[m][n].longest = find_LCS(m - 1, n - 1) + 1;
    else
        return LCS[m][n].longest = max(find_LCS(m - 1, n), find_LCS(m, n - 1));
}

void find_solution_backward(int m, int n)
{
    if(LCS[m][n].longest == 0)
        return;
    if(n - 1 >= 0 && LCS[m][n].longest == LCS[m][n - 1].longest)
    {
        find_solution_backward(m, n - 1);
        return;
    }
    if(m - 1 >= 0 && LCS[m][n].longest == LCS[m - 1][n].longest)
    {
        find_solution_backward(m - 1, n);
        return;
    }
    if(m - 1 >= 0 && n - 1 >= 0 && LCS[m][n].longest == LCS[m - 1][n - 1].longest + 1)
    {
        LCS_output.push(sequence_of_word[0][m]);
        find_solution_backward(m - 1, n - 1);
        return;
    }
    if(m == 0 || n == 0)
    {
        LCS_output.push(sequence_of_word[0][m]);
        return;
    }
}
inline string fix_alignment(string para)
{
    const int alignment_num = 10;
    para.resize(alignment_num, ' ');
    return para;
}
void print_LCS()
{
    cout << fix_alignment("");
    for(int i = 0;i < sequence_of_word[1].size();i++)
    {
        cout << fix_alignment(sequence_of_word[1][i]);
    }
    cout << endl;
    for(int i = 0;i < sequence_of_word[0].size();i++)
    {
        cout << fix_alignment(sequence_of_word[0][i]);
        for(int j = 0;j < sequence_of_word[1].size();j++)
        {
            cout << fix_alignment(to_string(LCS[i][j].longest));
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //bool last_new_line_flag = false;
    while(!cin.eof())
    {
        //if(last_new_line_flag)
        //    cout << endl;
        //last_new_line_flag = true;

        initial();

        for(int i = 0;i < 2;i++)
        {
            word keyin_word;
            while(cin >> keyin_word)
            {
                if(keyin_word[0] == '#')
                    break;
                sequence_of_word[i].push_back(keyin_word);
            }
        }
        int longest_ans = find_LCS(sequence_of_word[0].size() - 1, sequence_of_word[1].size() - 1);
        print_LCS();
        find_solution_backward(sequence_of_word[0].size() - 1, sequence_of_word[1].size() - 1);
        while(!LCS_output.empty())
        {
            cout << LCS_output.top();
            if(LCS_output.size() != 1)
                cout << " ";
            LCS_output.pop();
        }
        cout << endl;
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

