/*************************************************************************
	> File Name: 1109.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 11 May 2015 10:40:53 PM CST
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

string s1,s2;
void work(string mid,string last){
    int i,p;
    cout<<last[last.size()-1];
    p=mid.find(last[last.size()-1]);
    if(p>0) work(mid.substr(0,p),last.substr(0,p));
    if(p+1<=mid.size()-1) work(mid.substr(p+1,mid.size()-p),last.substr(p,last.size()-1-p));
}

int main(){
	while(cin >> s1 >> s2) {
		work(s1, s2);
		cout << endl;
	}
	return 0;
}
