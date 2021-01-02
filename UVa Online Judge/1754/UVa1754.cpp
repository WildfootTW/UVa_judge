/*
 * UVa1754.cpp
 * Copyleft (ɔ) 2021 wildfootw <wildfootw@wildfoo.tw>
 *
 * Distributed under terms of the MIT license.
 */

// [ ] Completed

#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>
#include <ctime>

using namespace std;

static const unsigned long long int INF = 1e18;

template<size_t D, size_t K>
class UVa1754
{
public:
    UVa1754()
    {
        for(size_t i = 0;i < D;++i)
            for(size_t j = 0;j < D;++j)
                squared_errors[i][j].fill(INF);
    }
    unsigned long long int get_sum_squared_errors(size_t pos = 0, size_t d = D, size_t k = K)
    {
        if(squared_errors[pos][d][k] != INF) return squared_errors[pos][d][k];
        if(k == 1) return squared_errors[pos][d][k] = get_squared_errors(pos, d);
        unsigned long long int ret = INF;
        for(size_t i = 1;i <= d;++i)
        {
            ret = min(ret, get_sum_squared_errors(pos, i, 1) + get_sum_squared_errors(i, k - i, k - 1));
        }
        return squared_errors[pos][d][k] = ret;
    }
    void input()
    {
        for(size_t i = 0;i < D;++i)
        {
            cin >> pixels[i].first >> pixels[i].second;
        }
    }
private:
    array<array<array<unsigned long long int, K>, D>, D> squared_errors; // array[D][D][K]
    array<pair<int, unsigned long long int>, D> pixels;

    unsigned long long int get_squared_errors(size_t pos, size_t d)
    {
        unsigned long long int ret = INF;
        for(size_t i = pixels[pos].first;i <= pixels[pos + d - 1].first;++i) // new position
        {
            unsigned long long int nret = 0;
            for(size_t j = pos;j < (pos + d);++j)
            {
                nret += (pow((pixels[pos + j].first - i), 2) * pixels[pos + j]);
            }
            ret = min(ret, nret);
        }
        return ret;
    }
};

int main()
{
    size_t d, k;
    while(cin >> d >> k)
    {
        UVa1754<d, k> solver;
        solver.input();
        unsigned long long int answer = solver.get_sum_squared_errors();
        cout << answer << endl;
    }

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

