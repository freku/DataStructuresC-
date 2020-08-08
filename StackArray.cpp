#include <iostream>
#include <cstring>

using namespace std;

class Stack {
	int* array;
	int top;
	int size;

public:
	Stack(int size) {
		array = new int[size];
		top = -1;
		this->size = size;
	}

	~Stack() {
		delete[] array;
	}

	void pop() {
		if (!isEmpty()) {
			top--;
		} else {
			cout<<"Error: Stack Out Of Index"<<endl;
		}
	}

	void push(int val) {
		reallocate();

		array[++top] = val;
	}

	bool isEmpty() {
		return top == -1;
	}

	void print() {
		for(int i = 0; i < top + 1; i++)
			cout<<array[i]<<" ";
		
		cout<<endl;
	}

	void reallocate() { // size = 10, top = 2
		if ( (top+1) / size == 1 ) {
			size *= 2;
			int* tmp = new int[size];
			
			memcpy(tmp, array, sizeof(int)*(top+1));
			delete array;
			array = tmp;
		}
	}

	int getSize() { return size; }
};

int main() {
	Stack stack(10);
	int last_size = stack.getSize();
	for (int i = 0; i< 1000; i++) {
		if (last_size != stack.getSize()) {
			cout<<"new size: "<<stack.getSize()<<endl;
			last_size = stack.getSize();
		}
		stack.push(i);
	}
	//stack.push(1); stack.print();
	//stack.push(2); stack.print();
	//stack.push(3); stack.print();
	//stack.pop(); stack.print();
	//stack.pop(); stack.print();
	//stack.push(101); stack.print();
	
	return 0;	   
}
