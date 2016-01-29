//done
#include <iostream>

using namespace std;

int runf(int n)
{
	int o[10]={0},t=0;
	for(int i = 0;n >= 10;i++)
	{
		o[i] = n % 10;
		n = n / 10;
		//cout<<"o["<<i<<"]="<<o[i]<<endl;
	}
	o[9]=n;
	//cout<<"o[9]="<<o[9]<<endl;
	for(int i = 0;i < 10;i++)
	{
		t = t + o[i];
		//cout<<"t="<<t<<endl;
	}
	//cout<<"t="<<t<<endl;
	return t;
}


int main()
{
while(1)
{
	int n;
	cin>>n;
	if(n==0)
	break;

	while(1)
	{
		if(n<10)
		{
			cout<<n<<endl;
			break;
		}
		else
			n = runf(n);
	}
}
return 0;
}
