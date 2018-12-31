// priority queue
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>
#include <queue>
#include <vector>
#include <functional> //greater

#define INF 2147483647
#define EPS 1e-9

using namespace std;

template<typename T> void print_queue(T& origin_q) {
    auto q = origin_q;
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int count;
    while(cin >> count)
    {
        if(!count)
            break;
        priority_queue<int, vector<int>, greater<int> > pq;
        long long int cost = 0;
        for(int i = 0;i < count;i++)
        {
            int keyin;
            cin >> keyin;
            pq.push(keyin);
        }

        while(pq.size() != 1)
        {
            //print_queue(pq);
            int a, b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(a + b);
            cost += (a + b);
        }
        cout << cost << endl;
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

