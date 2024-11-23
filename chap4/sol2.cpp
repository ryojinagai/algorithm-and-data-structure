#include <iostream>
#include <vector>
using namespace std;

// fibo(N) の答えをメモ化する配列
vector<long long> memo;

long long fibo(int N) {
  // ベースケース
  if (N == 0)
    return 0;
  else if (N == 1)
    return 0;
  else if (N == 2)
    return 1;

  // メモをチェック(すでに計算済みなら答えをリターンする)
  if (memo[N] != -1)
    return memo[N];

  // 答えをメモ化しながら、再帰呼び出し
  return memo[N] = fibo(N - 1) + fibo(N - 2) + fibo(N - 3);
}

int main() {
  // 標準入力でNを受け取る
  int N;
  cin >> N;
  // メモ化用配列を -1 で初期化する
  memo.assign(N + 1, -1);

  // fibo(N) を呼び出す
  int result = fibo(N);

  cout << result << endl;
}
