////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-11 10:48:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1009
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1648KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1009.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 11 May 2015 10:32:21 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <sstream>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <stack>
#include <set>
#include <numeric>
#include <utility>
#include <cstring>
using namespace std;
struct JF {
	int j, f;
	double a;
	bool operator < (const JF &b) const {
		return b.a < this->a;
	}
};

int main()
{
	vector<JF> JFs;
	int M, N;
//	freopen("1009.data", "r", stdin);
	while(cin >> M >> N && !(M==-1 && N==-1)) {
		JF tmp;
		for(int i=0; i<N; ++i) {
			cin >> tmp.j >> tmp.f;
			tmp.a = tmp.j*1.0/tmp.f*1.0;
			JFs.push_back(tmp);
		}
		sort(JFs.begin(), JFs.end());
		double earn = 0.0;

		// for(int i=0; i<N; ++i) {
			// printf("J=%d F=%d a=%lf\n", JFs[i].j, JFs[i].f, JFs[i].a);

		// }


		for(int i=0; i<N; ++i) {
			if(JFs[i].f < M) {
				earn += JFs[i].j;
				M-=JFs[i].f;
			}
			else {
				earn +=(double) M*JFs[i].a;
				break;
			}
		}
		printf("%.3lf\n", earn);
		JFs.clear();
	}


	return 0;
}