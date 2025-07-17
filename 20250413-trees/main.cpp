//https://www.youtube.com/watch?v=S7SzpK84N-Q&list=PLD075A4D416004C91&index=5
#include "tree.h"
int main() {
	Tree<int> tree1;

    tree1.Add(13);
	tree1.Add(5);
	tree1.Add(3);
	tree1.Add(10);
	tree1.Add(7);
	tree1.Add(11);
	tree1.Add(6);
	tree1.Add(9); 
	cout << "Tree height : " << tree1.GetHeight() << endl
		 << "There are " << tree1.GetNodesOnLevel(3) << " nodes on the 3rd level" << endl;
	
    cout << tree1.root->item 
         << " " << tree1.root->son->item 
         << " " << tree1.root->brother 
         << " " << tree1.root->son->son->item << " " << tree1.root->son->brother->item
         << "\n";
    return 0;	
}