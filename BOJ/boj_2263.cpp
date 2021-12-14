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
    int val, n;
    cin >> n;
    BST * root;

    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        if(i == 0) {
            root = new BST(r);
        }
        else{
            root->insert(root, r);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
    }

    root->postorder(root);
    return 0;
}