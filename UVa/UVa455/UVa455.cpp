/*
 * UVa455.cpp
 * Copyleft (ɔ) 2020 wildfootw <wildfootw@wildfoo.tw>
 *
 * Distributed under terms of the MIT license.
 */

// [ ] Completed

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

#define NDEBUG

#ifndef KNUTHMORRISPRATT_HPP
#define KNUTHMORRISPRATT_HPP
class KnuthMorrisPratt
{
private:
#ifndef NDEBUG
    inline string fix_alignment(string para) const;
#endif // NDEBUG

protected:
    string text, pattern;
    vector<int> answer_pos; //answer text[answer_pos] == pattern[0]
    int * failure; // second longest proper prefix-suffix length

    void calculate_failure();
    void matching();

#ifndef NDEBUG
    void print_failure() const;
#endif // NDEBUG

public:
    KnuthMorrisPratt(string text, string pattern):
        text(text), pattern(pattern)
    {
        failure = new int[text.length() + pattern.length()];
    }

    ~KnuthMorrisPratt()
    {
        delete[] failure;
    }

    vector<int> answer();
};

#ifndef NDEBUG
inline string KnuthMorrisPratt::fix_alignment(string para) const
{
    const int alignment_num = 2;
    para.resize(alignment_num, ' ');
    return para;
}
#endif // NDEBUG

void KnuthMorrisPratt::calculate_failure()
{
    failure[0] = 0;
    string combine_str = pattern + text;

    for(int i = 1, j = 0;i < combine_str.length();++i)
    {
        if(failure[i - 1] == pattern.length()) // failure[i - 1] == pattern.length() is my own alternative for in case failure > pattern length (z.B. ABZABC ABZABCABZABC)
            j = 0;
            //j = failure[j - 1];

        while(combine_str[i] != combine_str[j] && j > 0)
        {
            j = failure[j - 1];
        }
        if(combine_str[i] == combine_str[j])
        {
            failure[i] = ++j;
        }
        else
        {
            failure[i] = 0;
        }
    }
}

void KnuthMorrisPratt::matching()
{
    for(int i = 0;i < text.length();++i)
    {
        if(failure[pattern.length() + i] == pattern.length())
        {
            answer_pos.push_back(i - pattern.length() + 1);
        }
    }
    return;
}

#ifndef NDEBUG
void KnuthMorrisPratt::print_failure() const
{
    for(int i = 0;i < pattern.length();++i)
        clog << fix_alignment(string(1, pattern[i]));
    for(int i = 0;i < text.length();++i)
        clog << fix_alignment(string(1, text[i]));
    clog << endl;

    for(int i = 0;i < (pattern.length() + text.length());++i)
        clog << fix_alignment(to_string(failure[i]));
    clog << endl;
}
#endif // NDEBUG

vector<int> KnuthMorrisPratt::answer()
{
    calculate_failure();

#ifndef NDEBUG
    print_failure();
#endif // NDEBUG

    matching();

#ifndef NDEBUG
    if(answer_pos.size() == 0)
    {
        clog << "Nothing Matched." << endl;
    }
    else
    {
        clog << "Matched!" << endl;
        clog << text << endl;
        int idx = 0;
        for(int i = 0;i < text.length() && idx < answer_pos.size();++i)
        {
            if(i == answer_pos[idx])
            {
                clog << "⤴";
                ++idx;
            }
            else
                clog << " ";
        }
        clog << endl;
    }
#endif // NDEBUG

    return answer_pos;
}

#endif // KNUTHMORRISPRATT_HPP

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore(1, '\n');
    while(t--)
    {
        string input;
        cin.ignore(1, '\n');
        getline(cin, input);
        for(int i = 1;i <= input.length();++i)
        {
            if(input.length() % i != 0)
                continue;
            KnuthMorrisPratt test(input, input.substr(0, i));
            if(test.answer().size() * i == input.length())
            {
                cout << i << endl;
                break;
            }
        }
        if(t) cout << endl;
    }

    //clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}
