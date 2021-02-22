#include <iostream>
using namespace std;
int main() {
	int len = 0;
	int x = 0;
	int sum = 0;

	cin >> len;
	for (int i = 0;i < len;i++) {
		cin >> x;
		sum = sum + x;
	}
	cout << sum;

	return 0;
}
