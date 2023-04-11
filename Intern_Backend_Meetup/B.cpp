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
      int n, m;
      cin >> n >> m;
      vector<long long> a(n);
      vector<long long> b(m);
      for (int i = 0; i < n; i++) {
        cin >> a[i];
      }
      for (int j = 0; j < m; j++) {
        cin >> b[j];
      }
      vector<long long> newA;
      newA.push_back(a[n - 1]);
      long long mx = a[n - 1];
      for (int i = n - 2; i >= 0; i--) {
        if (mx >= a[i]) {
          continue;
        }
        newA.push_back(a[i] - mx);
        mx = max(mx, a[i]);
      }
      sort(newA.begin(), newA.end());
      sort(b.begin(), b.end());
      int j = (int) newA.size() - 1;
      int result = 0;
      for (int i = m - 1; i >= 0 and j >= 0; i--) {
        if (b[i] <= newA[j]) {
          ++result;
          --j;
        }
      }
      cout << result << '\n';
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
