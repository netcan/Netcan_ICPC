#include<stdio.h>

void Init(unsigned int, int * s);
void MoveTree(unsigned int, unsigned int, int * s);
void CountTree(unsigned int, int * s);

unsigned int  sum;

int main(void)
{
    unsigned int L, M;
    unsigned int start, end;
    scanf("%d%d", &L, &M);
        int s[L];
        Init(L,s);
        while(M--) {
            scanf("%d%d", &start, &end, s);
            MoveTree(start, end, s);
        }
        CountTree(L, s);
        printf("%d \n", sum);

    return 0;
}

void Init(unsigned int L, int * s)
{
    for(int i = 0; i <= L; i++) {
        s[i] = 1;
    }

    sum = 0;
}

void MoveTree(unsigned int start, unsigned int end, int * s)
{
    for(int i = start; i <= end; i++) {
        s[i] = 0;
    }
}

void CountTree(unsigned int L, int * s)
{
    for(int i = 0; i <= L; i++) {
        if(s[i] == 1)
            sum ++;
    }
}

