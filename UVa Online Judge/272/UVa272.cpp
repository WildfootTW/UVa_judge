//done
#include <iostream>

using namespace std;

int main(  )
{
	int t=1;
      	char c;
	while(cin.get(c))
	{
		if(c!='"')
			cout << c;
		else if(c=='"'&&t%2)
		{
			t++;
			cout <<"``";
		}
		else
		{
			cout << "''";
			t++;
		}
			
	}
	return 0;
}
