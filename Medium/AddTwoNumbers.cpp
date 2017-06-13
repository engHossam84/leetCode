/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};


class Solution {
public:
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * result;
		ListNode * head;
		ListNode * newNode;
		int sum = 0, carry = 0;

		sum = l1->val + l2->val + carry;
		carry = sum / 10;
		newNode = new ListNode(sum % 10);
		result = newNode;
		head = newNode;
		l1 = l1->next; 
		l2 = l2->next;
		while (l1 != nullptr || l2 != nullptr)
		{
			if (l1 && l2)
			{
				sum = l1->val + l2->val + carry;
				carry = sum / 10;
				newNode = new ListNode(sum % 10); 
				result->next = newNode;
				result = result->next;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1 != nullptr && l2 == nullptr)
			{
				sum = l1->val + carry;
				carry = sum / 10;
				newNode = new ListNode(sum % 10);
				result->next = newNode;
				result = result->next;
				l1 = l1->next;
			}
			else if (l1 == nullptr && l2 != nullptr)
			{
				sum = l2->val + carry;
				carry = sum / 10;
				newNode = new ListNode(sum % 10);
				result->next = newNode;
				result = result->next;
				l2 = l2->next;
			}

		}
		if (carry == 1)
		{
			newNode = new ListNode(carry);
			result->next = newNode;
			result = result->next;
		}

		return head;
	}

};

void print(ListNode* listNode)
{
	ListNode * currentNode = listNode;
	while (currentNode != nullptr)
	{
		cout << currentNode->val << " ";
		currentNode = currentNode->next;
	}
	cout << endl;
}

void main()
{
	
	ListNode *newNode = new ListNode(2);
	ListNode * Head = newNode;
	ListNode * Tail = newNode;

	newNode = new ListNode(4);
	Tail->next = newNode;
	Tail = Tail->next;

	newNode = new ListNode(5);
	Tail->next = newNode;
	Tail = Tail->next;

	newNode = new ListNode(5);
	ListNode * Head2 = newNode;
	ListNode * Tail2 = newNode;

	newNode = new ListNode(6);
	Tail2->next = newNode;
	Tail2 = Tail2->next;

	newNode = new ListNode(5);
	Tail2->next = newNode;
	Tail2 = Tail2->next;

	newNode = new ListNode(8);
	Tail2->next = newNode;
	Tail2 = Tail2->next;

	
	print(Head);
	cout << endl;
	print(Head2);
	cout << endl;

	ListNode *result = Solution::addTwoNumbers(Head, Head2);
	print(result);

}

