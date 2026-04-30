#include <iostream>
using namespace std;

// Node structure
class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int item) {
		data = item;
		left = right = nullptr;
	}
};

bool search(Node* root, int key) {
	bool present = false;

	// iterative traversal
	while (root != nullptr) {
		if (root->data == key) {
			present = true;
			break;
		}
		else if (key > root->data)
			root = root->right;
		else
			root = root->left;
	}
	return present;
}

int main() {
	// Creating BST
	//    6
	//   / \
	//  2   8
	//     / \
	//    7   9
	Node* root = new Node(6);
	root->left = new Node(2);
	root->right = new Node(8);
	root->right->left = new Node(7);
	root->right->right = new Node(9);

	int key = 7;

	// Searching for key in BST
	cout << search(root, key) << endl;
}