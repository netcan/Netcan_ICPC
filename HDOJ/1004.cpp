////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2014-11-23 11:20:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1004.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2014/11/23 10:39:40
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main() {
	int N;
	static char bc[1010][20];
	static char c[20];
	static int cn[1010];
	while(scanf("%d",&N)==1 && N) {
		memset(cn,0,N*sizeof(int));
		int count=0;
		int i,j,maxn=0,max=0;
		for(i=0;i<N;i++){
			scanf("%s",c);
			if(count==0) {
				memcpy(bc[count],c,strlen(c));
//				cn[count]++;
				count++;
			}
			for(j=0;j<count;j++){
				if(strcmp(c,bc[j])==0)
					break;
			}
			
			if(j==count) {
				memcpy(bc[count],c,strlen(c));
				cn[count]++;
				count++;
			}
			else	cn[j]++;
		}
		for(int k=0;k<count;k++) {
			if(k==0){
				max=cn[0];
				maxn=k;
			}
			if(cn[k]>max){
				max=cn[k];
				maxn=k;
			}
		}
		printf("%s\n",bc[maxn]);

	}
	return 0;
}
