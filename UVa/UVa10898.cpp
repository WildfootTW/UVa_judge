// 
// WildfootW 2018
// https://github.com/Wildfoot
// Wrong Answer

#include <iostream>
#include <ctime>
#include <cstring>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

#define MAX 14
#define ITEM_NUM_MAX 6

struct combo
{
    int item_num[ITEM_NUM_MAX];
    int price;
    combo(int create_combo_paramenter[ITEM_NUM_MAX] = {0}, int price = 0)
    {
        this->price = price;
        memcpy(this->item_num, create_combo_paramenter, ITEM_NUM_MAX * 4);
    }
};

static int item_total_num;
static combo combos[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin >> item_total_num)
    {
        for(int i = 0;i < item_total_num;i++)
        {
            int create_combo_paramenter[ITEM_NUM_MAX] = {0}, price;
            create_combo_paramenter[i] = 1;
            cin >> price;
            combo temp_combo(create_combo_paramenter, price);
            combos[i] = temp_combo;
        }
        int m;
        cin >> m;
        for(int i = 0;i < m;i++)
        {
            int create_combo_paramenter[ITEM_NUM_MAX] = {0}, price;
            for(int j = 0;j < item_total_num;j++)
            {
                cin >> create_combo_paramenter[j];
            }
            cin >> price;
            combo temp_combo(create_combo_paramenter, price);
            combos[item_total_num + i] = temp_combo;
        }
        int question_num;
        cin >> question_num;
        while(question_num--)
        {
            //solve_problem();
        }
    }




    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

