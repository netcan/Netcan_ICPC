/*************************************************************************
    > File Name: 1020.cpp
    > Author: Netcan
    > Mail: 1469709759@qq.com 
    > Created Time: 2015/5/1 16:30:17
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Process {
	int A,E;
	bool operator<(const Process &a) const {
		if(this->A != a.A)
			return this->A < a.A;
		else
			return this->E < a.E;
	}
} process[1004];

int main() {
	int N;
	while(scanf("%d", &N)==1) {
		for(int i=0; i<N; ++i)
			scanf("%d%d", &process[i].A, &process[i].E );
		sort(process, process+N);
//		for(int i=0; i<N; ++i)
//			printf("%d %d\n", process[i].A, process[i].E );
		int w=0,e=0;
		int endt = process[0].A;
		for(int i=0; i<N; ++i) {
			if(process[i].A < endt) {
				e += process[i].E;
				w += (endt-process[i].A);
				endt+=process[i].E;
			}
			else {
				e += process[i].E;
				endt=process[i].A+process[i].E;
			}
		}
		printf("%.4lf\n", (w+e)/(1.0*N));


	}
}

