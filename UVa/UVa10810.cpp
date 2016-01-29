//done
#include <iostream>
#define sum 500000
using namespace std;
/*
void swapx(long long &a,long long &b)
{
    long long temp = a;
    a = b;
    b = temp;
}
*/
long long total;
long long buf[sum];
void merge(int l,int r,long long arr[])
{
    if(l == r)
        return;
    int m = (r + l) / 2;
    merge(l, m, arr);
    merge(m + 1, r, arr);
    int lptr = l, rptr = m + 1, ptr = l;
    while(lptr < m + 1 || rptr < r + 1)
    {
        while(lptr < m + 1 && rptr < r + 1)
        {
            if(arr[lptr] > arr[rptr])
            {
                buf[ptr] = arr[rptr];
                rptr++;     ptr++;
                if(rptr - ptr > 0)
                    total += rptr - ptr;
            }
            else
            {
                buf[ptr] = arr[lptr];
                lptr++;     ptr++;
                if(lptr - ptr > 0)
                    total += lptr - ptr;
            }
        }
        if(lptr < m + 1)
        {
            buf[ptr] = arr[lptr];
            lptr++;     ptr++;
            if(lptr - ptr > 0)
                total += lptr - ptr;
        }
        else
        {
            buf[ptr] = arr[rptr];
            rptr++;     ptr++;
            if(rptr - ptr > 0)
                total += rptr - ptr;
        }
    }
    for(int i = l;i <= r;i++)
    {
        arr[i] = buf[i];
    }
}
int main()
{
    int n;
    while(cin >> n)
    {
        if(!n)
            break;

        total = 0;
        //int total = 0;
        long long arr[n];
        for(int i = 0;i < n;i++)
        {
            cin >> arr[i];
        }
        merge(0, n - 1,arr);
        //for(int i = 0;i < n;i++)
            //cout << buf[i] << " ";
          cout << total << endl;
    }
    return 0;
}
