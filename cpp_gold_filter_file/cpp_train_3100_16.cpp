#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  cout << ((n%1000)?1000-(n%1000):0);
  return 0;
}