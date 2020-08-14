#include <iostream>

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

bool isFullBT(Node* root) {
	if (!root || hasNoChildren(root))
		return true;

	if (root->left && root->right)
		return isFullBT(root->left) && isFullBT(root->right);

	return false;
}

int main() {
	Node* n1 = new Node {1, NULL, NULL};
	Node* n2 = new Node {2, NULL, NULL};
	Node* n3 = new Node {3, NULL, NULL};
	Node* n4 = new Node {4, NULL, NULL};
	Node* n5 = new Node {5, NULL, NULL};
	Node* n6 = new Node {6, NULL, NULL};

	n1->left = n2;
	n1->right = n3;

	n2->left = n4;
	n2->right = n5;

	//n3->left = n6;
	inorder(n1);
	cout<<endl;
	preorder(n1);
	cout<<endl;
	postorder(n1);
	cout<<endl;
	cout<<isFullBT(n1)<<endl;
	return 0;
}
