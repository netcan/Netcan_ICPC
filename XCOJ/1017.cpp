#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int m(char * str)
{
	int len=strlen(str);
	int len_end;
	int n,r=0;
	len_end=len/2;
	for(n=0;n<len_end;n++)
		r+=abs(str[n]-str[len-n-1]);
	r*=2;
	return r;
}

int main()
{
	static char str[10000];
	unsigned int N,M;
	scanf("%d %d",&N,&M);
	while(N-->0)
	{
		scanf("%s",str);
		if(m(str)<=M)
			printf("%s %d\n",str,m(str));
	}
}

