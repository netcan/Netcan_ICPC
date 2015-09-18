/*************************************************************************
	> File Name: 1305.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-18 五 22:42:11 CST
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
	Trie *next[2];
	int cnt;
	Trie() {
		memset(next, 0, sizeof(next));
		cnt = 0;
	}
} *root;

bool flag = true;

void createTrie(const string &b) {
	Trie *p = root, *q;
	for(int i=0; i<b.length(); ++i) {
		int x = b[i] - '0';
		if(p->next[x] == NULL) { // 不存在
			q = new Trie;
			q->cnt = 1;
			p->next[x] = q;
			p = q;
		}
		else { // 存在
			if(((i==b.length() - 1) && p->next[x]) || p->next[x]->cnt == -1) flag = false; // 此串是字符串集中某串前缀或字符串集中某串是该串前缀
			++p->next[x]->cnt;
			p = p->next[x];
		}
	}
	p->cnt = -1;
}

void freeTrie(Trie *p) {
	if(p == NULL) return;
	for(int i=0; i<2; ++i) freeTrie(p->next[i]);
	delete p;
}


void solve() {
	string bin;
	root = new Trie;
	int t = 0;
	while(cin >> bin) {
		if(bin == "9") {
			if(flag) printf("Set %d is immediately decodable\n", ++t);
			else printf("Set %d is not immediately decodable\n", ++t);
			flag = true;
			freeTrie(root);
			root = new Trie;
		}
		else createTrie(bin);
	}

}

int main()
{
#ifdef Oj
	freopen("1305.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	solve();
	return 0;
}
