#include <stdio.h>
unsigned int num[1000];
void quick(unsigned int *a,int i,int j) 
{ 
	int m,n,temp; 
	int k; 
	m=i; 
	n=j; 
	k=a[(i+j)/2];
	do { 
		while(a[m]<k&&m<j) m++;  
		while(a[n]>k&&n>i) n--; 
		if(m<=n) {
			temp=a[m]; 
			a[m]=a[n]; 
			a[n]=temp; 
			m++; 
			n--; 
			} 
	}while(m<=n); 
	if(m<j) quick(a,m,j);  
	if(n>i) quick(a,i,n); 
} 

int main(){
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		quick(num,0,n-1);
		if(n%2==0)
			printf("%.2f\n",((float)num[n/2-1]+(float)num[n/2])/2.0);
		else
			printf("%.2f\n",(float)num[n/2]);

	}
}
	

