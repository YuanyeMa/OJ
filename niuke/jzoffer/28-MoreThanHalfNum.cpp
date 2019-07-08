#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int size = numbers.size();
		if (size < 1) return 0;

		int result = 0;
		int counter = 0;

		for (int i=0; i<size; i++) {
			if (counter == 0 ) {
				counter = 1;
				result = numbers[i];
			} else if ( result == numbers[i] ) counter++;
			else counter--;
		}
		
		counter = 0;
		for (int i = 0; i < size; i++) {
			if (numbers[i] == result) counter++;
		}
		return (counter > (size>>1)) ? result : 0;
	}
};

int main()
{
	int num[] = {2,2,2,2,2,1,3,4,5};
	
	vector<int> numbers(num, num+9);

	for (auto it = numbers.begin(); it != numbers.end(); it++) {
		cout<<" "<<*it;
	}
	cout<<endl;
	
	Solution s;
	cout<<"result: "<<s.MoreThanHalfNum_Solution(numbers)<<endl;

	return 0;
}

