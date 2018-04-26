/*
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

// Wrong Answer

#include <iostream>
#include <ctime>
#include <vector>
#include <functional>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

#define MAX 11

class edge
{
    public:
        int value, to_node;
        edge(void);
        edge(int input_to, int input_value);
        bool operator > (const edge&);
}
edge::edge()
{
}
edge::edge(int input_to, int input_value):
value(input_value), to_node(input_to)
{
}
bool edge::operator> (const edge& param)
{
    return this.value > param.value;
}

vector<edge> intersection[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int node_num;
    while(cin >> node_num)
    {
        if(!node_num)
            break;
        // input
        for(int i = 1;i <= node_num;i++)
        {
            int k;
            cin >> k;
            for(int j = 0;j < k;j++)
            {
                int input_node, input_value;
                cin >> input_node >> input_value;
                intersection[i].push_back(edge{input_node, input_value});
            }
        }
        int node_start, node_end;
        cin >> node_start >> node_end;

        priority_queue< edge, vector<edge>, greater<edge> > pq;
        pq.push(edge{node_start, 0});
    }


    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

