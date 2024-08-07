#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, no_of_changes;
  scanf("%d %d", &n, &no_of_changes);
  int no_of_elements = (1LL << n);
  long long sum = 0;
  vector<int> A(no_of_elements + 1);
  for (int i = 0; i < no_of_elements; i++) {
    scanf("%d", &A[i]);
    sum += A[i];
  }
  double average = (sum * 1.0) / no_of_elements;
  printf("%.12f\n", average);
  for (int i = 1; i <= no_of_changes; i++) {
    int position, new_value;
    scanf("%d %d", &position, &new_value);
    sum = sum - A[position] + new_value;
    A[position] = new_value;
    average = (sum * 1.0) / (no_of_elements);
    printf("%.12f\n", average);
  }
  return 0;
}
