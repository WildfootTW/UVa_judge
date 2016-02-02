#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct
{
    int ar[16][16];
}Miners;

Miners p1, p2;
Miners *n=&p2, *p=&p1;

int cg (char c)
{
    if (c == 'M')return 1;
    if (c == 'F')return 2;
    return 3;
}

int val (int a, int b, int c)
{
    if (a==0 && b==0) return 1;
    if (a==0 && b!=0)
    {
        if (b==c) return 1;
        return 2;
    }
    if (a!=b && b!=c && a!=c) return 3;
    if (a!=b || b!=c) return 2;
    return 1;
}

int main ()
{
    memset (p1.ar, -1, sizeof (p1.ar));
    memset (p2.ar, -1, sizeof (p2.ar));
    p->ar[0][0] = 0;
    int qN;
    scanf ("%d\n", &qN);
    while (qN--)
    {
        char c;
        scanf ("%c", &c);
        int t=cg (c);
        int j, k;
        for (j = 0 ; j < 16 ; j ++)
            for (k = 0 ; k < 16 ; k ++)
                if (p->ar[j][k] != -1)
                {
                    int tt = p->ar[j][k] + val (j/4, j%4, t);
                    if (tt > n->ar[ (j % 4) * 4 + t][k])
                        n->ar[ (j % 4) * 4 + t ][k] = tt;
                    tt = p->ar[j][k] + val (k/4, k%4, t);
                    if (tt > n->ar[j][ (k % 4) * 4 + t ])
                        n->ar[j][ (k % 4) * 4 + t ] = tt;
                    p->ar[j][k] = -1;
                }
        swap(p, n);
    }
    int AC = -1, i, j;
    for (i = 0 ; i < 16 ; i ++)
        for (j = 0 ; j < 16 ; j ++)
            if (p->ar[i][j] > AC)
                AC = p->ar[i][j];

    printf("%d\n", AC);
    return 0;
}
