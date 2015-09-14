/*************************************************************************
	> File Name: 2393.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-14 一 17:05:51 CST
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

int N, S; // 周数， 存储一周单价
int C[10005]; // 生产成本单价
int Y[10005]; // 需求量
typedef long long ll;

void solve() {
	ll res = 0; // 累计成本
	int store = 0; // 仓库量
	for(int i=0; i<N; ++i) {
		if(store > 0) { // 仓库有酸奶
			res+=store*S; // 计算储存费用
			if(Y[i] >= store) {Y[i]-=store; store = 0;} // 取出酸奶
			else {Y[i] = 0; store-=Y[i]; }
		}
		res += Y[i]*C[i]; // 计算该周生产酸奶的费用（可能为0，即不生产）
		if(i+1 < N  && C[i] + S < C[i+1]) { // 该周生产的酸奶+储存费比下周便宜
			store+=Y[i+1]; // 存储酸奶
			res+=Y[i+1]*C[i]; // 该周多生产的
		}
	}
	cout << res << endl;
}

int main()
{
#ifdef Oj
	freopen("2393.in", "r", stdin);
#endif
	cin >> N >> S;
	for(int i=0; i<N; ++i)
		cin >> C[i] >> Y[i];
	solve();
	return 0;
}
