#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, v;
  cin >> N >> v;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  // 線形探索
  int counter = 0;
  for (int i = 0; i < N; ++i) {
    if (a[i] == v) {
      ++counter;
      // break;
    }
  }

  cout << counter << endl;
}