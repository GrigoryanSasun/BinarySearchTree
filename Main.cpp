#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree<int>* tree = new BinarySearchTree<int>();
	cout << "Empty binary tree created with height " << tree->get_height() << endl;
	cout << "Inserting values 60,20,10,40,30,50,70" << endl;
	tree->insert(60);
	tree->insert(20);
	tree->insert(10);
	tree->insert(40);
	tree->insert(30);
	tree->insert(50);
	tree->insert(70);
	cout << "The new height is " << tree->get_height() << endl;
	if (tree->find(40)) {
		cout << "The tree contains 40";
	}
	else {
		cout << "The tree does not contain 40";
	}
	cout << endl;
	if (tree->find(8)) {
		cout << "The tree contains 8";
	}
	else {
		cout << "The tree does not contain 8";
	}
	cout << endl;
	cout << "Traversing the tree" << endl;
	cout << "Preorder: ";
	tree->preorder_traverse();
	cout << "Inorder: ";
	tree->inorder_traverse();
	cout << "Postorder: ";
	tree->postorder_traverse();
	cout << "Removing 70" << endl;
	tree->remove(70);
	cout << "Inorder traverse after removing 70: ";
	tree->inorder_traverse();
	cout << "Removing 40" << endl;
	tree->remove(40);
	cout << "Inorder traverse after removing 40: ";
	tree->inorder_traverse();
	delete tree;
	return 0;
}