#include <iostream>
#include <string>
using namespace std;

int main(){
	int sx, sy, tx, ty;
	int dx, dy;
	cin >> sx >> sy >> tx >> ty;
	dx = tx - sx;
	dy = ty - sy;
	cout << string(dy, 'U') << sring(dx, 'R') << string(dy, 'D') << sring(dx, 'L');
	cout << 'L';
	cout << string(dy + 1, 'U') << sring(dx + 1, 'R')
	cout << 'D';
	cout << 'R';
	cout << string(dy + 1, 'D') << sring(dx + 1, 'L')
	cout << 'U';
	return 0;
}

