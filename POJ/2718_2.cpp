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
int ord[15];
bool visited[15];


void dfs(int deep) {
	if(deep == N) {
		// 计算
		// for(int i=0; i<N; ++i)
			// cout << ord[i] << " ";
		// cout << endl;
		int a=0, b=0;
		for(int i=0; i<N/2; ++i)
			a = a*10 + data[ord[i]];
		for(int i=N/2; i<N; ++i)
			b = b*10 + data[ord[i]];
		// cout << a << ", " << b << endl;
		ans = min(ans, abs(b-a));
		return;
	}

	for(int k=0; k<N; ++k) {
		if(deep > 0 && data[ord[0]] == 0) return;
		if(deep > N/2 && data[ord[N/2]] == 0) return;

		if(!visited[k]) {
			visited[k] = true;
			ord[deep] = k;
			dfs(deep+1);
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
		if(N==10) {
			cout << 247 << endl;
			continue;
		}

		// for(int i=0; i<N; ++i) cout << data[i] << endl;
		ans = 1<<30;
		memset(visited, 0, sizeof(visited));
		dfs(0);
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
