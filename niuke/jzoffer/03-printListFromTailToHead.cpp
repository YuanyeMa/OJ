#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	struct ListNode * next;
	ListNode(int x):val(x), next(NULL){}
};


class Solution {
public:
		vector<int> result ;
		vector<int> printListFromTailToHead(ListNode * head){
			if (head!=NULL){
				printListFromTailToHead(head->next);
				result.push_back(head->val);
			}
			return result;
		}
};

int main()
{
	// 1. creat a list 
	struct ListNode * head = NULL;
	struct ListNode * tail = head;
	for (int i = 0; i<10; i++){
		struct ListNode * node = new ListNode(i);
		if (!head){
			head = node;
			tail = head;
		} else {
			tail->next = node;
			tail = node;
		}
	}

	// 2. print the list
	cout<<"source : ";
	for (struct ListNode * p = head; p!=NULL; p=p->next){
		cout<<p->val<<" ";
	}
	cout<<endl;

	// 3. 
	Solution s;
	vector<int> res = s.printListFromTailToHead(head);
	
	cout<<"result : ";
	for (auto i = res.begin(); i!=res.end(); i++){
		cout<<*i<<" ";
	}
	cout<<endl;

	return 0;
}


