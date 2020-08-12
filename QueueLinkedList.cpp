#include <iostream>

struct Node {
	int value;
	Node* next;
};

class Queue {
	Node* front, *tail;

public:
	Queue() {
		front = NULL;
		tail = NULL;
	}
	~Queue() {
		Node* n = front;
		Node* tmp;

		while (n) {
			tmp = n->next;
			delete n;
			n = tmp;
			std::cout<<"D ";
		}
	}
	
	void enQueue(int value) {
		Node* new_node = new Node {value, NULL};
		
		if (isEmpty()) {
			front = new_node;
			tail = front;
		} else {
			tail->next = new_node;
			tail = new_node;
		}
	}

	void deQueue() {
		if (!isEmpty()) {
			Node* tmp = front->next;
			delete front;
			front = tmp;
		} else {
			std::cout<<"Queue is empty! / dequeue error\n";
		}
	}

	int peek() {
		if (!isEmpty()) {
			return front->value;
		} else {
			std::cout<<"No value at the front.\n";
			return -1;
		}
	}
	
	bool isEmpty() {
		return !front;
	}

	void print() {
		Node* n = front;

		while (n) {
			std::cout<<n->value<<" ";
			n = n->next;
		}

		std::cout<<std::endl;
	}
};

int main() {
	Queue que;

	que.enQueue(10);que.print(); 
	que.enQueue(101);que.print();
	que.enQueue(102);que.print();
	std::cout<<que.peek()<<std::endl;
	que.enQueue(103);que.print();
	que.deQueue();que.print();
	que.deQueue();que.print();
	//que.deQueue();que.print();
	//que.deQueue();que.print();
	//que.deQueue();que.print();
	return 0;
}
