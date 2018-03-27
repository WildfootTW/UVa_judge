// 
// WildfootW 2018
// https://github.com/Wildfoot
// Wrong Answer

#include <iostream>
#include <ctime>
#include <array>
#include <cstring>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

#define ITEM_NUM_MAX 6
#define COMBO_NUM_MAX 8
#define ELEMENT_MAX 11  //most 10 + 1(0)

struct combo
{
    array<int, ITEM_NUM_MAX> item_num;
    int price;
    combo(array<int, ITEM_NUM_MAX> create_combo_paramenter = {0}, int price = 0)
    {
        this->price = price;
        this->item_num = create_combo_paramenter;
    }
};

static int item_total_num, combo_total_num;
static combo combos[COMBO_NUM_MAX];
static int dp[ELEMENT_MAX][ELEMENT_MAX][ELEMENT_MAX][ELEMENT_MAX][ELEMENT_MAX][ELEMENT_MAX];

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
int min_price(int request[])
{
    int the_min_price = dp[request[0]][request[1]][request[2]][request[3]][request[4]][request[5]];
    for(int i = 0;i < combo_total_num;i++)
    {
        int new_item_ptr[6];
        for(int j = 0;j < ITEM_NUM_MAX;j++)
        {
            new_item_ptr[j] = request[j] - combos[i].item_num[j];
            if(!(new_item_ptr[j] >= 0))
            {
                goto finish_a_combo_dp; //check if out of dp array
            }
        }

        the_min_price = min(min_price(new_item_ptr) + combos[i].price, the_min_price);
finish_a_combo_dp:
        ;
    }
    return the_min_price;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin >> item_total_num)
    {
        memset(dp, 0, sizeof(dp));
        int item_price[6] = {0};
        for(int i = 0;i < item_total_num;i++)
        {
            cin >> item_price[i];
        }
        for(int j = 0;j < ELEMENT_MAX;j++)
        {
            for(int k = 0; k < ELEMENT_MAX;k++)
            {
                for(int l = 0;l < ELEMENT_MAX;l++)
                {
                    for(int m = 0;m < ELEMENT_MAX;m++)
                    {
                        for(int n = 0;n < ELEMENT_MAX;n++)
                        {
                            for(int o = 0;o < ELEMENT_MAX;o++)
                            {
                                dp[o][n][m][l][k][j] = o * item_price[0] + n * item_price[1] + m * item_price[2] + l * item_price[3] + k * item_price[4] + j * item_price[5];
                            }
                            if(item_total_num == 1)
                                goto dp_init_end;
                        }
                        if(item_total_num == 2)
                            goto dp_init_end;
                    }
                    if(item_total_num == 3)
                        goto dp_init_end;
                }
                if(item_total_num == 4)
                    goto dp_init_end;
            }
            if(item_total_num == 5)
                goto dp_init_end;
        }
dp_init_end:

        cin >> combo_total_num;
        for(int i = 0;i < combo_total_num;i++)
        {
            int price;
            array<int, ITEM_NUM_MAX> create_combo_paramenter = {0};
            for(int j = 0;j < item_total_num;j++)
            {
                cin >> create_combo_paramenter[j];
            }
            cin >> price;
            combo temp_combo(create_combo_paramenter, price);
            combos[i] = temp_combo;
        }
//        print_combo();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//        for(int j = 0;j < ELEMENT_MAX;j++)
//            for(int k = 0; k < ELEMENT_MAX;k++)
//                for(int l = 0;l < ELEMENT_MAX;l++)
//                    for(int m = 0;m < ELEMENT_MAX;m++)
//                        for(int n = 0;n < ELEMENT_MAX;n++)
//                        {
//                            cout << j << " " << k << " " << l << " " << m << " " << n << " : ";
//                            for(int o = 0;o < ELEMENT_MAX;o++)
//                                cout << dp[j][k][l][m][n][o] << " ";
//                            cout << endl;
//                        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        int question_num;
        cin >> question_num;
        while(question_num--)
        {
            int question_request[ITEM_NUM_MAX] = {0}, ans;
            for(int i = 0;i < item_total_num;i++)
            {
                cin >> question_request[i];
            }
            ans = min_price(question_request);
            cout << ans << endl;
        }
    }

//    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

