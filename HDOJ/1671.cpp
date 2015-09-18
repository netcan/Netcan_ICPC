/*************************************************************************
	> File Name: 1671.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-18 五 19:19:47 CST
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

const int MAX_N = 10;
struct Trie {
	Trie *next[MAX_N];
	// char cnt;
	int cnt;
	Trie() {
		cnt = 0;
		memset(next, 0, sizeof(next));
	}
};
Trie *root;

int t, n;
bool flag;

void createTrie(const string &phone) {
	Trie *p = root, *q;
	int x;
	for(int i=0; i<phone.length(); ++i) {
		x = phone[i] - '0';
		if(p->next[x] == NULL) {
			q = new Trie;
			q->cnt = 1;
			p->next[x] = q;
			p = q;
		}
		else {
			if((i == phone.length()-1 && p->next[x]) || p->next[x]->cnt == -1) flag = true; // 此串是字符串集中某串前缀或者字符串集中已有此串前缀
			++p->next[x]->cnt;
			p = p->next[x];
		}
	}
	p->cnt = -1; // 结尾
}


void freeTrie(Trie *p) {
	if(p == NULL) return;
	for(int i=0; i<MAX_N; ++i) freeTrie(p->next[i]);
	delete p;
}


void solve() {
	string phone;
	cin >> t;
	while(t--) {
		cin >> n;
		root = new Trie;
		flag = false;
		for(int i=0; i<n; ++i) { // 读取数值
			cin >> phone;
			if(flag) continue;
			createTrie(phone);
		}

		if(flag) cout << "NO" << endl;
		else	cout << "YES" << endl;
		freeTrie(root);
	}
}

int main()
{
#ifdef Oj
	freopen("1671.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	solve();
	return 0;
}
