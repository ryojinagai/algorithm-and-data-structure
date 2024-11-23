#include <iostream>
#include <vector>
using namespace std;

// int 型を vector 型に変換
// bit: 集合を表す整数
// N: 何個のものについて考えているか
vector<int> IntegerToVector(int bit, int N) {
  vector<int> S;
  for (int i = 0; i < N; ++i) {
    if (bit & (1 << i)) {
      S.push_back(i);
    }
  }
  return S;
}

int main() {
  // 入力
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  // bit 全探索
  bool exist = false;
  for (int bit = 0; bit < (1 << N); ++bit) {
    // どれを選ぶか
    vector<int> S = IntegerToVector(bit, N);

    // 部分集合に対応する総和
    int sum = 0;
    for (int i : S)
      sum += a[i];

    // 判定
    if (sum == W)
      exist = true;
  }

  if (exist)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}