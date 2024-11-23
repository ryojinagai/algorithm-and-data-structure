#include <iostream>
#include <vector>
using namespace std;

int main() {
  int K, N;
  cin >> K >> N;

  // 計算量 O(N^2)
  int counter = 0;

  for (int i = 1; i < K - 2; ++i) {
    for (int t = 1; t < K - i - 1; ++t) {
      int z = N - i - t;
      if (z >= 0 && z <= K) {
        ++counter;
      }
    }
  }

  cout << counter << endl;
}
