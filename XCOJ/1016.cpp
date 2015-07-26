#include <stdio.h>
#include <string.h>

struct b {
	int x,y;
	int stat;
} b;

int main()
{
	int W,H,B;
	static int bomb[1002][1002];
	int bs=0;
	while(scanf("%d %d %d",&W,&H,&B)!=EOF)
	{
		if(W==0 && H==0 && B==0)
			break;
		for(int i=0;i<B;i++)
		{
			scanf("%d %d",&b.x,&b.y);
			bomb[b.y][b.x]=9;
		}
		// operate
		for(int j=1;j<=H;j++)
			for(int i=1;i<=W;i++)
			{	
				if(bomb[j][i]==9)
				{	
					for(b.y=j-1;b.y<=j+1;b.y++)
						for(b.x=i-1;b.x<=i+1;b.x++)
							if(bomb[b.y][b.x]!=9)
								bomb[b.y][b.x]++;

				}

			}

		// display bombs
		for(int j=1;j<=H;j++)
		{
			for(int i=1;i<=W;i++)
			{
				if(bomb[j][i]==9)
					printf("*");
				else
					printf("%d",bomb[j][i]);
			}
			printf("\n");
		}	
		for(int j=0;j<=H+1;j++)
			for(int i=0;i<=W+1;i++)
				bomb[j][i]=0;
		printf("\n");
	}
}

