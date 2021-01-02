/*
 * generate.cpp
 * Copyleft (ɔ) 2021 wildfootw <wildfootw@wildfoo.tw>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(nullptr));
    int pixel_value_amount = 5;
    cout << pixel_value_amount << " " << rand() % pixel_value_amount + 1 << endl;
    map<int, int> my_map;
    while(my_map.size() != pixel_value_amount)
    {
        my_map[rand() % 255 + 1] = rand() % 99999 + 1;
    }
    for(int i = 1;i <= 255;++i)
    {
        if(my_map.find(i) != my_map.end())
            cout << i << " " << my_map[i] << endl;
    }
}
