#include <iostream>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	char c[]="`1234567890-=""qwertyuiop[]\\""asdfghjkl;'""zxcvbnm,./";
	for(int i = 0, n = s.length();i < n;i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i]=s[i]-'A'+'a';
		}
		for (int j = 0,k = sizeof(c);j < k;j++)
		{	
			if(s[i]==c[j])
			{
				s[i]=c[j-2];
				
			}
		}
		cout<<s[i];		
	}
	cout<<endl;
}
