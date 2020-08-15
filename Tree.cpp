#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int value;
	Node* left, *right;
};

void inorder(Node* root) {
	if (root) {
		inorder(root->left);
		cout<<root->value<<" -> ";
		inorder(root->right);
	}
}

void preorder(Node* root) {
	if (root) {
		cout<<root->value<<" -> ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		cout<<root->value<<" -> ";
	}
}

bool hasChildren(Node* root) {
	return root->left && root->right;
}

bool hasSingleChild(Node* root) {
	return (!root->left && root->right) || (root->left && !root->right);
}

bool hasNoChildren(Node* root) {
	return !root->left && !root->right;
}

int depth(Node* root, int d) {
	if (root) {
		return max(depth(root->left, d + 1), depth(root->right, d + 1));
	} else {
		return d;
	}
}

bool isFullBT(Node* root) {
	if (!root || hasNoChildren(root))
		return true;

	if (hasChildren(root))
		return isFullBT(root->left) && isFullBT(root->right);

	return false;
}

bool isPerfectBT(Node* root) {
	if (hasNoChildren(root))
		return true;	

	if (root->left && root->right)
		return depth(root->left, 0) == depth(root->right, 0)
			&& isPerfectBT(root->left) && isPerfectBT(root->right);

	return false;
}

Node* create_node(int value) {
	return new Node {value, NULL, NULL};
}

void insert(Node*& root, int value) {
	if (!root) {
		root = create_node(value);
		return;
	}

	if (value < root->value)
		insert(root->left, value);
	else
		insert(root->right, value);
}

bool search(Node* root, int val) {
	if (!root) return false;

	if (root->value == val)
		return true;

	if (val < root->value)
		return search(root->left, val);
	else
		return search(root->right, val);
}

int main() {
	Node* root = create_node(12);
	insert(root, 5);
	insert(root, 6);
	insert(root, 7);
	insert(root, 14);
	insert(root, 13);
	insert(root, 16);

	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	cout<<isFullBT(root)<<endl;
	cout<<"is perfect: "<<isPerfectBT(root)<<endl;
	cout<<"search 12: "<<search(root, 12)<<endl;
	cout<<"search 5: "<<search(root, 5)<<endl;
	cout<<"search 2: "<<search(root, 2)<<endl;
	cout<<"search 1: "<<search(root, 1)<<endl;
	return 0;
}
