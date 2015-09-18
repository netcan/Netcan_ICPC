/*************************************************************************
	> File Name: 1251.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-09-18 五 08:28:54 CST
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
const int MAX_C = 26;

struct Trie {
	Trie *next[MAX_C];
	int v;
	Trie() {
		for(int i=0; i<MAX_C; ++i) next[i] = NULL;
	}
};

// Trie root;
Trie *root = new Trie;

void createTrie(const string &str) {
	Trie *p = root, *q;
	for(int i=0; i<str.length(); ++i) {
		int id = str[i] - 'a';
		if(p->next[id] == NULL) {
			q = new Trie;
			q->v = 1;
			p->next[id] = q;
			p = p->next[id];
		}
		else {
			++(p->next[id]->v);
			p = p->next[id];
		}
	}
	// p->v = -1; // 结尾
}


int findTrie(const string &w) {
	// cout << w << endl;
	Trie *p = root;
	for(int i=0; i<w.length(); ++i) {
		int id = w[i] - 'a';
		p = p->next[id];
		if(p == NULL) return 0; // 空集，则不存在以此为前缀的串
	}
	return p->v; // 此字符串是字符集某串的前缀
}

void freeTrie(Trie *p) { // 释放内存
	if(p == NULL) return;
	for(int i=0; i<MAX_C; ++i) freeTrie(p->next[i]);
	delete p;
}

void solve() {

}

int main()
{
#ifdef Oj
	freopen("1251.in", "r", stdin);
#endif
	string word;
	while(getline(cin, word) && word!="")
		createTrie(word);

	int ans = 0;
	while(getline(cin, word)) {
		ans = findTrie(word);
		cout << ans << endl;
	}
	freeTrie(root);

	return 0;
}
