/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

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
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		if (head != nullptr && n > 0)
		{
			ListNode* fastPtr = head;
			ListNode* slowPtr = head;
			ListNode* tmpPtr;
			int numOfNodes = 1;
			int count = 0;
			int count2 = 0;
			while (count < n)
			{
				if (fastPtr->next != nullptr)
				{
					fastPtr = fastPtr->next;
					numOfNodes++;
				}

				count++;

			}

			if (fastPtr->next != nullptr)
			{
				while (fastPtr->next != nullptr)
				{
					fastPtr = fastPtr->next;
					slowPtr = slowPtr->next;
				}
				tmpPtr = slowPtr->next;
				slowPtr->next = tmpPtr->next;

			}
			else
			{
				//cout << "Enter else" << count << ","<< numOfNodes << endl;
				if (n == numOfNodes)
				{
					//  cout << "in if" << endl;
					tmpPtr = head;
					head = head->next;
				}
				else
				{
					count2 = numOfNodes - n - 1;
					// cout << "in if , count2 = " << count2 <<  endl;
					while (count2 > 0 && slowPtr->next != nullptr)
					{
						slowPtr = slowPtr->next;
						count2--;
					}
					tmpPtr = slowPtr->next;
					slowPtr->next = tmpPtr->next;
				}
			}

			delete(tmpPtr);
			return head;
		}
		return head;
	}
};
