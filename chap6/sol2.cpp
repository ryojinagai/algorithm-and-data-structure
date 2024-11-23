#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// N 個の異なる整数列 a0, a1, ..., aN−1 と b0, ..., bN−1, c0, c1, ..., cN−1が与えられます。ai < bj < ck を満たすような (ai, bj, ck) の組が何個あるかを O(N log N) で求めるアルゴリズムを設計してください。
// 解法アイディア aを固定して、bの組をカウントしていく。
int main() {
  int N;
  long long result = 0;
  cin >> N;
  vector<int> avector(N);
  vector<int> bvector(N);
  vector<int> cvector(N);
  for (int i = 0; i < N; ++i)
    cin >> avector[i];
  for (int i = 0; i < N; ++i)
    cin >> bvector[i];
  for (int i = 0; i < N; ++i)
    cin >> cvector[i];
  sort(avector.begin(), avector.end());
  sort(bvector.begin(), bvector.end());
  sort(cvector.begin(), cvector.end());

  for (int i = 0; i < N; ++i) {
    int taraget_b = bvector[i];
    long long a_distance = lower_bound(avector.begin(), avector.end(), taraget_b) - avector.begin();
    long long c_distance = N - (upper_bound(cvector.begin(), cvector.end(), taraget_b) - cvector.begin());
    result += a_distance * c_distance;
  }
  cout << result << endl;
}
