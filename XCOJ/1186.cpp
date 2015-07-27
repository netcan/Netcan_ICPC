/*************************************************************************
    > File Name: b.c
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2015/1/31 19:28:05
 ************************************************************************/
 
#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
 
 
int main()
{
    priority_queue<int, vector<int>,greater<int> > que;
    int n;
    while(scanf("%d",&n) == 1) {
    int sum = 0;
        while(!que.empty())
            que.pop();
        int data = 0;
        for(int i=0; i<n; ++i) {
            scanf("%d",&data);
            que.push(data);
        }
 
        if(n == 1) {
            printf("0\n");
            continue;
        }
 
        while(!que.empty() && --n) {
            int t = que.top();
            que.pop();
            t += que.top();
            que.pop();
            sum+=t;
            que.push(t);
             
        }
 
        printf("%d\n",sum);
    }
    return 0;
}
