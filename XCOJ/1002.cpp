#include<stdio.h>
unsigned int loop(unsigned int num){
	unsigned int num_r=0,q=1,q_n=1;
	while(num/q>0)
		q*=10;
	q/=10;
	while(num>0)
	{
		num_r+=num%10*q;
		q/=10;
		num/=10;
	}
	return num_r;
}
int main(){
	unsigned int input;
	static unsigned int data[100000];

	int times,times_b;
	while(scanf("%d",&input)!=EOF)
	{

		times=0;
		data[0]=input;
		while(data[times]!=loop(data[times]))
			data[++times]=data[times-1]+loop(data[times-1]);	
		printf("%d\n",times);
		times_b=0;
		times--;
		while(times_b<=times)
			printf("%d--->",data[times_b++]);
		printf("%d\n",data[times+1]);
	}
}




