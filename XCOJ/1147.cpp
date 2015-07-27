#include <stdio.h>
int main()
{
    int L;
    static int height[100];
    static int h[100];
    int hx=0;
    int i,j,x,n,n_x;
    scanf("%d\n",&L);
    for(x=0;x<L;x++)
        scanf("%d",&height[x]);
    scanf("%d",&n);
    for(n_x=0;n_x<n;n_x++)
    {
        scanf("%d %d",&i,&j);
        i--;
        j--;
        for(x=i;x<=j;x++) {
            h[hx]+=height[x];
        }
        hx++;
    }
    for(int x2=0;x2<hx;x2++)
        printf("%d\n",h[x2]);
     
    return 0;
}
 
/**************************************************************
    Problem: 1147
    User: 2014218760
    Language: C++
    Result: 正确
    Time:0 ms
    Memory:948 kb
****************************************************************/
