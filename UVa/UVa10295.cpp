//done
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int m,n;
	cin >> m >> n;
	map<string,int> hay;
	string s;
	while(m--)
	{
		int t;
		cin >> s >> t;
		hay[s] = t;
	}
	while(n--)
	{
		int ans = 0;
		while(cin >> s)
		{
			if(s == ".")
				break;
			ans = ans + hay[s];
		}
		cout << ans << endl;
	}
	return 0;
}
