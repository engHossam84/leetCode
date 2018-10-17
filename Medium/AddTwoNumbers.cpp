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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int extraOne = 0;
        ListNode* num1 = l1;
        ListNode* num2 = l2;
        ListNode* result = NULL;
        ListNode* current = NULL;
        ListNode* tmp = NULL;
        int sum = 0;
        if(l1 && l2 == NULL)
        {
            return l1;
        }
        else if(l2 && l1 == NULL)
        {
            return l2;
        }
        else 
        {
            while(num1 != NULL && num2!= NULL)
            {
                sum = num1->val + num2-> val + extraOne;
                extraOne = 0;
                num1 = num1->next;
                num2 = num2->next;
                if(result == NULL)
                {
                    if(sum < 10)
                    {
                        result = new ListNode(sum);
                        current = result ;
                    }
                    else
                    {
                        result = new ListNode(sum%10);
                        extraOne = 1;
                        current = result ;
                    }

                }
                else
                {
                    if(sum < 10)
                    {
                        tmp = new ListNode(sum);
                        current->next = tmp ;
                        current = tmp;
                    }
                    else
                    {
                        tmp = new ListNode(sum%10);
                        extraOne = 1;
                        current->next = tmp ;
                        current = tmp;
                    }
                }
            }
            while(num1 != NULL)
            {
                sum = num1->val + extraOne;
                extraOne = 0;
                num1 = num1->next;
                if(sum < 10)
                {
                    tmp = new ListNode(sum);
                    current->next = tmp ;
                    current = tmp;
                }
                else
                {
                    tmp = new ListNode(sum%10);
                    extraOne = 1;
                    current->next = tmp ;
                    current = tmp;
                }
            }

             while(num2 != NULL)
            {
                sum = num2->val + extraOne;
                extraOne = 0;
                num2 = num2->next;
                if(sum < 10)
                {
                    tmp = new ListNode(sum);
                    current->next = tmp ;
                    current = tmp;
                }
                else
                {
                    tmp = new ListNode(sum%10);
                    extraOne = 1;
                    current->next = tmp ;
                    current = tmp;
                }
            }
            if(extraOne == 1)
            {
                tmp = new ListNode(1);
                current->next = tmp ;
                current = tmp;
            }
            return result;
        }
        
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

