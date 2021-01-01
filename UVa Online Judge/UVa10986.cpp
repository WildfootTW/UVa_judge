/* dijkstra
 * Version 
 * Author: WildfootW
 * GitHub: github.com/Wildfoot
 * Copyright (C) 2018 WildfootW All rights reserved.
 *
 */

// Accepted

#include <iostream>
#include <ctime>
#include <queue>
#include <vector>
#include <stack>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

class edge
{
    public:
        int cost;
        int to;
        edge(int input_to, int input_cost);
};
class tentative_node
{
    public:
        int index, pre_index;
        int distance;
        tentative_node(int input_index, int input_pre, int input_distance);
};
class node: public tentative_node
{
    public:
        bool visit;
        node(void);
        node(const tentative_node& tnode, bool visit = true);
};
struct custom_compare
{
    bool operator()(tentative_node &lhs, tentative_node &rhs)
    {
        return lhs.distance > rhs.distance;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int max_count;
    cin >> max_count;

    for(int count = 0;count < max_count;count++)
    {
        int node_num, edge_num;
        cin >> node_num >> edge_num;
        if(!node_num)
            break;

        int start_index, end_index;
        cin >> start_index >> end_index;

        priority_queue<tentative_node, vector<tentative_node>, custom_compare> pq;      // priority_queue sort the shortest node.distance at the top of pq
        node * nodes = new node [node_num];     // save confirmed node which visit = true || shortest distance guessed now (which visit = false)
        vector<edge> * edges = new vector<edge> [node_num];     // save graph in edges

        while(edge_num--)
        {
            int input_A, input_B, input_cost;
            cin >> input_A >> input_B >> input_cost;
            edges[input_A].push_back(edge{input_B, input_cost});
            edges[input_B].push_back(edge{input_A, input_cost});
        }

        pq.push(tentative_node{start_index, -1, 0});
        while(!pq.empty())
        {
            node cnode = pq.top();
            pq.pop();
            // if the node is already on the shortest tree, just pop it.
            if(nodes[cnode.index].visit)
                continue;

            nodes[cnode.index] = node{cnode};   // confirm the tentative node to corrected node
            for(edge tedge:edges[cnode.index])
            {
                if(!nodes[tedge.to].visit && nodes[tedge.to].distance > cnode.distance + tedge.cost)
                {
                    nodes[tedge.to].distance = cnode.distance + tedge.cost;
                    pq.push(tentative_node{tedge.to, cnode.index, cnode.distance + tedge.cost});
                }
            }
        }

        cout << "Case #" << count + 1 << ": ";
        if(nodes[end_index].distance == INF)
            cout << "unreachable";
        else
            cout << nodes[end_index].distance;
        cout << endl;

        delete[] nodes;
        delete[] edges;
    }

    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}

edge::edge(int input_to, int input_cost):
to(input_to), cost(input_cost)
{
}
node::node():
visit(false), tentative_node(-1, -1, INF)
{
}
node::node(const tentative_node& tnode, bool visit):
tentative_node(tnode.index, tnode.pre_index, tnode.distance), visit(visit)
{
}
tentative_node::tentative_node(int input_index, int input_pre, int input_distance):
index(input_index), pre_index(input_pre), distance(input_distance)
{
}
