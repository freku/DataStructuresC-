#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next_node;
};

class LinkedList
{
public:
	Node* head_node;

	LinkedList()
	{
		   head_node = NULL;
	}

	~LinkedList()
	{
		if (isEmpty()) return;
  
		Node* node = head_node;

		while (node->next_node) {
			delete node;
			node = node->next_node;
		}
	}
	
	bool isEmpty()
	{
		return !head_node;
	}

	
	bool append(int value)
	{
		if (!isEmpty())
		{
			Node* last_node = getLastNode();
			Node* new_node = new Node { value, NULL };
			
			last_node->next_node = new_node;
		}
		else {
			Node* new_node = new Node { value, NULL };
			head_node = new_node;
		}
		return true;
	}
	// call only when list is not empty 
	Node* getLastNode()
	{
		Node* node = head_node;

		while (node->next_node) {
			node = node->next_node;
		}

		return node;
	}
	
	bool print()
	{
		if (isEmpty()) {
			cout<<"Empty linked list\n";
			return false;
		}

		Node* node = head_node;
		cout<<node->value;

		while (node->next_node) {
			node = node->next_node;
			cout<<" -> "<<node->value;
		}
		
		cout<<endl;
		
		return true;
	}

	bool prepend(int value)
	{
		Node* new_node = new Node { value, NULL };

		if (!isEmpty())
			new_node->next_node = head_node;

		head_node = new_node;

		return true;
	}

	int at(int position)
	{
		Node* node = head_node;

		for(int i = 0; i < position; i++)
		{
			if (!node->next_node && i != position - 1)
				return -1;
			if (position - 1 == i)
				return node->value;

			node = node->next_node;
		}
		return node->value;
	}
};

int main()
{
	LinkedList list;
	list.print();
	list.prepend(1);
	
	list.print();

	list.prepend(29);
	list.prepend(39);
	list.append(101);
	list.append(102);

	list.prepend(49);
	list.prepend(59);
	list.prepend(69);
	list.print();
	cout<<"1: "<<list.at(1)<<" 2: "<<list.at(2)<<" "<<list.at(111)<<endl;
	cout<<list.at(8)<<" "<<list.at(9)<<endl;
	return 0;
}
