//done
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,int> tree;
map<string,int>::iterator it;
string s, name;
//char c[1000000][32];
//void run();

int main()
{
	int T;
	//string s;
	cin >> T;
	getline(cin, s);
	getline(cin, s);

	for(int c = 0;c < T;c++)
	{
		int count = 0;
		tree.clear();
		//讀到檔案結尾為止
		while(!cin.eof())
		{
			//讀到空白行為止
			getline(cin, name);
			if(name[0] == '\0')
				break;

			count++;
			it = tree.find(name);
			
			//確認樹名在不在map中
			if(it == tree.end())
				tree[name] = 1;
			else
				tree[name]++;
		}
		if(c > 0)
			cout << endl;

		for(it = tree.begin();it != tree.end();it++)
		{	
			float per = 100.0 * it->second / count;
			//設定精準度 小數點後四位
			cout.precision(4);
			cout.setf(cout.fixed);
			cout << it->first << ' ' << per << endl;
		}		
		//cout << "run" << endl;
		//run();
	}
	return 0;
}

/*void run()
{

}*/
