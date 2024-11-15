#include <bits/stdc++.h>
struct NumbersWithCertainBitValueGenerator {
 private:
  int bit_pos;
  bool bit_val;
  int max_state;
  int state = 0;

 public:
  NumbersWithCertainBitValueGenerator(int up_to, int position, bool value)
      : max_state(up_to), bit_pos(position), bit_val(value) {
    move_to_next();
  }
  bool has_next() { return state < max_state; }
  int get_next() {
    int next = state++;
    move_to_next();
    return next;
  }

 private:
  void move_to_next() {
    while (state < max_state && ((state >> bit_pos) & 1) != bit_val) {
      state += 1;
    }
  }
};
int main() {
  int n;
  std::cin >> n;
  std::map<std::pair<int, int>, std::vector<int>> partial_minimums;
  int bits_in_n = 0;
  while (n >> (++bits_in_n)) {
  }
  for (int bit = 0; bit < bits_in_n; bit++) {
    for (int val = 0; val <= 1; val++) {
      NumbersWithCertainBitValueGenerator g(n, bit, (bool)val);
      std::vector<int> indices;
      indices.reserve(1000);
      while (g.has_next()) {
        indices.push_back(g.get_next());
      }
      std::vector<int> current_minimums(n, 0);
      if (!indices.empty()) {
        std::cout << indices.size() << std::endl;
        for (int i : indices) {
          std::cout << i + 1 << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < n; i++) {
          std::cin >> current_minimums[i];
        }
      }
      partial_minimums[std::make_pair(bit, val)] = current_minimums;
    }
  }
  std::cout << -1 << std::endl;
  for (int i = 0; i < n; i++) {
    int minimum_for_row = INT32_MAX;
    for (int bit = 0; bit < bits_in_n; bit++) {
      int bit_value = (i >> bit) & 1;
      int next_minimum = partial_minimums[std::make_pair(bit, !bit_value)][i];
      if (next_minimum < minimum_for_row) {
        minimum_for_row = next_minimum;
      }
    }
    std::cout << minimum_for_row << " ";
  }
  std::cout << std::endl;
  return 0;
}
