////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-09 15:34:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2036
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 2036.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sat 09 May 2015 03:21:52 PM CST
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
#include <iomanip>
#include <cstring>
using namespace std;

struct point {
	int x, y;
} p[105];

double area_polygon(int n,point* p){
	double s1=0,s2=0;
	int i;
	for (i=0;i<n;i++)
		s1+=p[(i+1)%n].y*p[i].x,s2+=p[(i+1)%n].y*p[(i+2)%n].x;
	return fabs(s1-s2)/2;
}

int main()
{
	int n;
	while(cin >> n && n!=0) {
		for(int i=0; i<n; ++i)
			cin >> p[i].x >> p[i].y;
		printf("%.1f\n", area_polygon(n, p));

	}


	return 0;
}