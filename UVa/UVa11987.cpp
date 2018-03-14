// 
// WildfootW 2018
// https://github.com/Wildfoot
// Wrong Answer

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>
#include <algorithm>

#define INF 2147483647

using namespace std;

#define MAX 100001

struct node{
    int father, sum, num;
    vector<int> son;
};

node nodes[MAX];

int find_father(int p)
{
    if(nodes[p].father == p)
        return p;
//    p.father = find_father(nodes[p].father);
//    return p.father
    return find_father(nodes[p].father);
}

void update_upward(int index, int changed_sum, int changed_num)
{
    static int index_buffer = 0, changed_sum_buffer = 0, changed_num_buffer = 0;
    if(index_buffer == index)
    {
        changed_sum_buffer += changed_sum;
        changed_num_buffer += changed_num;
        return;
    }
    else
    {
        while(1)
        {
            node *the_node = &nodes[index_buffer];
            the_node->sum += changed_sum_buffer;
            the_node->num += changed_num_buffer;

            if(index_buffer == the_node->father)
                break;
            index_buffer = the_node->father;
        }
        index_buffer = index;
        changed_sum_buffer = changed_sum;
        changed_num_buffer = changed_num;
    }
    return;
}

void initial(int n)
{
    update_upward(0, 0, 0);
    for(int i = 0;i <= n;i++)
    {
        node *the_node = &nodes[i];
        the_node->father = i;
        the_node->sum = i;
        the_node->num = 1;
        the_node->son.clear();
    }
    return;
}
void unions(int p, int q)
{
    p = find_father(p);
    q = find_father(q);
    if(find_father(p) == find_father(q))
        return;

    node *node_p = &nodes[p], *node_q = &nodes[q];

    if(node_p->num < node_q->num)
    {
        swap(node_p, node_q);
        swap(p, q);
    }

    node_q->father = p;
    update_upward(p, node_q->sum, node_q->num);
    node_p->son.push_back(q);

    return;
}

void isolates(int p)
{
    node *node_p = &nodes[p];
    if(node_p->father == p)
    {
        if(node_p->son.empty())
            return;
        int node_new_father_index = node_p->son.back();
        node_p->son.pop_back();
        node *node_new_father = &nodes[node_new_father_index];

        update_upward(p, node_new_father->sum * -1, node_new_father->num * -1);
        //node_p->sum -= node_new_father->sum;
        //node_p->num -= node_new_father->num;
        node_new_father->father = node_new_father_index;

        while(!node_p->son.empty())
        {
            int e = node_p->son.back();
            node *node_son = &nodes[e];
            node_p->son.pop_back();

            update_upward(p, node_son->sum * -1, node_son->num * -1);
            //node_p->sum -= node_son->sum;
            //node_p->num -= node_son->num;
            node_son->father = e;

            unions(e, node_new_father_index);
        }
    }
    else
    {
        node *node_father = &nodes[node_p->father];
        node_father->son.erase(remove(node_father->son.begin(), node_father->son.end(), p), node_father->son.end());
        //https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
        update_upward(node_p->father, node_p->sum * -1, node_p->num * -1);
        //node_father->sum -= node_p->sum;
        //node_father->num -= node_p->num;
        node_p->father = p;

        while(!node_p->son.empty())
        {
            int e = node_p->son.back();
            node *node_son = &nodes[e];
            node_p->son.pop_back();

            update_upward(p, node_son->sum * -1, node_son->num * -1);
            node_p->sum -= node_son->sum;
            node_p->num -= node_son->num;
            node_son->father = e;

            unions(e, node_p->father);
        }
    }
    return;
}

//Move p to the set containing q
void moves(int p, int q)
{    
    if(find_father(p) == find_father(q))
        return;

    node *node_p = &nodes[p], *node_q = &nodes[q];

    isolates(p);
    unions(p, q);
    
    return;
}

void print_node(int p)
{
    update_upward(0, 0, 0);
    node *the_node = &nodes[find_father(p)];
    cout << the_node->num << " " << the_node->sum << endl;

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

    cout << "Time used = " << (double)clock() / CLOCKS_PER_SEC << endl;
    return 0;   
}

