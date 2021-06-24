/*
 * 13243.cpp
 * Copyleft (ɔ) 2021 wildfootw <wildfootw@wildfoo.tw>
 *
 * Distributed under terms of the MIT license.
 */

// [ ] Completed RE

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <ctime>

#define INF 2147483647
#define EPS 1e-9
#define DEFAULT_FIXSTR 3

using namespace std;

/*
inline string _fixstr(string para, int alignment_num = DEFAULT_FIXSTR)
{
    para.resize(alignment_num, ' ');
    return para;
}
inline string _fixstr(char para, int alignment_num = DEFAULT_FIXSTR)
{
    string ret = string(1, para);
    return _fixstr(ret, alignment_num);
}
inline string _fixstr(int para, int alignment_num = DEFAULT_FIXSTR)
{
    string ret = to_string(para);
    if(para == INF)
        ret = "INF";
    return _fixstr(ret, alignment_num);
}
*/

int longest_front_substring(string main_str, string material_str, int& l, int& r)
{
    vector<int> match_length(material_str.length());
    if(main_str[0] == material_str[0]) match_length[0] = 1;
    else match_length[0] = 0;

    string::iterator main_str_ptr = main_str.begin() + 1;

    for(int i = 1;i < material_str.length();++i)
    {
        if(material_str[i] == *main_str_ptr)
        {
            match_length[i] = match_length[i - 1] + 1;
            ++main_str_ptr;
        }
        else
        {
            match_length[i] = 0;
            main_str_ptr = main_str.begin();
        }
    }

    int ret = 0; // longest_front_substring_length

    for(int i = 0;i < material_str.length();++i)
    {
        if(ret < match_length[i])
        {
            ret = match_length[i];
            r = i;
        }
    }
    if(ret == 0)
        return -1;
    l = r - ret + 1;
    return ret;
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n, m;
        string s_forward, s_reverse, t;
        cin >> n;
        getline(cin, s_forward);
        getline(cin, s_forward);
        s_reverse = s_forward;
        reverse(s_reverse.begin(), s_reverse.end());
        cin >> m;
        getline(cin, t);
        getline(cin, t);

        int ans = 0;
        queue<int> ans_l_r;
        while(t.length() != 0)
        {
            int longest_front_substring_length, longest_front_substring_length_reverse;
            int l, r, l_reverse, r_reverse;
            longest_front_substring_length = longest_front_substring(t, s_forward, l, r);
            longest_front_substring_length_reverse = longest_front_substring(t, s_reverse, l_reverse, r_reverse);
            if(longest_front_substring_length_reverse > longest_front_substring_length)
            {
                l = s_reverse.length() - l_reverse - 1;
                r = s_reverse.length() - r_reverse - 1;
                longest_front_substring_length = longest_front_substring_length_reverse;
            }
            if(longest_front_substring_length == -1)
            {
                ans = -1;
                break;
            }
            else
            {
                ++ans;
                ans_l_r.push(l + 1);
                ans_l_r.push(r + 1);
                t = t.substr(longest_front_substring_length, t.length() - longest_front_substring_length);
            }
        }
        if(ans == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
            while(!ans_l_r.empty())
            {
                cout << ans_l_r.front() << " ";
                ans_l_r.pop();
                cout << ans_l_r.front() << endl;
                ans_l_r.pop();
            }
        }
    }

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

