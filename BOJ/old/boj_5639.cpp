#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BST{
    private:
        int key;
        BST *leftchild;
        BST *rightchild;

    public:
    BST(int n){
        key = n;
        leftchild = NULL;
        rightchild = NULL;
    }
    BST *insert(BST *x, int k);
    void postorder(BST *node);
};

BST *BST::insert(BST *x, int k){
    if(x == NULL) {
        x = new BST(k);
    }
    else if(k < x->key) x->leftchild = insert(x->leftchild, k);
    else x->rightchild = insert(x->rightchild, k);

    return x;
}


void BST::postorder(BST* node) {
	if (node->leftchild != NULL)
		postorder(node->leftchild);

	if (node->rightchild != NULL)
		postorder(node->rightchild);
	cout << node->key << '\n';
}

int main(){
    int val, tmp;
    cin >> tmp;

    BST *root = new BST(tmp);

	while (cin>>val) {
        if (val == EOF) break;
        root->insert(root, val);
	}

    root->postorder(root);
    return 0;
}