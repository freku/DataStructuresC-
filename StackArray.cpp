#include <iostream>
#include <cstring>

using namespace std;

class Stack {
	char* array;
	int top;
	int size;

public:
	Stack(int size) {
		array = new char[size];
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

	void push(char val) {
		reallocate();

		array[++top] = val;
	}

	bool isEmpty() {
		return top == -1;
	}

	char Top() { return array[top]; }

	void print() {
		for(int i = 0; i < top + 1; i++)
			cout<<array[i]<<" ";
		
		cout<<endl;
	}

	void reallocate() { // size = 10, top = 2
		if ( (top+1) / size == 1 ) {
			size *= 2;
			char* tmp = new char[size];
			
			memcpy(tmp, array, sizeof(char)*(top+1));
			delete array;
			array = tmp;
		}
	}

	int getSize() { return size; }
	int getTop() { return top; };
};

bool isOpen(char ch) {
	return ch == '{' || ch == '(' || ch == '[';
}

bool isClose(char ch) {
	return ch == '}' || ch == ')' || ch == ']';
}

bool isBalanced(string str) {
	Stack stack(str.length());

	for(int i = 0; i < str.length(); i++) {
		if (isOpen(str[i])) {
			stack.push(str[i]);
		} else if (isClose(str[i])) {
			if (stack.isEmpty())
				return false;

			if (isOpen(stack.Top())) {
				stack.pop();
			} else {
				return false;
			}
		}
	} // stack pusty == return true else false
	return stack.isEmpty();
}


int main() {
	Stack stack(10);
	string input;

	while(input != "close") {
		cin>>input;
		bool a = isBalanced(input);
		cout<<"Balanced -> "<<a<<endl;
	}

	return 0;	   
}
