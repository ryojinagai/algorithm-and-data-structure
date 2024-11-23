#include <iostream>
#include <vector>
using namespace std;
using std::to_string;

// 十進法表記で各桁の値が 7, 5, 3 のいずれかであり、かつ 7, 5, 3 がすべて一度以上は登場する整数を「753 数」とよぶことにします。正の整数 K が与えられたときに、K 以下の 753 数が何個あるかを求めるアルゴリズムを設計してください。
// ただし K の桁数を d として O(3^d) 程度の計算量を許容できるものとします。
// 計算量 O(1)
int main() {
  // 標準入力でKを受け取る
  int K;
  cin >> K;

  string K_string = to_string(K);
  int digit = K_string.length();
  int counter = 0;

  if (digit < 3) {
    counter = 0;
  } else {
    // 最初に0があるパターンは除く必要がある。
    int all_pattern = 3 * 2 * 1 * 10 ^ (digit - 3);
    cout << all_pattern << endl;
    int zero_start_counter = 0;
    if (digit > 3) {
      zero_start_counter = 3 * 2 * 1 * 1 * 10 ^ (digit - 4);
    }
    counter = all_pattern - zero_start_counter;
  }
  cout << counter << endl;
}
