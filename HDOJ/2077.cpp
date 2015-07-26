////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-09 23:26:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2077
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int f(int n)
{
	int i;
	__int64 sum=1;
	for(i=1;i<n;i++)
	sum*=3;
	sum+=1;
	return sum;
}
int main()
{
	int t,n;
	while(cin>>t)
	while(t--)
	{
	   cin>>n;
	   cout<<f(n)<<endl;
	}
	return 0;
}