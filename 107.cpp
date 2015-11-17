#include <iostream>

using namespace std;

int main()
{

	int son=30,daughter=0,gson=0;
	for(int i=1;i<=30;i++)
	{
		//son=son+i;
		daughter=daughter+i;
		int WW=0;
		for(int j=1;j<=i;j++)
		{
			WW=WW+j;
			//WW=WW*i;
		}
		gson=gson+WW*i;
	}
	//cout<<son<<"+"<<daughter<<"+"<<gson<<endl;
	cout<<son+daughter+gson<<endl;
}
