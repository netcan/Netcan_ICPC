/*************************************************************************
	> File Name: 2222_2.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-29 四 17:29:45 CST
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

struct Trie {
	static const int max_L = 500010;
	static const int max_c = 26;
	int cnt[max_L]; // 单词结尾节点统计该单词个数
	int fail[max_L]; // fail指针
	int next[max_L][max_c];
	int root, L; // 根指针，当前最大有效节点指针
	int newnode() {
		for(int i=0; i<max_c;++i)
			next[L][i] = -1;
		cnt[L++] = 0;
		return L-1;
	}
	void init() {
		L = 0;
		root = newnode();
	}

	void insert(const char *s) { // 建立Trie树
		int len = strlen(s);
		int p = root;
		for(int i=0; i<len; ++i) {
			int id = s[i] - 'a';
			if(next[p][id] == -1) next[p][id] = newnode();
			p = next[p][id];
		}
		++cnt[p];
	}

	void build() {
		queue<int> que;
		fail[root] = root; // 根fail指针指向根，避免多余的判断
		for(int i=0; i<max_c; ++i) // 处理root的后继节点，都指向root
			if(next[root][i] == -1) next[root][i] = root;
			else {
				fail[next[root][i]] = root;
				que.push(next[root][i]);
			}

		while(!que.empty()) {
			int p = que.front(); que.pop();

			for(int i=0; i<max_c; ++i)
				if(next[p][i] == -1) next[p][i] = next[fail[p]][i]; // 方便后面match失配的fail转移
				else {
					fail[next[p][i]] = next[fail[p]][i];
					que.push(next[p][i]);
				}
		}
	}

	int match(const char *s) {
		int len = strlen(s);
		int p = root;
		int res = 0;
		for(int i=0; i<len; ++i) {
			int id = s[i] - 'a';
			p = next[p][id];
			int tmp = p;
			while(tmp != root) {
				res += cnt[tmp];
				cnt[tmp] = 0;
				tmp = fail[tmp];
			}
		}
		return res;
	}

};

int T, n;
char s[1000005];
Trie ac;

void solve() {
	ac.build();
	cout << ac.match(s) << endl;
}

int main()
{
#ifdef Oj
	freopen("2222.in", "r", stdin);
#endif
	// cin.sync_with_stdio(false);
	// cin >> T;
	scanf("%d", &T);
	char in[55];
	while(T--) {
		ac.init();
		// cin >> n;
		scanf("%d", &n);
		for(int i=0; i<n; ++i) {
			// cin >> in;
			scanf("%s", in);
			ac.insert(in);
		}
		// cin >> s;
		scanf("%s", s);
		solve();
	}
	return 0;
}
