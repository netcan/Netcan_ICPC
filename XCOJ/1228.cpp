/*************************************************************************
	> File Name: 1002.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan666.com
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-12-20 日 14:24:40 CST
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

char s[100];
int T;
void solve() {
	int sum = 0;
	for(int i=strlen(s)-1; i>=0; --i) sum += (s[i]-'A'+1);
	printf("%s\n", sum%T==0?"STAY":"BYE");
}

int main()
{
#ifdef Oj
	freopen("E.in", "r", stdin);
#endif
	while(cin >> s >> T) {
		solve();
	}
	return 0;
}
