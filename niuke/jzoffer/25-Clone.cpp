#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
	// 1. clone node 
	for (RandomListNode * p = pHead; p != NULL ; p=p->next->next){
		RandomListNode * tmp = new RandomListNode(p->label);
		tmp->next = p->next;
		tmp->random = NULL;
		p->next = tmp;
	}

	// 2. fix the random pointer
	for (RandomListNode * p = pHead; p != NULL; p=p->next->next) {
		if (p->random != NULL)
			p->next->random = p->random->next;
	}

	// 3. separate two list
	RandomListNode * result = NULL;
	RandomListNode * tail = result;
	for (RandomListNode * p = pHead; p != NULL; p=p->next) {
		if (!result) {
			result = p->next;
			tail = p->next;
		} else {
			tail->next = p->next;
			tail=tail->next;
		}
		p->next = p->next->next;
	}

	return result;
    }
};


int main()
{	
	RandomListNode p1 = RandomListNode(1);
	RandomListNode p2 = RandomListNode(2);
	RandomListNode p3 = RandomListNode(3);
	RandomListNode p4 = RandomListNode(4);
	RandomListNode p5 = RandomListNode(5);
	RandomListNode p6 = RandomListNode(6);
	
	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p4;
	p4.next = &p5;
	p5.next = &p6;

	p1.random = &p4;
	p3.random = &p2;
	p6.random = &p1;
	
	for (RandomListNode *p = &p1; p != NULL; p=p->next)
		cout<<p->label<<" ";
	cout<<endl;	
	
	for (RandomListNode * p = &p1; p!=NULL; p=p->next) {
		if (p->random!=NULL)
			cout<<p->random->label<<" ";
	}
	cout<<endl;

	Solution s = Solution();
	RandomListNode * result = s.Clone(&p1);

	for (RandomListNode *p = result; p != NULL; p=p->next)
		cout<<p->label<<" ";
	cout<<endl;	

	return 0;
}
