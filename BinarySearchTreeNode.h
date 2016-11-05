#pragma once
template <class T>
class BinarySearchTreeNode
{
private:
	T _data;
	BinarySearchTreeNode* _left_child;
	BinarySearchTreeNode* _right_child;
	BinarySearchTreeNode* _parent;
public:
	const T& get_data()
	{
		return _data;
	}

	void set_data(const T& newData)
	{
		_data = newData;
	}

	BinarySearchTreeNode* get_left_child()
	{
		return _left_child;
	}

	void set_left_child(BinarySearchTreeNode* newLeftChild)
	{
		_left_child = newLeftChild;
	}

	BinarySearchTreeNode* get_right_child()
	{
		return _right_child;
	}

	void set_right_child(BinarySearchTreeNode* newRightChild)
	{
		_right_child = newRightChild;
	}

	BinarySearchTreeNode* get_parent()
	{
		return _parent;
	}

	void set_parent(BinarySearchTreeNode* newParent)
	{
		_parent = newParent;
	}

	BinarySearchTreeNode()
	{
		_left_child = nullptr;
		_right_child = nullptr;
		_parent = nullptr;
	}
};