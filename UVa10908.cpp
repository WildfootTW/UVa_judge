#include <iostream>

using namespace std;

int main()
{
	int T,M,N,Q;
	char map[100][100]={0};
	cin>>T;
	while(T--)
	{
		cin >> M >> N >> Q;
		for(int i = 0;i < M;i++)
		{
			for(int j = 0;j < N;j++)
			{
				cin >> map[i][j];
			}
		}
		cout << M <<" "<< N <<" "<< Q <<endl;
		while(Q--)
		{
			int r,c,ans = 1;
			cin >> r >> c;
			for(int i = ans;i < M && i < N;i++)
			{
				int flag = 1;
				for(int a = r-i;a <= r+i;a++)
				{
					for(int b = c-i;b <= c+i;b++)
					{
						if(a < 0||b < 0||a >= M||b >= N)
						{
							flag = 0;
							break;
						}
						if(map[a][b] != map[r][c])
						{
							flag = 0;
							break;
						}
					}
				}
				if(flag)
					ans = ans + 2;
				else
					break;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
