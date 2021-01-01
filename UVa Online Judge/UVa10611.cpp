// Binary search
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <typeinfo>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int lady_chimps_num;
    vector<int> lady_chimps;
    cin >> lady_chimps_num;
    for(int i = 0;i < lady_chimps_num;i++)
    {
        int input;
        cin >> input;
        lady_chimps.push_back(input);
    }

    int Q;
    cin >> Q;
    for(int i = 0;i < Q;i++)
    {
        int Luchu_height;
        cin >> Luchu_height;
        //cout << lower_bound(lady_chimps.begin(), lady_chimps.end(), Luchu_height) - lady_chimps.begin() << endl;
        int upper_bin_ans = upper_bound(lady_chimps.begin(), lady_chimps.end(), Luchu_height) - lady_chimps.begin();
        int lower_bin_ans = lower_bound(lady_chimps.begin(), lady_chimps.end(), Luchu_height) - lady_chimps.begin();
        int low_ans, high_ans;
        if(lower_bin_ans == lady_chimps.size())
        {
            low_ans = lower_bin_ans - 1;
            high_ans = lower_bin_ans;
        }
        else if(lower_bin_ans == 0 && lady_chimps[0] > Luchu_height)
        {
            low_ans = -1;
            high_ans = 0;

        }
        else if(lady_chimps[lower_bin_ans] == Luchu_height)
        {
            low_ans = lower_bin_ans - 1;
            high_ans = upper_bin_ans;
        }
        else
        {
            low_ans = lower_bin_ans - 1;
            high_ans = lower_bin_ans;
        }
        if(low_ans < 0)
            cout << "X";
        else
            cout << lady_chimps[low_ans];
        cout << " ";
        if(high_ans >= lady_chimps.size())
            cout << "X";
        else
            cout << lady_chimps[high_ans];
        cout << endl;
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

