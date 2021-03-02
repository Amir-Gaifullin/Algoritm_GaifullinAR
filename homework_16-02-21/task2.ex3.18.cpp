#include <iostream> 
#include <algorithm> 

int main()
{
	int length1 = 5;
	int mas1[length1] = { 30, 50, 20, 10, 40 };
	int length2 = 4;
	int mas2[length2] = { 30, 50, 20, 10 };

	int k = 0;
	int* mas = new int[length1 + length2];
	for (int i = 0; i < length1 + length2; i++) {
		if (i < length1) {
			mas[k++] = mas1[i];
		}
		else {
			mas[k++] = mas2[i - length1];
		}
	}

	for (int index = 0; index < (length1 + length2); ++index)
		std::cout << mas[index] << ' ';

	delete[] mas1;
	delete[] mas2;

	return 0;
}