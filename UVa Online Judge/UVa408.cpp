// GCD
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>

#define INF 2147483647

using namespace std;

int GCD(int a, int b)
{
    if(!b)
        return a;
    else
        return GCD(b, a % b);
}

void print_right_justified(int interger)
{
    string s = to_string(interger);
    for(int i = 0;i < 10 - s.length();i++)
        cout << " ";
    cout << s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Step, Mod;
    while(cin >> Step >> Mod)
    {
        print_right_justified(Step);
        print_right_justified(Mod);
        if(GCD(Step, Mod) == 1)
            cout << "    Good Choice" << endl << endl;
        else
            cout << "    Bad Choice" << endl << endl;
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

