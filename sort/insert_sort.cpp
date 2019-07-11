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

	// insert sort
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < i ; j++) {
//			if (numbers[j] > numbers[i]) {
//				float temp = numbers[i];
//				numbers[i] = numbers[j];
//				numbers[j] = temp;
//			}
//		}
//	}
	for (int i = 0; i<n; i++) {
		int j = i-1;
		for (; j>=0; j--) {
			if (numbers[j] < numbers[i]) break;
		}
		if (j!=i-1) {
			float temp = numbers[i];
			int k = i-1;
			for (; k > j; k--)
				numbers[k+1] = numbers[k];
			numbers[k+1] = temp;
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

