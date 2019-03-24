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
	ListNode * swapPairs(ListNode* head) {
		ListNode* first = head;
		ListNode* second = nullptr;
		ListNode* prev = nullptr;
		if (first != nullptr)
		{
			if(first->next != nullptr)
			{
				second = first->next;
				if (second->next != nullptr)
				{
					ListNode* tmp = second->next;
					first->next = tmp;
					second->next = first;
					head = second;
					prev = first;
					first = first->next;
				}
				else
				{
					first->next = nullptr;
					second->next = first;
                    head = second;
				}
			}
			else
			return head;
			
		}
		else
			return head;
		while (first->next != nullptr)
		{
			second = first->next;
			if (second->next != nullptr)
			{
				ListNode* tmp = second->next;
				prev->next = second;
				first->next = tmp;
				second->next = first;
                prev = first;
				first = first->next;
			}
			else
			{
				prev->next = second;
				first->next = nullptr;
				second->next = first;
				//first = first->next;

			}

		}
		return head;
	}
};
