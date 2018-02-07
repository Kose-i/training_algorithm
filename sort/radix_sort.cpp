#include <iostream>
#include <vector>

int getMax(const std::vector<int> target)
{
	int max = target[0];
  int search_i = target.size();
	for (int i = 1; i < search_i ; ++i)
		if (target[i] > max)
			max = target[i];
	return max;
}

void countSort(std::vector<int>& target, int exp)
{
  int n = target.size();
	std::vector<int> output(n,0);
	int count[10] = {0};

	for (int i = 0; i < n; ++i)
		++count[ (target[i]/exp)%10 ];

	for (int i = 1; i < 10; ++i)
		count[i] += count[i - 1];

	for (int i = n - 1; 0 <= i; --i)
	{
		output[count[ (target[i]/exp)%10 ] - 1] = target[i];
		--count[ (target[i]/exp)%10 ];
	}

	for (int i = 0; i < n; ++i)
		target[i] = output[i];
}

void sort(std::vector<int>& target)
{
	int m = getMax(target);
	for (int exp = 1; m/exp > 0; exp *= 10)
		countSort(target, exp);
}

int main()
{
  std::vector<int> target{3,2,4,5,3,7,1};
	sort(target);
  for(const auto& e : target)
  {
    std::cout << e << ' ';
  }
  std::cout << '\n';
	return 0;
}
