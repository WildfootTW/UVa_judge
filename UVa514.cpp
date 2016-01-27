#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        if(!n)
            break;
        bool flag = 0;

        while(1)
        {
            stack<int> s;
            int arr[n];
            for(int i = 0;i < n;i++)
            {
                cin >> arr[i];
                if(!arr[i])
                {   
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
            
            int ptr = 1;
            s.push(0);
            bool flagi = 1,flagy = 0;
            for(int i = 0;i < n;i++)
            {
                flagi = 1;

                while( (ptr <= n || s.top() == arr[i] ) && flagi)
                {
                    //if(s.size() != 0)
                    //cout << "s.top() = " << s.top() << "ptr = " << ptr << "i = " << i << endl;
                    if(ptr == arr[i])
                    {
                        ptr++;
                        flagi = 0;//i++
                    }
                    else if(s.size() != 0)
                    {
                        if(arr[i] == s.top())
                        {
                            s.pop();
                            flagi = 0;//i++
                        }
                        else
                        {
                           s.push(ptr);
                           ptr++;
                        }
                    }
                    else
                    {
                        s.push(ptr);
                        ptr++;
                    }
                }
                if(flagi)
                {
                    flagy = 1;
                }
            }
            if(flagy) 
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
        cout << endl;

        //if(flag)
        //    break;
        //cout << endl;
    }
    return 0;
}
