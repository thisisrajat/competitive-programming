#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <utility>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <list>
#include <memory.h>

using namespace std;

int a[1234];

int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a[i + 1];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  cout << a[k] << endl;
}