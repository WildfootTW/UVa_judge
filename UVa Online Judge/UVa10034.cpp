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
#include <cmath>
#include <queue>
#include <vector>

#define INF 2147483647
#define EPS 1e-9

using namespace std;

class node
{
    public:
        double x, y;
        node(void)
        {
        }
        node(double input_x, double input_y):
        x(input_x), y(input_y)
        {
        }
};

inline double distance(node a, node b)
{
    return pow(pow(a.x - b.x, 2) + pow(a.y - b.y, 2), 0.5);
}

class edge
{
    public:
        node * u, * v;
        double cost;
        edge(void)
        {
        }
        edge(node * input_u, node * input_v):
        u(input_u), v(input_v)
        {
            cost = distance(*u, *v);
        }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int case_num;
    cin >> case_num;
    for(int count = 0;count < case_num;count++)
    {
        int node_num;
        cin >> node_num;
        node * nodes = new node [node_num];
//        edge * edges = new edge []
        for(int i = 0;i < node_num;i++)
        {
            double input_x, input_y;
            cin >> input_x >> input_y;
            nodes[i] = node{input_x, input_y};
        }
        edge test = edge{&nodes[0], &nodes[1]};

        delete [] nodes;
    }



    clog << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;
}


