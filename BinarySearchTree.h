#pragma once
#include "BinarySearchTreeNode.h"

template <class T>
class BinarySearchTree
{
private:
	BinarySearchTreeNode<T>* _treeRoot;

	void finalize(BinarySearchTreeNode<T>* node)
	{
		if (node != nullptr)
		{
			finalize(node->get_left_child());
			finalize(node->get_right_child());
			cout << "Finalizing the node with value " << node->get_data() << endl;
			delete node;
		}
	}

	void inorder_traverse_helper(BinarySearchTreeNode<T>* node)
	{
		if (node != nullptr)
		{
			inorder_traverse_helper(node->get_left_child());
			cout << node->get_data() << " ";
			inorder_traverse_helper(node->get_right_child());
		}
	}

	void preorder_traverse_helper(BinarySearchTreeNode<T>* node)
	{
		if (node != nullptr)
		{
			cout << node->get_data() << " ";
			preorder_traverse_helper(node->get_left_child());
			preorder_traverse_helper(node->get_right_child());
		}
	}

	void postorder_traverse_helper(BinarySearchTreeNode<T>* node)
	{
		if (node != nullptr)
		{
			postorder_traverse_helper(node->get_left_child());
			postorder_traverse_helper(node->get_right_child());
			cout << node->get_data() << " ";
		}
	}

	int get_height_helper(BinarySearchTreeNode<T>* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int leftTreeHeight = get_height_helper(node->get_left_child());
		int rightTreeHeight = get_height_helper(node->get_right_child());
		int max = (leftTreeHeight > rightTreeHeight) ? leftTreeHeight : rightTreeHeight;
		return max + 1;
	}

	BinarySearchTreeNode<T>* get_node_by_value(const T& value)
	{
		BinarySearchTreeNode<T>* currentNode = _treeRoot;
		while (currentNode != nullptr)
		{
			T currentNodeValue = currentNode->get_data();
			if (value == currentNodeValue)
			{
				break;
			}
			else if (value < currentNodeValue)
			{
				currentNode = currentNode->get_left_child();
			}
			else
			{
				currentNode = currentNode->get_right_child();
			}
		}
		return currentNode;
	}

	void replace_by_node(BinarySearchTreeNode<T>* oldNode, BinarySearchTreeNode<T>* newNode)
	{
		BinarySearchTreeNode<T>* oldNodeParent = oldNode->get_parent();
		if (oldNodeParent == nullptr)
		{
			_treeRoot = newNode;
		}
		else if (oldNodeParent->get_left_child() == oldNode)
		{
			oldNodeParent->set_left_child(newNode);
		}
		else {
			oldNodeParent->set_right_child(newNode);
		}
		if (newNode != nullptr) {
			newNode->set_parent(oldNodeParent);
		}
	}

public:
	void inorder_traverse()
	{
		inorder_traverse_helper(_treeRoot);
		cout << endl;
	}

	void preorder_traverse()
	{
		preorder_traverse_helper(_treeRoot);
		cout << endl;
	}

	void postorder_traverse()
	{
		postorder_traverse_helper(_treeRoot);
		cout << endl;
	}


	void insert(const T& newValue)
	{
		BinarySearchTreeNode<T>* newNode = new BinarySearchTreeNode<T>();
		newNode->set_data(newValue);
		if (_treeRoot == nullptr)
		{
			_treeRoot = newNode;
		}
		else 
		{
			BinarySearchTreeNode<T>* parentNode = nullptr;
			BinarySearchTreeNode<T>* currentNode = _treeRoot;
			while (currentNode != nullptr)
			{
				parentNode = currentNode;
				T currentNodeData = currentNode->get_data();
				if (newValue < currentNodeData)
				{
					currentNode = currentNode->get_left_child();
				}
				else if (newValue > currentNodeData)
				{
					currentNode = currentNode->get_right_child();
				}
				else
				{
					delete newNode;
					throw "Duplicate value detected";
				}
			}
			newNode->set_parent(parentNode);
			if (newValue < parentNode->get_data())
			{
				parentNode->set_left_child(newNode);
			}
			else
			{
				parentNode->set_right_child(newNode);
			}
		}
	}

	bool find(const T& value)
	{
		BinarySearchTreeNode<T>* foundNode = get_node_by_value(value);
		return foundNode != nullptr;
	}

	int get_height()
	{
		return get_height_helper(_treeRoot);
	}

	void remove(T value)
	{
		BinarySearchTreeNode<T>* nodeToRemove = get_node_by_value(value);
		if (nodeToRemove == nullptr)
		{
			throw "Value not found";
		}
		BinarySearchTreeNode<T>* leftChild = nodeToRemove->get_left_child();
		BinarySearchTreeNode<T>* rightChild = nodeToRemove->get_right_child();
		if (leftChild == nullptr)
		{
			replace_by_node(nodeToRemove, rightChild);
		}
		else if (rightChild == nullptr)
		{
			replace_by_node(nodeToRemove, leftChild);
		}
		else {
			//Find the inorder successor of the removable node which is in the right subtree
			BinarySearchTreeNode<T>* inorderSuccessor = rightChild;
			bool found = false;
			while (!found)
			{
				BinarySearchTreeNode<T>* leftNode = inorderSuccessor->get_left_child();
				if (leftNode == nullptr) {
					found = true;
				}
				else {
					inorderSuccessor = leftNode;
				}
			}
			if (inorderSuccessor->get_parent() != nodeToRemove) {
				BinarySearchTreeNode<T>* inorderSuccessorRightChild = inorderSuccessor->get_right_child();
				replace_by_node(inorderSuccessor, inorderSuccessorRightChild);
				inorderSuccessor->set_right_child(rightChild);
				rightChild->set_parent(inorderSuccessor);
			}
			replace_by_node(nodeToRemove, inorderSuccessor);
			inorderSuccessor->set_left_child(leftChild);
			leftChild->set_parent(inorderSuccessor);
		}
		delete nodeToRemove;
	}

	BinarySearchTree()
	{
		cout << "Constructor called" << endl;
		_treeRoot = nullptr;
	}

	~BinarySearchTree()
	{
		cout << "Destructor called" << endl;
		finalize(_treeRoot);
	}
};