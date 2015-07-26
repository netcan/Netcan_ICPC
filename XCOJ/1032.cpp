#include <stdio.h>
int main()
{
	int n=0,r=0,l=0;
	while(scanf("%d",&n)!=EOF)
	{
		r=0;
		l=0;
		if(n==0)
			break;
		while(n!=0 && n!=1)
		{
			r+=n/3;
			l=n/3;
			n=l+n%3;
			if(n==2)
			{
				r++;
				break;
			}
		}
		printf("%d\n",r);


	}
}

