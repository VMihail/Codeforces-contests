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
      vector<string> a(n);
      string ss;
      getline(cin, ss);
      for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        a[i] = s;
      }
      int k;
      cin >> k;
      int level = n - 2;
      while (k--) {
        string name;
        int count;
        char symbol;
        cin >> name >> count >> symbol;
        for (int i = 0; i < count; i++) {
          for (int j = 0; j < (int) a[level].length(); j++) {
            if (a[level][j] == ' ') {
              a[level][j] = symbol;
            }
          }
          --level;
        }
      }
      for (auto &line : a) {
        for (auto el : line) {
          cout << el;
        }
        cout << '\n';
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
