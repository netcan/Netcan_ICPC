/*************************************************************************
	> File Name: 2718.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-08-30 日 22:03:39 CST
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

int N, data[15];
int ans;
int ord1[7];
int ord2[7];
bool visited[15];


void dfs(int i, int id) {
	if(i >= N/2 && id == 1) {
		// 枚举第二个数
		dfs(0, 2);
		return;
	}
	int end = N/2 + N%2;

	if(i >= end  && id == 2) { // 奇数
		// 显示
		// for(int i=0; i<N/2; ++i)
			// cout << ord1[i] << " ";
		// cout << "||";
		// for(int i=0;i<end; ++i)
			// cout << ord2[i] << " ";
		// cout << endl;
		// 计算
		int a=0, b=0;
		for(int i=0; i<N/2; ++i) {
			a = a*10 + data[ord1[i]];
			b = b*10 + data[ord2[i]];
		}
		if(N&1) b = b*10 + data[ord2[N/2]];
		ans = min(ans, abs(a-b));
		return;
	}


	for(int k=0; k<N; ++k) {// 枚举
		if(i>0 && id==1 && data[ord1[0]]==0) return; // 前导０则回溯
		if(i>0 && id==2 && data[ord2[0]]==0) return;

		if(!visited[k]) {
			visited[k] = true;
			if(id == 1) ord1[i] = k;
			else ord2[i] = k;
			dfs(i+1, id);
			visited[k] = false;
		}
	}
}



void solve() {
	int T;
	cin >> T;
	string s;
	getchar();
	while(T--) {
		getline(cin, s);
		N = 0;
		for(int i=0; i<s.length(); ++i) if(s[i] != ' ') data[N++] = s[i] - '0';
		if(N==10) { // 已知
			cout << 247 << endl;
			continue;
		}
		// for(int i=0; i<N; ++i) cout << data[i] << endl;
		ans = 1<<30;
		memset(visited, 0, sizeof(visited));
		dfs(0, 1); // 开始枚举第一个数
		cout << ans << endl;

	}

}

int main()
{
#ifdef Oj
	freopen("2718.in", "r", stdin);
#endif
	solve();
	return 0;
}
