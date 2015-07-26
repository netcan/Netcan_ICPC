////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-09 23:25:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2093
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1648KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 10005
typedef struct {
	char name[15];//name
	int ac;//ac的数量
	int time;//时间分数
}Stu;
int N,M;
Stu record[maxn];

int cmp_struct(const void* now,const void* next)
{
    Stu* Now = (Stu*)now;
    Stu* Next = (Stu*)next;//强制转换类型

    if(Now->ac == Next->ac){
        if(Now->time == Next->time)
            return strcmp(Now->name,Next->name);
        return (Now->time - Next->time);//时间从小到大排
    }
    return (Next->ac - Now->ac);
}
int main()
{
    int cnt = 0;

    memset(record,0,sizeof(record));
    scanf("%d%d",&N,&M);
    while(scanf("%s",record[cnt].name)!=EOF){
        int ac;
        char c;
        int time;//time表示AC之前提交了几次
        for(int i = 0 ; i < N ; i++){
            scanf("%d",&ac);
            if(ac > 0){
                record[cnt].ac++;
                record[cnt].time += ac;//ac的时间
            }
            if((c = getchar())=='('){
                scanf("%d",&time);
                getchar();
                record[cnt].time += time * M;
			}
		}
		cnt++;
    }
    qsort(record,cnt,sizeof(record[0]),cmp_struct);
    for(int i = 0 ; i < cnt ; ++i)
        printf("%-10s %2d %4d\n",record[i].name,record[i].ac,record[i].time);
    return 0;
}