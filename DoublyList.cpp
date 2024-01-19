#include <iostream>
#include "Node.cpp"
using namespace std;

class DoublyList
{
public:
	Node* Head;
	Node* Tail;

	DoublyList()
	{
		Head = NULL;
		Tail = NULL;
	}

	void InsertAtEnd(int d)
	{
		Node* temp = new Node;
		temp->data = d;
		temp->next = NULL;
		temp->prev = NULL;

		if (Head == NULL)
		{
			Head = temp;
			Tail = temp;
		}
		else
		{
			//no loop required to go to end so time complexity is O(1)
			Tail->next = temp;
			temp->prev = Tail;
			Tail = temp;
			temp = NULL;
			delete temp;
		}
	}

	void InsertAtStart(int d)
	{
		Node* temp = new Node;
		temp->data = d;
		temp->next = NULL;
		temp->prev = NULL;
		if (Head == NULL)
		{
			
			Head = temp;
			Tail = temp;
		}
		else
		{
			
			temp->next = Head;
			Head->prev = temp;
			Head = temp;
			temp = NULL;
			delete temp;
		}

	}

	void InsertAtPoint(int pos, int val)
	{
		int count = 0, size=0;
		Node* temp = new Node;
		temp->data = val;
		Node* ptr = Head;
		Node* previous = NULL;
		while (ptr != Tail)
		{
			size++;
			ptr = ptr->next;
		}
		ptr = Head;

		if (Head == NULL)
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

			temp->next = previous->next;
			temp->prev = previous;
			previous->next = temp;
			ptr->prev = temp;
		}
	}

	void DeleteAtStart()
	{
		if (Head == NULL)
		{
			cout << "List is Empty!";
		}
		else
		{
			Node* temp;
			temp= Head->next;
			temp->prev = NULL;
			Head = temp;

		}
	}
	void DeleteAtLast()
	{
		if (Head == NULL)
		{
			cout << "List is Empty!";
		}
		else
		{
			Node* temp;
			temp = Tail->prev;
			temp->next = NULL;
			Tail = temp;
		}
	}

	void DeleteAtPoint(int pos)
	{
		int count = 0, size = 0;
		Node* ptr = Head;
		Node* previous = NULL;
		while (ptr != Tail)
		{
			size++;
			ptr = ptr->next;
		}
		ptr = Head;

		if (Head == NULL)
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
			ptr->next->prev = previous;
			previous->next = ptr->next;

		}
	}

	void RemoveDup()
	{
		Node* ptr = Head;

		
		if (Head == NULL)
		{
			cout << "List is Empty!\n";
		}
		else
		{
			int size = 0;
			Node* previous = ptr;
			Node* check;
			while (ptr != NULL)
			{
				size++;
				ptr = ptr->next;
			}
			
			ptr = Head;
			//sort the data in ascending order
			int *dataArr = new int [size];

			cout << "!!!!!!!!!";

			for (int i = 0; i < 8; i++)
			{
				dataArr[i] = ptr->data;
				ptr = ptr->next;
			}

			int end;
			for (int i = 1; i < 8; i++)
			{
				end = dataArr[i];
				int j = i - 1;
				while (j >= 0 && dataArr[j] > end)
				{
					dataArr[j + 1] = dataArr[j];
					j = j - 1;
				}
				dataArr[j + 1] = end;
			}


			//moving data from array back to linked list
			ptr = Head;
			for (int i = 0; i < size; i++)
			{
				ptr->data = dataArr[i];
				ptr = ptr->next;
			}

			
			ptr = Head;
			ptr = ptr->next;
			while (ptr != NULL)
			{
				if (previous->data == ptr->data)
				{
					check = ptr;
					previous->next = ptr->next;
					ptr->next->prev = previous;
					ptr = ptr->next;
					delete check;
				}
				else
				{
					ptr = ptr->next;
					previous = previous->next;
				}
			}
			
			
		}
	}

	void Swap(int Index1, int Index2)
	{
		int size = 0;
		Node* current = Head;
		while (current != Tail)
		{
			current = current->next;
			size++;
		}
		current = Head;

		if (Index1 > size || Index2 > size)
		{
			cout << "Invalid\n";
		}
		else if (Head == NULL)
		{
			cout << "Linked List is Empty\n";
		}
		else
		{
			int count1 = 0, count2 = 0;
			Node* Temp1 = new Node;
			Node* Temp2 = new Node;
			while (count1 != Index1)
			{
				count1++;
				current = current->next;
			}
			Temp1 = current;
			current = Head;
			while (count2 != Index2)
			{
				count2++;
				current = current->next;
			}
			Temp2 = current;
			current = Temp1;
			current = Head;
			int x = 0;
			while (x != Index1)
			{
				x++;
				current = current->next;
			}
			current = Temp2;


		}
	}

	void Display()
	{
		Node* temp = Head;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
			
		}
	}

	void RevDisplay()
	{
		Node* temp = Tail;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->prev;
		}
	}
};