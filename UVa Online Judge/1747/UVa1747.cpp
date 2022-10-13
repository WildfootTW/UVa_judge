/*
 * UVa1747.cpp
 * ACM ICPC World Finals 2016 Problem L: Swap Space
 * Copyleft (ɔ) 2022 wildfootw <wildfootw@wildfoo.tw>
 *
 * Distributed under terms of the MIT license.
 */

// [ ] Completed

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//#define NDEBUG

class UVa1747
{
public:
    UVa1747(const vector< pair<int, int> > &drive_capacity): drive_capacity(drive_capacity)
    {
#ifndef NDEBUG
        cout << "Drive Capacity: \n";
        for(size_t i = 0;i < drive_capacity.size(); ++i)
        {
            cout << drive_capacity[i].first << " " << drive_capacity[i].second << endl;
        }
        cout << "Drive Capacity --END--\n";
#endif //NDEBUG
    }
    int minimum_extra_capacity()
    {
        return 0;
    }
private:
    const vector< pair<int, int> > &drive_capacity;
};

int main(int argc, char* argv[])
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    int t;
    cin >> t;
    vector< pair<int, int> > drive_capacity;
    while(t--)
    {
        int drive_capacity_old, drive_capacity_new;
        cin >> drive_capacity_old >> drive_capacity_new;
        drive_capacity.push_back( make_pair(drive_capacity_old, drive_capacity_new) );
    }

    UVa1747 uva_1747(drive_capacity);
    cout << uva_1747.minimum_extra_capacity() << endl;

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

