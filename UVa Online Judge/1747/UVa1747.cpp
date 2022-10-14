/*
 * UVa1747.cpp
 * ACM ICPC World Finals 2016 Problem L: Swap Space
 * Copyleft (ɔ) 2022 wildfootw <wildfootw@wildfoo.tw>
 *
 * Distributed under terms of the MIT license.
 */

// [x] Completed

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

#define NDEBUG

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
    long long int get_minimum_extra_capacity()
    {
        extra_capacity = 0;
        free_capacity = 0;
        classify_dc();
        sort_dc_increase();
        sort_dc_decrease();
#ifndef NDEBUG
        print_dc_ptr(dc_increase_ptr);
        print_dc_ptr(dc_decrease_ptr);
#endif //NDEBUG
        calc_extra_capacity(dc_increase_ptr);
        calc_extra_capacity(dc_decrease_ptr);
        return extra_capacity;
    }
private:
    const vector< pair<int, int> > &drive_capacity;
    vector< pair<int, int> const* > dc_increase_ptr, dc_decrease_ptr; // increase include equal
    long long int extra_capacity, free_capacity;
    void classify_dc()
    {
        for(size_t i = 0;i < drive_capacity.size(); ++i)
        {
            if(drive_capacity[i].first > drive_capacity[i].second)
                dc_decrease_ptr.push_back(&drive_capacity[i]);
            else
                dc_increase_ptr.push_back(&drive_capacity[i]);
        }

    }
    void sort_dc_increase()
    {
        sort(dc_increase_ptr.begin(),
                dc_increase_ptr.end(),
                [this](const pair<int, int>* const a, const pair<int, int>* const b)
                {
                    if(a->first == b->first) return a->second > b->second;
                    else return a->first < b->first;
                });
    }
    void sort_dc_decrease()
    {
        sort(dc_decrease_ptr.begin(),
                dc_decrease_ptr.end(),
                [this](const pair<int, int>* const a, const pair<int, int>* const b)
                {
                    if(a->second == b->second) return a->first > b->first;
                    else return a->second > b->second;
                    //if(a->first == b->first) return a->second < b->second;
                    //else return a->first > b->first;
                });
    }
    void calc_extra_capacity(const vector< pair<int, int> const* > & dc_ptr)
    {
        for(size_t i = 0;i < dc_ptr.size(); ++i)
        {
            if(dc_ptr[i]->first > free_capacity)
            {
                extra_capacity += dc_ptr[i]->first - free_capacity;
                free_capacity += dc_ptr[i]->first - free_capacity;
            }
            free_capacity -= dc_ptr[i]->first;
            free_capacity += dc_ptr[i]->second;
#ifndef NDEBUG
	    cout << "extra: " << extra_capacity << " free: " << free_capacity << endl;
#endif //NDEBUG
        }
    }
#ifndef NDEBUG
    void print_dc_ptr(const vector< pair<int, int> const* > & dc_ptr)
    {
        cout << "Drive Capacity: \n";
        for(size_t i = 0;i < dc_ptr.size(); ++i)
        {
            cout << dc_ptr[i]->first << " " << dc_ptr[i]->second << endl;
        }
        cout << "Drive Capacity --END--\n";
    }
#endif //NDEBUG
};

int main(int argc, char* argv[])
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    int t;
    while(cin >> t)
    {
        vector< pair<int, int> > drive_capacity;
        while(t--)
        {
            int drive_capacity_old, drive_capacity_new;
            cin >> drive_capacity_old >> drive_capacity_new;
            drive_capacity.push_back( make_pair(drive_capacity_old, drive_capacity_new) );
        }

        UVa1747 uva_1747(drive_capacity);
        cout << uva_1747.get_minimum_extra_capacity() << endl;
    }

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

