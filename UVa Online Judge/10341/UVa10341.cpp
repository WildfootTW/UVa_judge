// binary search
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>
#include <cmath>

#define INF 2147483647
#define EPS 1e-7

using namespace std;

static int p, q, r, s, t, u;
//p ∗ e ^ −x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x ^ 2 + u = 0
inline double proposition(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x, 2) + u;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout.precision(4);
    while(cin >> p >> q >> r >> s >> t >> u)
    {
        double upper_bound = 1, lower_bound = 0, ans = -1;
        while(abs(upper_bound - lower_bound) > 1e-9)
        {
            double test_num = (upper_bound + lower_bound) / 2;
            double result = proposition(test_num);
            //cout << upper_bound << " " << lower_bound << " " << test_num << " " << result << endl;
            if(abs(result) < EPS)
            {
                ans = test_num;
                break;
            }
            if(result > 0)
            {
                lower_bound = test_num;
                continue;
            }
            if(result < 0)
            {
                upper_bound = test_num;
                continue;
            }
        }
        if(ans == -1.0)
        {
            cout << "No solution" << endl;
        }
        else
        {
            cout << fixed << ans << endl;
        }
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

