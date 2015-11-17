
#include <iostream>
#include <stack>
using namespace std;
 
bool fun(string s) {
	//int top = 0;
        //char stack[75];
        stack<int> x;
	x.push(0);
        for (int i = 0, n = s.length();i < n && x.size() != 0;i++)
	{
		//int chk=x.top;
                if (s[i] == '(')
		{
                        //stack[top++] = ')';
                        x.push(1);
                } 
		else if (s[i] == '[') 
		{
                        //stack[top++] = ']';
                        x.push(2);
                } 
		else if (s[i] == ')') 
		{
			if(x.top() != 1)
			{
				cout<<"x.top!=1||="<<x.top()<<endl;
				return 0;
			}
			else
			x.pop();
                //        char s2 = stack[--top];
                //        if (top < 0 || s[i] != s2)
                //                return false;
                }
		else if (s[i] == ']')
		{
			if(x.top() != 2)
			{
				cout<<"x.top!=2||="<<x.top()<<endl;
				return 0;
			}
			else
			x.pop(); 
		}

        }
	if(x.size() == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main() {
        string s;
        int n;
        cin >> n;
        getline(cin, s);
        while(n--) 
	{
                getline(cin, s);
                if(fun(s)) 
		{
                        cout << "Yes" << endl;
                } 
		else 
		{
                        cout << "No" << endl;
                }
        }
}
