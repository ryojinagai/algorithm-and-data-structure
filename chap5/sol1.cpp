#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

template <class T>
void chmax(T &a, T b) {
  if (a < b) {
    a = b;
  }
}
int main() {
  int a = 3;
  int b = 4;
  int c = 5;
  int day = 20;
  std::unordered_map<string, int> happiness_list =
      {
          {"a", 3},
          {"b", 4},
          {"c", 5}};
  std::unordered_map<int, string> happiness_list_keys =
      {
          {3, "a"},
          {4, "b"},
          {5, "c"}};
  // map<int, map<string, int>> dp;
  vector<int> dp;
  string selected_happiness;
  for (int i = 0; i < day; ++i) {
    if (i == 0) {
      int max = std::max({happiness_list["a"], happiness_list["b"], happiness_list["c"]});
      selected_happiness = happiness_list_keys[max];
      dp[i] = max;
    } else {
      if (selected_happiness == "a") {
        int max = std::max({happiness_list["b"], happiness_list["c"]});
        selected_happiness = happiness_list_keys[max];
        dp[i] = max;
      } else if (selected_happiness == "b") {
        int max = std::max({happiness_list["c"], happiness_list["a"]});
        selected_happiness = happiness_list_keys[max];
        dp[i] = max;
      } else if (selected_happiness == "c") {
        int max = std::max({happiness_list["a"], happiness_list["b"]});
        selected_happiness = happiness_list_keys[max];
        dp[i] = max;
      }
    }
  }
}
