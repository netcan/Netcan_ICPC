/*************************************************************************
    > File Name: 2010.cpp
      > Author: Netcan
      > Blog: http://www.netcan.xyz
      > Mail: 1469709759@qq.com
      > Created Time: 2015-10-31 六 16:28:03 CST
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

int N, C, F;
pair<int, int> cows[100005]; // first成绩，second补助
int lower[100000+5]; // 以成绩<牛i为中位数的学费和
int upper[100000+5]; // 以成绩>牛i为中位数的学费和

void solve() {
    sort(cows, cows+C);
    memset(lower, 0x3f, sizeof(lower));
    memset(upper, 0x3f, sizeof(upper));
    int median = N/2;
    // 求出lower[i]
    {
        priority_queue<int> que;
        int total = 0;
        for(int i=0; i<C; ++i) {
            if(que.size() == median) lower[i] = total; // 保证i前面有N/2个学生
            que.push(cows[i].second);
            total += cows[i].second;
            if(que.size() > median) { // 保证i后面有N/2个学生，多了将所需补助最大的出队。
                total -= que.top();
                que.pop();
            }
        }
    }

    // 求出upper[i]
    {
        priority_queue<int> que;
        int total = 0;
        for(int i=C-1; i>=0; --i) {
            if(que.size() == median) upper[i] = total; // 保证i后面有N/2个学生
            que.push(cows[i].second);
            total+=cows[i].second;
            if(que.size() > median) { // 保证i后面有N/2个学生，多了将所需补助最大的出队。
                total -= que.top();
                que.pop();
            }
        }
    }


    // 求解
    int result = -1;
    for(int i=C-1; i>=0; --i)
        if(lower[i] + upper[i] + cows[i].second <= F) {
            result = cows[i].first;
            break;
        }
    cout << result << endl;

}

int main()
{
#ifdef Oj
    freopen("2010.in", "r", stdin);
#endif
    cin.sync_with_stdio(false);
    cin >> N >> C >> F;
    for(int i=0; i<C; ++i)
        cin >> cows[i].first >> cows[i].second;
    solve();
    return 0;
}
