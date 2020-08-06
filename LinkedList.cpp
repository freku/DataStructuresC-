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
	// called only after checking if list is empty
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
};

int main()
{
	LinkedList list;
	list.print();
	list.append(1);
	
	list.print();

	list.append(29);
	list.append(39);

	list.append(49);
	list.append(59);
	list.append(69);
	list.print();
	return 0;
}
