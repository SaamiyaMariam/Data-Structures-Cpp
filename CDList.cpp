#include <iostream>
#include "Node.cpp"
using namespace std;

class CDList
{
public:
	Node* head;
	Node* tail;

	//constructor
	CDList()
	{
		head = tail = NULL;
	}

	void Insert_at_End(int d)
	{
		Node* temp = new Node;
		temp->data = d;
		temp->next = NULL;
		temp->prev = NULL;

		if (head == NULL)
		{
			head = tail = temp;
			temp->next = temp;	//connecting first and last node
			temp->prev = temp;

		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			temp->next = head;	//implementing cirular property
			head->prev = temp;
			tail = temp;

			temp = NULL;
			delete temp;
		}
	}

	void Insert_at_Start(int d)
	{
		Node* temp = new Node;
		temp->data = d;
		temp->next = NULL;
		temp->prev = NULL;

		if (head == NULL)
		{
			head = tail = temp;
			temp->next = temp;	//connecting first and last node
			temp->prev = temp;

		}
		else
		{
			temp->next = head;
			tail->next = temp;
			head->prev = temp;
			temp->prev = tail;
			head = temp;
			temp = NULL;
			delete temp;
		}
	}

	void Insert_at_Index(int d, int pos)
	{
		int count = 1, size = 0;
		Node* temp = new Node;
		temp->data = d;
		Node* ptr = head;
		Node* previous = NULL;
		while (ptr != tail)
		{
			size++;
			ptr = ptr->next;
		}
		ptr = head;
		if (head == NULL)
		{
			cout << "Linked List is Empty!";
		}
		else if (pos > size)
		{
			cout << "Invalid\n";
		}
		else
		{
			while (count < pos)
			{
				previous = ptr;
				ptr = ptr->next;
				count++;
			}

			temp->next = ptr;
			temp->prev = ptr->prev;
			previous->next = temp;
			ptr->prev = temp;

		}
	
	}

	void DeleteAtStart()
	{
		if (head == NULL)
		{
			cout << "List is Empty!";
		}
		else
		{
			Node* temp;
			temp = head->next;
			temp->prev = tail;
			head = temp;
			tail->next = head;
			temp = NULL;
			delete temp;

		}
	}

	void DeleteAtLast()
	{
		if (head == NULL)
		{
			cout << "List is Empty!";
		}
		else
		{
			Node* temp = new Node;
			temp = tail->prev;
			temp->next = head;
			tail = temp;

			temp = NULL;
			delete temp;
		}
	}

	void Reverse()
	{
		Node* ptr = tail;
		int temp;
		int count = 0;

		CDList* rev = NULL;

		while (ptr != head)
		{
			rev->Insert_at_End(ptr->data);
			ptr = ptr->prev;
			count++;
		}


		ptr = head;
		Node* ptr2 = rev->head;
		for (int i = 0; i < count; i++)
		{
			ptr = ptr2;
			ptr = ptr->next;
			ptr2 = ptr2->next;
		}

	}

	int MidValue()
	{
		int count = 1, size = 0;
		
		Node* ptr = head;
		Node* previous = NULL;
		while (ptr != tail)
		{
			size++;
			ptr = ptr->next;
		}
		int mid = (size / 2) +1;
		ptr = head;

		while (count < mid)
		{
			count++;
				ptr = ptr->next;
		}
		return ptr->data;

	}


	bool IsSorted()
	{
		bool sorted = true;
		Node* ptr = head;
		do
		{
			if (ptr->data > ptr->next->data)
			{
				sorted = false;
				break;
			}
			ptr = ptr->next;
		} while (ptr->next != head);
		return sorted;
	}

	void Display()
	{
		Node* temp = head;
		do
		{
			cout << temp->data << "\t";
			temp = temp->next;
		} while (temp != head); ////instead of temp != NULL since last node is connected to head
		cout << endl;
	}
};