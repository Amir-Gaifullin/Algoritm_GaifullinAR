
#include <iostream> 
#include <algorithm> 

int sort_mas(const int len, int sort[]) {
	for (int i = 0; i < len - 1; ++i)
	{
		int i_min = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (sort[j] < sort[i_min])
				i_min = j;
		}
		std::swap(sort[i], sort[i_min]);
	}
}

int main()
{
	int length = 5;
	int mas[length] = { 30, 50, 20, 10, 40 };
	sort_mas(length, mas);
	for (int index = 0; index < length; ++index)
		std::cout << mas[index] << ' ';

	return 0;
}