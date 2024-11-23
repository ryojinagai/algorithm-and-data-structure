#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  // 線形探索
  int min = -1;
  int max = -1;
  int diff;
  for (int i = 0; i < N; ++i) {
    if (min > a[i] or min == -1) {
      min = a[i];
    }
    if (max < a[i] or max == -1) {
      max = a[i];
    }
  }
  diff = max - min;
  cout << diff << endl;
}