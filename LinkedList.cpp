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

	void insertAt(int value, int pos)
	{
		Node* next = head_node;
		
		if (pos == 0) {
			head_node = new Node {value, head_node};
			return;
		}
		
		for (int i = 0; i < pos - 1; i++)
			next = next->next_node;
		
		Node* new_node = new Node {value, next->next_node};
		next->next_node = new_node;
	}

	void removeAt(int pos)
	{
		if (pos == 0) {
			Node* node = head_node;
			head_node = node->next_node;
			delete node;
			return;
		}

		Node* node = head_node;

		for (int i = 0; i < pos - 1; i++)
			node = node->next_node;

		Node* to_delete = node->next_node;
		node->next_node = node->next_node->next_node;
		delete to_delete;
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

	int at(int pos)
	{
		Node* node = head_node;
		
		for (int i = 0; i < pos; i++)
			node = node->next_node;
		
		return node->value;
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
	list.insertAt(2, 0);
	list.insertAt(3, 1);
	list.insertAt(4, 0);
	list.insertAt(5, 1);
	list.print();
	list.append(10);
	list.prepend(101);
	list.print();
	list.removeAt(1);
	list.print();
	list.removeAt(0);
	list.print();
	cout<<"1: "<<list.at(1)<<" 2: "<<list.at(2)<<" "<<list.at(1)<<endl;
	//cout<<list.at(3)<<" "<<list.at(3)<<endl;
	return 0;
}
