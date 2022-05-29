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
#include <vector>

#define int int32_t

typedef int64_t int64;
typedef uint64_t uint64;

using namespace std;

class ArraysUtils {
public:
    template <typename T>
    static void printArray(const vector<T>& array) {
      for (auto el : array) {
        cout << el << ' ';
      }
      cout << '\n';
    }

    template <typename T>
    static vector<T> nextArray(size_t len) {
      vector<T> result(len);
      for (size_t i = 0; i < len; i++) {
        cin >> result[i];
      }
      return result;
    }
};

namespace SegTree {

    class SegmentTree {
    private:
        vector<int64> tree;
        int size;
        const int64 NEUTRAL = 0LL;

        void init(int len) {
          size = 1;
          while (size < len) {
            size <<= 1;
          }
          tree.assign(2 * size - 1, NEUTRAL);
        }

        void build(const vector<int> &array, int nodeNow, int left, int right) {
          if (right == left + 1) {
            if (nodeNow < tree.size() and left < array.size()) {
              tree[nodeNow] = array[left];
            }
            return;
          }
          int middle = ((right - left) >> 1) + left;
          int child = (nodeNow << 1) + 1;
          build(array, child, left, middle), build(array, child + 1, middle, right);
          tree[nodeNow] = tree[child] + tree[child + 1];
        }

        void build(const vector<int> &array) {
          build(array, 0, 0, size);
        }

    public:
        explicit SegmentTree(int len) {
          init(len);
        }

        explicit SegmentTree(const vector<int> &array) {
          init(array.size());
          build(array);
        }

        void set(int i, int64 value) {
          int index = size - 1 + i;
          tree[index] = value;
          while (index > 0) {
            index = (index - 1) >> 1;
            int child = (index << 1) + 1;
            tree[index] = tree[child] + tree[child + 1];
          }
        }

        int64 sum(int left, int right, int nodeNow, int leftNow, int rightNow) {
          if (leftNow >= left and rightNow <= right) {
            return tree[nodeNow];
          }
          if (leftNow >= right or rightNow <= left) {
            return NEUTRAL;
          }
          int middle = ((rightNow - leftNow) >> 1) + leftNow;
          int child = (nodeNow << 1) + 1;
          return sum(left, right, child, leftNow, middle) +
                 sum(left, right, child + 1, middle, rightNow);
        }

        int64 sum(int left, int right) {
          return sum(left, right, 0, 0, size);
        }

        int64 get(int i) {
          return tree[size - 1 + i];
        }

        void printTree() {
          ArraysUtils::printArray(tree);
        }
    };
}

class SparseTable {
private:
    int size{};
    vector<vector<int>> table;
    const int NEUTRAL = INT32_MAX;

    void init(int n) {
      size = 1;
      while (size < n) {
        size <<= 1;
      }
      table.assign(log2(size), vector<int>(size, NEUTRAL));
    }

    void build(const vector<int>& array) {
      for (int i = 0; i < array.size(); i++) {
        table[0][i] = array[i];
      }
      for (int k = 1; k < log2(size); k++) {
        for (int i = 0; i < size; i++) {
          int j = i + pow(2, k - 1);
          if (j < size) {
            table[k][i] = ::min(table[k - 1][i], table[k - 1][j]);
          }
        }
      }
    }
public:
    explicit SparseTable(const vector<int>& array) {
      init(array.size());
      build(array);
    }

    int getMin(int left, int right) {
      int t = log2(right - left);
      return ::min(table[t][left], table[t][right - (1 << t)]);
    }

    void printTable() {
      for (const auto& line : table) {
        for (auto el : line) {
          cout << el << ' ';
        }
        cout << '\n';
      }
    }
};

class Solver {
private:
    void solveOne() {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> a(n, vector<int>(m));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cin >> a[i][j];
        }
      }
      int result = INT32_MIN;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          int row = i, col = j;
          int now = 0;
          while (row < n and col < m) {
            now += a[row++][col++];
          }
          row = i, col = j;
          while (row >= 0 and col >= 0) {
            now += a[row--][col--];
          }
          row = i, col = j;
          while (row < n and col >= 0) {
            now += a[row++][col--];
          }
          row = i, col = j;
          while (row >= 0 and col < m) {
            now += a[row--][col++];
          }
          result = max(result, now - 3 * a[i][j]);
        }
      }
      cout << result << '\n';
    }
public:
    void solve() {
      int t = 1;
      cin >> t;
      while (t--) {
        solveOne();
      }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  //freopen("input.txt", "r", stdin);
    (new Solver)->solve();
    return 0;
}
