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
#include <queue>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

#define MAX 11

class edge
{
    public:
        int delay, to_node, from_node;
        edge(int input_from, int input_to, int input_delay);
        bool operator> (const edge&);
        bool operator< (const edge&);
};
class node
{
    public:
        int total_delay, pre;
        vector<edge> edges;
        node(int input_delay = INF);
};
edge::edge(int input_from, int input_to, int input_delay):
from_node(input_from), delay(input_delay), to_node(input_to)
{
}
bool edge::operator> (const edge& param)
{
    return this->delay > param.delay;
}
bool edge::operator< (const edge& param)
{
    return this->delay < param.delay;
}
node::node(int input_delay):
total_delay(input_delay), pre(-1)
{
}

struct custom_compare
{
    bool operator()(edge &lhs, edge &rhs)
    {
        return lhs.delay < rhs.delay;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int node_num;
    while(cin >> node_num)
    {
        if(!node_num)
            break;

        priority_queue< edge, vector<edge>, custom_compare > pq;
        node * nodes = new node[node_num + 1];

        // input
        for(int i = 1;i <= node_num;i++)
        {
            int k;
            cin >> k;
            for(int j = 0;j < k;j++)
            {
                int input_to, input_delay;
                cin >> input_to >> input_delay;
                nodes[i].edges.push_back(edge{i, input_to, input_delay});
            }
        }
        int node_start, node_end;
        cin >> node_start >> node_end;

        nodes[node_start].total_delay = 0;
        nodes[node_start].pre = -1;
        for(edge n:nodes[node_start].edges)
            pq.push(n);

        while(pq.size())
        {
            node current_node = nodes[pq.top().to_node];
            pq.pop();
            for(edge next_edge:current_node.edges)
            {
                if(node[current_edge.to_node].total_delay + next_edge.delay > node[next_edge.to_node].total_delay )
            }

        }
    }


    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

