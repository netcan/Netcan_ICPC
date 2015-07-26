#include <stdio.h>

static int month_r[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
static int month_p[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
static const int d_p=365;
static const int d_r=366;

int is_runy(int y)
{
	if((y%4 ==0 && y%100!=0) || y%400==0)
		return 1;
	else return 0;
}
int days(int y,int m)
{
	y+=1899;
	int d=0;
	if(is_runy(y))
		for(int i=1;i<=m;i++)
			d+=month_r[i];
	else
		for(int i=1;i<=m;i++)
			d+=month_p[i];
	return d;
}
int y_days(int y)
{
	if(y==0)
		return 0;
	y+=1899;
	int d=0;
	for(int i=1900;i<=y;i++)
		if(is_runy(i))
			d+=d_r;
		else
			d+=d_p;
	return d;
}


int main()
{
	int N=0,y=1,m=1,d=0;
	int wdays[8]={0};
	scanf("%d",&N);
	while(y<=N)
	{
		d=y_days(y-1)+days(y,m-1);
		wdays[(d+13)%7+1]++;
//		printf("d=%d m=%d\n",d,m);
		m++;
		if(m%12==0)
		{
			d=y_days(y-1)+days(y,m-1);
			wdays[(d+13)%7+1]++;
			m=1;
			y++;
		}
	}
	printf("%d %d %d %d %d %d %d",wdays[7],wdays[1],wdays[2],wdays[3],wdays[4],wdays[5],wdays[6]);



}

