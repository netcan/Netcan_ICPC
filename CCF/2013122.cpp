/*************************************************************************
	> File Name: 2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-10 四 20:55:32 CST
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
// 出版语言1-出版社3-出版社编号5-识别码1
char isbn[15];

void solve() {
	cin >> isbn;
	int k=1;
	int res = 0;
	for(int i=0; i<11; ++i) {
		if(isbn[i] == '-') continue;
		res = res + (isbn[i] - '0')*k;
		++k;
	}
	char flag;
	if(res % 11 == 10) flag = 'X';
	else flag = res%11 + '0';
	if(flag == isbn[12])
		cout << "Right" << endl;
	else {
		for(int i=0; i<12; ++i) cout << isbn[i];
		cout << flag << endl;
	}

}

int main()
{
#ifdef Oj
	freopen("2.in", "r", stdin);
#endif
	solve();
	return 0;
}
