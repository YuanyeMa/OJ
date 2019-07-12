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

	// bubble sort
	//for (int i = 0; i < n-1; i++) {
	//	for (int j = 0; j < n-i-1 ; j++) {
	//		if (numbers[j] > numbers[j+1]) {
	//			float temp = numbers[j];
	//			numbers[j] = numbers[j+1];
	//			numbers[j+1] = temp;
	//		}
	//	}
	//}
	
	// fast bubble sort
	bool swap_flag = false;
	for (int i = 0; i<n-1; i++) {
		swap_flag = true;
		for (int j = 0; j<n-i-1; j++) {
			if (numbers[j] > numbers[j+1]) {
				swap(numbers[j], numbers[j+1]);
				swap_flag = false;
			}
		}
		if (swap_flag) break;
	}
	// output
	cout<<endl;
	cout<<"after sort : ";
	for (int i = 0; i<n; i++)
		cout<<numbers[i]<<" ";
	cout<<endl;
	
	
	return 0;
}

