// 
// WildfootW 2018
// https://github.com/Wildfoot
// Wrong Answer

#include <iostream>
#include <ctime>

#define INF 2147483647

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int a, b, c, d;
    double eps;
    while(cin >> a >> b){
        cin >> eps;
        long double t1 = (long double)a/b, t2;
        for(d = 1; ; d++) {
            c = (long long)(t1*d);
            while(a*d >= b*c)
                c++;
            t2 = (long double)c/d;
            cout << "c = " << c << " d = " << d << endl;
            cout << t2 << " " << t1 << endl;
            cout << t2 - t1 << endl;
            if(t2-t1 <= eps) {
                cout << c << " " << d << endl;
                break;
            }
        }
    }

    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

