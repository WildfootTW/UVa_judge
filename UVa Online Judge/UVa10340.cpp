#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string seq,subs;
    while(cin >> seq >> subs)
    {
        int ptrs = 0,ptrsub = 0;
        //cout << seq.size() << " " << subs.size() << endl;
        while(ptrs < seq.size() && ptrsub < subs.size())
        {
            if(seq[ptrs] == subs[ptrsub])
            {
                ptrs++; ptrsub++;
            }
            else
                ptrsub++;
        }
        if(ptrs == seq.size())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
