/*
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
Note:

All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.
*/

class ListNode
{
friend class MyLinkedList;
public:
ListNode(int val)
:data(val),next(nullptr)
{}

int data;
ListNode * next;

};

class MyLinkedList {
public:
	/** Initialize your data structure here. */
	MyLinkedList()
		:head(nullptr), tail(nullptr)
	{
		//cout << "In Constrcutor" << endl;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		//  cout << "get " << index << endl;
		if (!isEmpty() && index > -1)
		{
			ListNode * current = head;
			int count = 0;
			while (count < index)
			{
				if (current->next != nullptr)
				{
					current = current->next;
					count++;
				}
				else
					return -1;
			}
			return current->val;
		}
		else
			return -1;
	}

	bool isEmpty()
	{
		if (head == nullptr)
			return true;
		return false;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		//  cout << "addAtHead " << val << endl;
		ListNode * newNode = new ListNode(val);
		if (isEmpty())
			head = tail = newNode;
		else
		{
			newNode->next = head;
			head = newNode;
		}

	}

	void printList()
	{
		if (!isEmpty())
		{
			ListNode * current = head;
			while (current != nullptr)
			{
				cout << current->val << " , ";
				current = current->next;
			}
			cout << endl;
		}
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		//  cout << "addAtTail " << val << endl;
		ListNode * newNode = new ListNode(val);
		if (isEmpty())
			head = tail = newNode;
		else
		{
			ListNode * current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
		// printList();
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		// cout << "addAtIndex " << index << ", " << val << endl;
		if (!isEmpty())
		{
			ListNode * current = head;
			int count = 1;
			// cout <<" val = "<< current->val << endl;
			while (count < index)
			{
				if (current->next != nullptr)
				{
					current = current->next;
					// cout << "C Val = " << current -> val << endl;
					count++;
				}
				else
					count++;
			}
			//cout << "count = "<< count << endl;
			ListNode * newNode = new ListNode(val);
			if (current->next != nullptr)
			{
				// cout << "in if" << endl;
				ListNode * tmpNode = current->next;
				current->next = newNode;
				newNode->next = tmpNode;
			}
			else
			{
				//cout << "in else" << endl;
				current->next = newNode;
			}

		}
		else if (isEmpty() && index == 0)
		{
			addAtHead(val);
		}

		// printList();

	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		//  cout << "deleteAtIndex" << index << endl;
		if (!isEmpty() && index > -1)
		{
			ListNode * tmpNode = nullptr;
			if (index == 0)
			{
				tmpNode = head;
				head = head->next;
				delete(tmpNode);
			}
			else
			{
				if (head != nullptr)
				{
					ListNode * current = head;
					int count = 1;
					while (count < index)
					{
						if (current->next != nullptr)
						{
							current = current->next;

							count++;
						}
						else
						{
							current = nullptr;
						}
					}
					if (current != nullptr)
					{
						if (current->next != nullptr)
						{
							tmpNode = current->next;
							current->next = tmpNode->next;
							delete(tmpNode);
						}
					}
				}

			}
		}

	}

private:
	ListNode * head;
	ListNode * tail;
};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList obj = new MyLinkedList();
* int param_1 = obj.get(index);
* obj.addAtHead(val);
* obj.addAtTail(val);
* obj.addAtIndex(index,val);
* obj.deleteAtIndex(index);
*/
