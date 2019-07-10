#include <iostream>

using namespace std;

int main()
{
	// input
	const int MAXN = 1001;
	float numbers[MAXN];
	
	int n = 0;
	cout<<"len : ";
	cin>>n;

	for (int i = 0; i < n; i++) {
		cout<<i<<" of numbers : ";
		cin>>numbers[i];
	}

	// sort
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i+1; j < n ; j++) {
			if (numbers[j] < numbers[min]) min = j;
		}
		if (min != i) {
			float temp = numbers[min];
			numbers[min] = numbers[i];
			numbers[i] = temp;
		}
	}
	// output
	cout<<endl;
	cout<<"after sort : ";
	for (int i = 0; i<n; i++)
		cout<<numbers[i]<<" ";
	cout<<endl;
	
	
	return 0;
}

