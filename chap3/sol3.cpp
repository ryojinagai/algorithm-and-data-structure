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
  int min_second = -1;
  for (int i = 0; i < N; ++i) {
    if (min > a[i] or min == -1) {
      min_second = min;
      min = a[i];
    } else if (min_second > a[i] or min_second == -1) {
      min_second = a[i];
    }
  }

  cout << min << min_second << endl;
}