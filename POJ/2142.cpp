/*************************************************************************
	> File Name: 2142.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-20 四 14:56:35 CST
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

int extgcd(int a, int b, int &x, int &y) {
	int d = a;
	if(b!=0) {
		d = extgcd(b, a%b, y, x);
		y -= (a/b)*x;
	}
	else  {
		x = 1; y = 0;
	}
	return d;
}


void solve() {
	cin.sync_with_stdio(false);
	int a, b, c;
	while(cin >> a >> b >> c) {
		if(a == b && b == c && c == 0)
			break;
		int x, y;
		int d = extgcd(a,b,x,y);
		a/=d;
		b/=d;
		x*=c/d;
		y*=c/d;
		while(abs(x) + abs(y) > abs(x+b) + abs(y-a)) {x+=b; y-=a;} // 数量和最小
		while(abs(x) + abs(y) > abs(x-b) + abs(y+a)) {x-=b; y+=a;}
		while(abs(x)+abs(y)  == abs(x+b)+abs(y-a) && abs(a*x) + abs(b*y) > abs(a*(x+b)) + abs(b*(y-a))) {x+=b; y-=a;} // 质量最小
		while(abs(x)+abs(y)  == abs(x-b)+abs(y+a) && abs(a*x) + abs(b*y) > abs(a*(x-b)) + abs(b*(y+a))) {x-=b; y+=a;}
		printf("%d %d\n", abs(x), abs(y));

	}
}

int main()
{
#ifdef Oj
	freopen("2142.in", "r", stdin);
#endif
	solve();
	return 0;
}
