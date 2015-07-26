/*************************************************************************
	> File Name: 1006.cpp
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Mon 11 May 2015 10:59:15 PM CST
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

int n, m;
int su[5500], sn;
bool he[50001];
int num[5500];
void work (int x)
{
  int d = x;
  x += d;
  while (x <= 5e4)
    {
      he[x] = true;
      x += d;
    }
}

void calc (int x, int c)
{
  int p = 1;
  while (x > 1)
    {
      int count = 0;
      while (x % su[p] == 0 && x > 1)
	{
	  x /= su[p];
	  ++count;
	}
      num[p] += count * c;
      ++p;
    }
}

int main ()
{
  for (int i = 2; i <= 5e4; ++i)
    if (!he[i])
      work (i);
  for (int i = 2; i <= 5e4; ++i)
    if (!he[i])
      su[++sn] = i;
  scanf ("%d%d", &n, &m);
  for (int i = 0; i < m; ++i)
    calc (n - i, 1);
  for (int i = m; i > 0; --i)
    calc (i, -1);
  int ans = 0;
  for (int i = 1; i <= sn; ++i)
    if (num[i] > 0)
      ++ans;
  cout << ans << endl;
}
