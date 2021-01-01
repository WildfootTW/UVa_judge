// 
// WildfootW 2018
// https://github.com/Wildfoot
// Accepted

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

#define MAX 100001

struct node{
    int root;
    vector<int> sons;
};

node nodes[MAX];

void initial(int n)
{
    for(int i = 0;i <= n;i++)
    {
        node *the_node = &nodes[i];
        the_node->root = i;
        the_node->sons.clear();
        the_node->sons.push_back(i);
    }
    return;
}
void unions(int p, int q)
{
    p = nodes[p].root;
    q = nodes[q].root;
    node *node_p = &nodes[p], *node_q = &nodes[q];

    if(p == q)
        return;

    if(node_p->sons.size() < node_q->sons.size())
    {
        swap(node_p, node_q);
        swap(p, q);
    }

    for(int n:node_q->sons)
    {
        node_p->sons.push_back(n);
        nodes[n].root = p;
    }
    node_q->sons.clear();

    return;
}

//Move p to the set containing q
void moves(int p, int q)
{   
    int root_p = nodes[p].root;
    int root_q = nodes[q].root;
    node *root_node_p = &nodes[root_p], *root_node_q = &nodes[root_q];

    if(root_p == root_q)
        return;

    root_node_p->sons.erase(remove(root_node_p->sons.begin(), root_node_p->sons.end(), p), root_node_p->sons.end());
    //https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
    root_node_q->sons.push_back(p);
    nodes[p].root = root_q;
    
    return;
}

void print_node(int p)
{
    int sum = 0;
    node *the_node = &nodes[nodes[p].root];
    for(int e:the_node->sons)
    {
        sum += e;
    }
    cout << the_node->sons.size() << " " << sum << endl;

    //node *the_node = &nodes[p];

    //cout << "node father = " << the_node->father << endl;
    //cout << "node num = " << the_node->num << endl;
    //cout << "node sum = " << the_node->sum << endl;
    //for(int e:the_node->son)
    //    cout << "node son = " << e << endl;

    return;
}

void solve_problem(int n, int m)
{
    initial(n);
    while(m--)
    {
        int op, p, q;
        cin >> op;
        switch(op)
        {
            case 1:
                cin >> p >> q;
                unions(p, q);
                break;
            case 2:
                cin >> p >> q;
                moves(p, q);
                break;
            case 3:
                cin >> p;
                print_node(p);
                break;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while(cin >> n >> m)
    {
        solve_problem(n, m);
    }

    //cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

