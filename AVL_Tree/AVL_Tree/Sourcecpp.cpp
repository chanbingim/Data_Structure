#include "AVL_Tree.h"
#include <algorithm>

int main()
{
	AVL_Tree<int> AVL_tree;
	AVL_tree.Init();
	AVL_tree.Insert_Node(100);
	AVL_tree.Print_Tree();

	cout << endl;
	cout << endl;
	cout << endl;

	AVL_tree.Insert_Node(150);
	AVL_tree.Print_Tree();

	cout << endl;
	cout << endl;
	cout << endl;

	AVL_tree.Insert_Node(200);
	AVL_tree.Print_Tree();

	cout << endl;
	cout << endl;
	cout << endl;

	AVL_tree.Insert_Node(120);
	AVL_tree.Print_Tree();

	cout << endl;
	cout << endl;
	cout << endl;

	AVL_tree.Insert_Node(75);
	AVL_tree.Print_Tree();


	cout << endl;
	cout << endl;
	cout << endl;

	cout << AVL_tree.Delete_Node(75) << endl;
	AVL_tree.Print_Tree();

	cout << endl;
	cout << endl;
	cout << endl;

	cout << AVL_tree.Delete_Node(75) << endl;
	AVL_tree.Print_Tree();

	cout << endl;
	cout << endl;
	cout << endl;

	cout << AVL_tree.Delete_Node(120) << endl;
	AVL_tree.Print_Tree();

	cout << endl;
	cout << endl;
	cout << endl;

	cout << AVL_tree.Delete_Node(100) << endl;
	AVL_tree.Print_Tree();

	cout << endl;
	cout << endl;
	cout << endl;

	cout << AVL_tree.Delete_Node(150) << endl;
	AVL_tree.Print_Tree();
	return 0;
}