#include <iostream>
#define Num 500000

int father[1000000] = {0};
using namespace std;

int find(int n)
{
    if(father[n] == n)  return n;
    father[n] = find(father[n]);
    return father[n];
}
int U(int a,int b)
{
    father[find(a)] = find(b);
}

int main()
{
    for(int i = 0;i < 1000000;i++)  father[i] = i;

    int n = 0;
    cin >> n;
    string s;
    getline(cin ,s);
    while(n--)
    {
        bool commandflag1, commandflag2;
        getline(cin, s,' ');
        if(s == "you")
            commandflag1 = 0;
        else 
            commandflag1 = 1;
        getline(cin, s,' ');
        getline(cin, s,' ');
        if(s == "enemies")
            commandflag2 = 0;
        else 
            commandflag2 = 1;

        int a,b;
        cin >> a >> b;
        getline(cin ,s);

        //*
        if(!commandflag1)       //set
        {
            if(commandflag2)    //friends
            {
                //cout << endl << "set friends " << a << " " << b;
                if(find(b) == find(a + Num) || find(a) == find(b + Num))
                    cout << "angry" << endl;
                else
                {
                    U(a,b);             
                    U(a + Num,b + Num); //a's enemies and b's enemies
                }
            }
            else                //enemies
            {
                //cout << endl << "set enemies " << a << " " << b;
                if(find(a) == find(b) || find(a + Num) == find(b + Num))
                    cout << "angry" << endl;
                else
                {
                    U(a,b + Num);
                    U(b,a + Num);
                }
            } 
        }

        else                    //question
        {
            if(commandflag2)    //friends
            {
                //cout << endl << "friends? " << a << " " << b;
                if(find(a) == find(b))
                    cout << "yeap" << endl;
                else
                    cout << "nope" << endl;
            }
            else                //enemies
            {

                //cout << endl << "enemies? " << a << " " << b;
                if(find(a + Num) == find(b)) 
                    cout << "yeap" << endl;
                else
                    cout << "nope" << endl;
            }
        }
        //*/
        /*
        if(!commandflag1)
            cout << "you ";
        else
            cout << "are ";
        if(commandflag2)
            cout << "friends ";
        else
            cout << "enemies ";
            cout << a << " " << b << endl;
        //*/

    }
    return 0;
}
