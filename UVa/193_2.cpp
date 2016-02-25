#include <iostream>
#include <vector>
using namespace std;
int N, K;
vector<int> toNxt[105];
int color[105]; // Black is 1, White is 2
int MaxNum;
vector<int> Container, Ans;

void Initial(int N);
void backtracking(int n);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int M;
    cin >> M;
    while (M--) 
    {
        int K;
        cin >> N >> K;//node edge
        Initial(N);

        int a, b;
        while(K--)
        {
            cin >> a >> b;
            toNxt[a].push_back(b);
            toNxt[b].push_back(a);
        }

        backtracking(1); //從1開始填到N

        cout << MaxNum << endl << Ans[0];
        for (int i = 1; i < MaxNum; ++i)
            cout << " " << Ans[i];
        cout << endl;
    }
}
void Initial(int N)
{
    Container.clear();
    MaxNum = 0;
    for (int i = 1; i <= N; ++i) 
    {
        toNxt[i].clear();
        color[i] = 0;
    }
}
void backtracking(int n)
{
    if (n > N) {
        //如果這個填法黑色數量比MaxNum大或是等於MaxNum但最後一個是黑色,則更新MaxNum和Ans
        if (Container.size() > MaxNum ||
            Container.size() == MaxNum && color[n - 1] == 1) {
            MaxNum = Container.size();
            Ans = Container;
        }
        return;
    }

    bool hasBlack = true; //確認這個node能不能填入黑色
    for (int i : toNxt[n])
        if (color[i] == 1) hasBlack = false;

    if (hasBlack) {
        Container.push_back(n);
        color[n] = 1;

        backtracking(n + 1);

        Container.pop_back();
        color[n] = 0;
    }
    color[n] = 2;

    backtracking(n + 1);

    color[n] = 0;
}
