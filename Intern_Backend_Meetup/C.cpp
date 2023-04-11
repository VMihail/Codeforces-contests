#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <utility>
#include <vector>

#define int int32_t

typedef int64_t int64;
typedef uint64_t uint64;

using namespace std;

class Solver {
private:
    void solveOne() {
      int n;
      cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '1') {
          a[i] = 1;
        } else {
          a[i] = -1;
        }
      }
      vector<int> pref(n, 0);
      pref[0] = a[0];
      for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + a[i];
      }
      int mn = -1;
      int mx = -1;
      int curMn = 0;
      int curMx = 0;
      cout << "-1 ";
      for (int i = 1; i < n; i++) {
        cout << (a[i] == -1 ? (pref[i] - curMx < 0 ? mx + 2 : -1) : (pref[i] - curMn > 0 ? mn + 2 : -1)) << ' ';
        if (pref[i - 1] < curMn) {
          curMn = pref[i - 1];
          mn = i - 1;
        }
        if (pref[i - 1] > curMx) {
          curMx = pref[i - 1];
          mx = i - 1;
        }
      }
    }
public:
//#define MultiTest
    void solve() {
      int t = 1;
#ifdef MultiTest
      cin >> t;
#endif
      while (t--) {
        solveOne();
      }
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef __llvm__
  freopen("input.txt", "r", stdin);
#endif
  (new Solver)->solve();
  return 0;
}
