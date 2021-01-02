//done
#include <iostream>
#include <stdio.h>

using namespace std;

int count[26]={0},len=1;
void run(string s) {
	for(int i = 0,n = s.length();i < n;i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			count[s[i]-65]++;
			len++;	
		}
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			count[s[i]-97]++;
			len++;
		}
	}

}
int main()
{
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	while(t--)
	{
		getline(cin, s);
		run(s);		
	}
	while(--len)
	{
		for(int i = 0;i < 26;i++)
		{
			if(count[i]==len)
			//cout << 'i+65' <<" "<< count[i] <<endl;
			printf("%c %d\n",i+65,count[i]);
		}
	}
	return 0;
}
