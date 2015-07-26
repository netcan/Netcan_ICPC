#include <stdio.h>
#include <stdlib.h>
int main(void)
{ 
	int x,y,num=0;
	char z[5];
	char opt;
	while(scanf("%d%c%d=%s",&x,&opt,&y,z)!=EOF)
	{
		if(z[0]=='?')
			continue;
		if(opt == '+')
			if(x+y == atof(z)) num++;
		if( opt == '-' )
			if(x-y ==atof(z)) num++;
		}
	printf("%d\n",num);
	return 0;
}
