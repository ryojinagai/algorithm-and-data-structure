#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// どの 2 要素も互いに相異なる N 要素からなる整数列 a0, a1, ..., aN−1 が与えられます。i = 0, 1, ..., N−1 に対して、ai が他の aj (j ≠ i) の中で相対的に最小な値であるような i を O(N log N) で求めるアルゴリズムを設計してください。
// 例えば a = {12, 43, 7, 15, 9} のとき、答えは {2, 4, 0, 3, 1} です
int main() {
  // 標準入力のインターフェースは設けない。
  vector<int> original = {12, 43, 7, 15, 9};
  vector<int> goal(original.size());
  vector<int> sorted = original;
  sort(sorted.begin(), sorted.end());

  for (int i = 0; i < original.size(); ++i) {
    int target = original[i];
    int iter = lower_bound(sorted.begin(), sorted.end(), target) - sorted.begin();
    goal[i] = iter;
  }
  for (int t = 0; t < original.size(); ++t) {
    cout << goal[t] << endl;
  }
}
