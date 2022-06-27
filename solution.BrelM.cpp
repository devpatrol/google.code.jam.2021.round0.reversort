#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &numbs, int start, int end)
{
	int i(0), s, e;
	while(start+i < end-i)
	{
		s = start + i;
		e = end - i;
		numbs[s] = numbs[s] + numbs[e];
		numbs[e] = numbs[s] - numbs[e];
		numbs[s] = numbs[s] - numbs[e];
		++i;
	}
}

int main(int argc, char const *argv[])
{
	int nb_of_tests, l, j, cost(0);
	cin >> nb_of_tests;
	for(int x(0); x < nb_of_tests; ++x)
	{
		cost = 0;
		cin >> l;
		vector<int> numbers(l);
		for (int i = 0; i < l; ++i)
			cin >> numbers[i];
		
		for (int i = 0; i < l-1; ++i)
		{
			j = i;
			for(int imin(i); imin<l; ++imin)
			{
				if(numbers[imin] < numbers[j])
					j = imin;
			}
			cost += j - i + 1;
			reverse(numbers, i, j);
		}
		numbers.clear();
		cout << "Case #" << x + 1 << ": " << cost << endl;
	}
	return 0;
}