/*************************************************************************
	> File Name: 2222.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: 2015-10-24 六 21:44:40 CST
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

int T;
int N;
char s[1000005];

struct Trie {
	int cnt; // 单词结尾节点统计单词个数
	Trie *fail; // 跳转指针fail
	Trie *next[26]; // 存放26个字母
	Trie() {
		cnt = 0; // 初始化
		fail = NULL;
		memset(next, 0, sizeof(next));
	}
} *root;

void insert(const char *s) { // 插入单词，构建Trie树
	Trie *p = root;
	int len = strlen(s);
	for(int i=0; i<len; ++i) {
		int id = s[i] - 'a';
		if(!p->next[id])
			p->next[id] = new Trie();
		p = p->next[id];
	}
	++p->cnt;
}

void build_AC() { // 第一个节点指向根节点
	Trie *p, *temp;
	queue<Trie*> que;
	que.push(root); // BFS建树
	while(!que.empty()) {
		p = que.front(); que.pop(); // 从根节点开始构建
		for(int i=0; i<26; ++i) {
			if(p->next[i]) {// 该节点后面有节点
				if(p == root) // 如果该节点是根节点，则后继节点为第一个子节点，fail指向根节点
					p->next[i]->fail = root;
				else { // 普通节点
					temp = p->fail;
					while(temp) { // 若p的跳转指针未指向根
						if(temp->next[i]) { // 如果跳转后的后继节点和p的后继节点一样，则p的后继节点fail指向跳转后的后继节点
							p->next[i]->fail = temp->next[i];
							break;
						}
						else
							temp = temp->fail; // 继续跳转
					}
					if(!temp) // 若跳转到根节点，则后继节点fail指向根节点
						p->next[i]->fail = root;
				}
				que.push(p->next[i]); // 后继节点入队
			}
		}
	}
}

int match(const char *s) {
	int res = 0;
	int len = strlen(s);
	Trie *p = root, *temp;
	for(int i=0; i<len; ++i) {
		int id = s[i] - 'a';
		while(!p->next[id] && p != root) p = p->fail; // 失配跳转
		p = p->next[id];
		if(!p) p=root; // 再次失配，跳转回根节点
		temp = p;
		while(temp != root && temp->cnt != -1) {
			res += temp->cnt; // 累加
			temp->cnt = -1; // 标记为已搜索过的节点，以防重复累加
			temp = temp->fail;
		}
	}
	return res;
}

void freeTrie(Trie *p) { // 释放AC自动机
	for(int i=0; i<26; ++i) if(p->next[i]) freeTrie(p->next[i]);
	delete p;
}

void solve() {
	build_AC();
	cout << match(s) << endl;
	free(root);
}

int main()
{
#ifdef Oj
	freopen("2222.in", "r", stdin);
#endif
	cin.sync_with_stdio(false);
	cin >> T;
	char keyword[10005];
	while(T--) {
		root = new Trie();
		cin >> N;
		for(int i=0; i<N; ++i) {
			cin >> keyword;
			insert(keyword);
		}
		cin >> s;
		solve();
	}
	return 0;
}
