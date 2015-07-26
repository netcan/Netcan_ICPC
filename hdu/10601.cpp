////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-11 20:43:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1060
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1632KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: 1060.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 11 May 2015 08:28:54 PM CST
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
//	Éè n^n = x * 10^l£¬Ôò l = log10(n^n) = nlog10(n)
//	Ôò LD = n^n / 10^l = 10^(nlog10n) / 10^l = 10^(nlog10n - l);
	int T;
	int N;
	cin >> T;
	while(T--) {
		cin >> N;
		long long l = N*log10(N);
		cout << (int)pow(10, N*log10(N) - l) << endl;
	}

	return 0;
}