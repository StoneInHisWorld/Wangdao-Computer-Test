#include <algorithm>
#include <iostream>
using namespace std;

int partition(int * num, int low, int high);
void quick_sort(int * num, int low, int high);

int main() {
	int n;
	while (cin >> n) {
		int * num = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		quick_sort(num, 0, n - 1);
		for (int i = 0; i < n; i++) {
			cout << num[i] << ' ';
		}
		cout << endl;
	}
}

void quick_sort(int * num, int low, int high)
{
	if (low < high)
	{
		int pivot_pos = partition(num, low, high);
		quick_sort(num, low, pivot_pos - 1);
		quick_sort(num, pivot_pos + 1, high);
	}
}

int partition(int * num, int low, int high)
{
	int pivot = num[low];
	while (low < high)
	{
		while (low < high && num[high] >= pivot) high--;
		num[low] = num[high];
		while (low < high && num[low] <= pivot) low++;
		num[high] = num[low];
	}
	num[low] = pivot;
	return low;
}

void swap(int * left, int * right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}