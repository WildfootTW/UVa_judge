/*
 * UVa1754.cpp
 * Copyleft (ɔ) 2021 wildfootw <wildfootw@wildfoo.tw>
 *
 * Distributed under terms of the MIT license.
 */

// [ ] Completed

#include <iostream>
#include <ctime>

#define INF 2147483647
#define EPS 1e-9
#define DEFAULT_FIXSTR 3

using namespace std;

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

class UVa1754
{
public:
    UVa1754(int d, int k){}
    long long int get_squared_errors()
    {
        return 0;
    }
    void input()
    {
    }
};

int main()
{
    int d, k;
    while(cin >> d >> k)
    {
        UVa1754 solver(d, k);
        solver.input();
        long long int answer = solver.get_squared_errors();
        cout << answer << endl;
    }

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

