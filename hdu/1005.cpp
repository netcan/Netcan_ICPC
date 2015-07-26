////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-11 13:12:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1005.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 11 May 2015 11:41:05 AM CST
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

int main()
{
	int A,B,N;
	int f[50];
	f[1] = 1;
	f[2] = 1;


	while(cin >> A >> B >> N && !(A==0 && B==0 && N==0)) {
		int T  = 2;
		for(int i=3; i<=49; ++i) {
			f[i] = (f[i-1] * A + f[i-2] * B)%7;
			if(f[i] == f[i-1] && f[i] == 1) {
				--T;
				break;
			}
			else ++T;
		}
//		for(int i=1; i<=49; ++i)
//			printf("f[%i] = %i, ", i, f[i]);
//		cout << endl;
//		cout << "T=" <<  T << endl;
		if(N%T==0)
			cout << f[T] << endl;
		else
			cout << f[N%T] << endl;


	}

	return 0;
}