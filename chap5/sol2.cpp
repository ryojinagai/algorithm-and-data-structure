#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// N個の正の整数 a0, a1, ..., aN-1 からいくつかを選んで総和を所望の整数 W に一致させることができるかどうかを判定する問題を O(NW) 時間でアルゴリズムを設計してください。
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // 入力
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  // DP
  vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
  dp[0][0] = true;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= W; ++j) {
      // a[i] を選ばない場合
      if (dp[i][j])
        dp[i + 1][j] = true;

      // a[i] を選ぶ場合
      if (j >= a[i] && dp[i][j - a[i]])
        dp[i + 1][j] = true;
    }
  }

  // 答え
  if (dp[N][W])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
