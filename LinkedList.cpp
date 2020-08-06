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
  
		clearList(head_node);
	}
	
	void clearList(Node* node)
	{
		if (node->next_node) {
			Node* n = node->next_node;
			delete node;
			return clearList(n);
		}
	}

	bool append(int value)
	{
		Node* new_node = new Node { value, NULL };

		if (!isEmpty())
		{
			Node* last_node = getLastNode();
			last_node->next_node = new_node;
		}
		else {
			head_node = new_node;
		}

		return true;
	}
	// call only when list is not empty 
	Node* getLastNode(Node* node)
	{
		if (node->next_node)
			return getLastNode(node->next_node);
		
		return node;
	}

	Node* getLastNode()
	{
		return getLastNode(head_node);
	}
	
	void print()
	{
		if (isEmpty()) {
			cout<<"Empty linked list\n";
		} else {
			print(head_node);
		}
	}

	void print(Node* node) {
		if (node->next_node) {
			cout<<node->value<<" -> ";
			return print(node->next_node);
		} else {
			cout<<node->value<<endl;
		}
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
			if (!node && position != i)
				return -1;
			if (position - 1 == i)
				return node->value;

			node = node->next_node;
		}
	
		return -1;
	}

	bool isEmpty()
	{
		return !head_node;
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
