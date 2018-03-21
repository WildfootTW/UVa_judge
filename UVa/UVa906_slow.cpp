// Epsilon ε
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>

#define INF 2147483647
#define EPS 1e-14

using namespace std;

// 1 < a, b < 100000
// 10 ^ -8 < n < 10 ^ -1

static int a, b, c, d;
static double n;
// float    ± 3.4 · 10± 38
// double   ± 1.7 · 10± 308

void solve_case()
{
    //cout << (double)a / (double)b << endl;
    d = 1;
    while(true)
    {
        c = (double)a / b * d;
        while(!((long int)a * d < (long int)c * b))
            c++;
        //cout << "c = " << c << " d = " << d << endl;
        //cout << (double)c / d << " " <<  (double)a / b << endl;
        //cout << (double)c / d - (double)a / b << " n = " << n << endl;
        
        //if((double)c / d - (double)a / b <= n)
        //above will make some error in a = 1040, b = 65, c = 1601, d = 100
        //n = 0.01
        //(double)c / d - (double)a / b - n = 1.56299e-15
        if(((double)c / d - (double)a / b) - n < EPS)
            break;
        d++;
    }
    cout << c << " " << d << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> a >> b >> n)
    {
        solve_case();
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

