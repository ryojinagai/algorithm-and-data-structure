#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];
  // 計算量 O(2^n)
  bool complted_flag = false;
  int counter = 0;
  while (complted_flag) {
    for (int i = 0; i < N; ++i) {
      if (a[i] % 2 == 0) {
        a[i] = a[i] / 2;
      } else {
        complted_flag = true;
      }
    }
    ++counter;
  }
  cout << counter << endl;
}
