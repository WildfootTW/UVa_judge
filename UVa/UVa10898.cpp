// 
// WildfootW 2018
// https://github.com/Wildfoot
// Wrong Answer

#include <iostream>
#include <ctime>
//#include <cstring>
#include <array>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

#define MAX 14
#define ITEM_NUM_MAX 6
#define ELEMENT_MAX 10

struct combo
{
    //int item_num[ITEM_NUM_MAX];
    array<int, ITEM_NUM_MAX> item_num;
    int price;
    combo(array<int, ITEM_NUM_MAX> create_combo_paramenter = {0}, int price = 0)
    {
        this->price = price;
        this->item_num = create_combo_paramenter;
        //memcpy(this->item_num, create_combo_paramenter, ITEM_NUM_MAX * 4);
    }
};

static int item_total_num, combo_total_num;
static combo combos[MAX];

void print_combo()
{
    cout << "total num of item : " << item_total_num << endl;
    cout << "total num of combo : " << combo_total_num << endl;
    for(int i = 0;i < combo_total_num;i++)
    {
        for(int j = 0;j < ITEM_NUM_MAX;j++)
        {
            cout << combos[i].item_num[j] << " ";
        }
        cout << endl << combos[i].price << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin >> item_total_num)
    {
        combo_total_num = item_total_num;
        for(int i = 0;i < item_total_num;i++)
        {
            int price;
            array<int, ITEM_NUM_MAX> create_combo_paramenter = {0};
            create_combo_paramenter[i] = 1;
            cin >> price;
            combo temp_combo(create_combo_paramenter, price);
            combos[i] = temp_combo;
        }
        int m;
        cin >> m;
        combo_total_num += m;
        for(int i = 0;i < m;i++)
        {
            int price;
            array<int, ITEM_NUM_MAX> create_combo_paramenter = {0};
            for(int j = 0;j < item_total_num;j++)
            {
                cin >> create_combo_paramenter[j];
            }
            cin >> price;
            combo temp_combo(create_combo_paramenter, price);
            combos[item_total_num + i] = temp_combo;
        }
        print_combo();
        int dp[ELEMENT_MAX][ELEMENT_MAX][ELEMENT_MAX][ELEMENT_MAX][ELEMENT_MAX][ELEMENT_MAX] = {0};
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

