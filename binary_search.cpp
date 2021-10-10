#include <iostream>
#include <utility>

using namespace std;

template <class K, class E> class BST;

// Ʈ���� ��� class
template <class T>
class TreeNode {
	friend class BST<int, int>;
public:
	TreeNode() {};
	TreeNode(T thePair) {
		data = thePair;
		leftChild = 0;
		rightChild = 0;
	}
private:
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
};

// Pair ����
template <class K, class E>
class Dictionary {
public:
	virtual bool IsEmpty() const = 0;
	//�����̸� true ��ȯ
	virtual pair<K, E>*Get(const K&) const = 0;
	//������ Ű ���� ���� �ֿ� ���� ������ ��ȯ, ���� ������ 0 ��ȯ
	virtual void Insert(const pair<K, E>&) = 0;
	//���� ����, Ű�� �ߺ��Ǹ� ���� ���� ����
	virtual void Delete(const K&) = 0;
	//���õ� Ű�� ���� �� ����
};

// �̿� Ž�� Ʈ��
template <class K, class E>
class BST : Dictionary<K, E>{
public:
	BST() { root = 0; }
	// Ʈ�� ���� �����Լ�
	bool IsEmpty() const;
	pair<K, E>* Get(const K&) const;
	pair<K, E>* Get(TreeNode<pair<K, E>>* p, const K& k) const;
	void Insert(const pair<K, E>&);
	void Delete(const K&);
	
	//���� ��ȸ �Լ�
	void Inorder();
	void Inorder(TreeNode<pair<K, E>> *);
	//�湮 �Լ�
	void Visit(TreeNode<pair<K, E>> *);

	void Showinfo(pair<K, E> *);
private:
	TreeNode<pair<K, E>> *root; // Ʈ���� root
};

// ----------------- Ʈ�� data ��� �Լ� ----------------------------
template <class K, class E>
void BST<K, E>::Showinfo(pair<K, E> *p) {
	if(p) {
		cout << p->second << endl;
	}
	else {
		cout << "��尡 �������� �ʽ��ϴ�." << endl;
	}
}
// ------------------------------------------------------------------

// ---------------- Ʈ���� ��ȸ ��ȯ �Լ� ----------------------------
// Ʈ���� �湮 �Լ�
template <class K, class E>
void BST<K, E>::Visit(TreeNode<pair<K, E>> *currentNode) {
	cout << currentNode->data.second << endl;
}

template<class K, class E>
void BST<K, E>::Inorder() {
	Inorder(root);
}

template<class K, class E>
void BST<K, E>::Inorder(TreeNode<pair<K, E>> *currentNode) {
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}
// ------------------------------------------------------------------

// ---------------- Ʈ���� ������ Ȯ���ϴ� �Լ� ---------------------
template <class K, class E>
bool BST<K, E>::IsEmpty() const{
	if (root) {
		return 0;
	}
	else {
		return 1;
	}
}
// ------------------------------------------------------------------

// ---------------- �̿� Ž�� Ʈ���� Ž�� �ڵ� ---------------------
template <class K, class E> //Driver
pair<K, E>* BST<K, E>::Get(const K& k) const
{
	return Get(root, k);
}

template <class K, class E> //Workhorse
pair<K, E>* BST<K, E>::Get(TreeNode<pair<K, E>>*p, const K& k) const
{
	if (!p) return 0;
	if (k<p->data.first) return Get(p->leftChild, k);
	if (k>p->data.first) return Get(p->rightChild, k);
	return &p->data;
}
// ------------------------------------------------------------------

// ------------------------ ��� ���� �Լ� --------------------------
template <class K, class E>
void BST<K, E>::Insert(const pair<K, E>& thePair) {
	TreeNode<pair<K, E>> *p = root, *pp = 0;
	// ���Ե� ����� �θ����� Ž��
	while (p) {
		pp = p;
		if (thePair.first < p->data.first) { // ���� Ű���� ������ ����
			p = p->leftChild;
		}
		else if (thePair.first > p->data.first) { // ���� Ű���� ũ�� ������
			p = p->rightChild;
		}
		else // duplicate, update associated element
		{
			// ������� ������ return
			p->data.second = thePair.second; 
			return;
		}
	}
	// perform insertion
	p = new TreeNode<pair<K, E> >(thePair);
	if (root) { // tree not empty
		if (thePair.first < pp->data.first) {
			pp->leftChild = p;
		}
		else {
			pp->rightChild = p;
		}
	}
	else {
		root = p;
	}
}
// ------------------------------------------------------------------

// ------------------------ ��� ���� �Լ� --------------------------
template <class K, class E>
void BST<K, E>::Delete(const K& k) {
	// p ������ pp ������ thePair ���� ����� �θ���
	TreeNode<pair<K, E>> *p = root, *pp = 0, *thePair = 0;
	int nodeDirection = 0;
	// ������ ����� �θ��� Ž��
	while (p) {
		if (k < p->data.first) {
			thePair = p; // �θ� ����� ����
			p = p->leftChild;
			nodeDirection = 1;
		}
		else if (k > p->data.first) {
			thePair = p; // �θ� ����� ����
			p = p->rightChild;
			nodeDirection = 2;
		}
		else
		{
			pp = p; // ������ ��带 ã��
			break;
		}
	}

	if (!pp) {
		cout << "�߸��� Ű�� �Է��Դϴ�." << endl;
	} 
	// �ڽ��� ���� ���� ����� ���
	while (p) {
		if (pp->leftChild) {
			// ���� ����Ʈ������ ���� ū ����
			p = pp->leftChild;
			if (p->rightChild == NULL) thePair = pp;
			while (p->rightChild) {
				thePair = p;
				nodeDirection = 2;
				p = p->rightChild;
			}
			pp->data = p->data;
			pp = p;
			continue;
		}
		else if (pp->rightChild) {
			// ������ ����Ʈ������ ���� ���� ����s
			p = pp->rightChild;
			while (p->leftChild) {
				thePair = p;
				nodeDirection = 1;
				p = p->leftChild;
			}
			pp->data = p->data;
			pp = p;
			continue;
		}
		else {
			if (nodeDirection == 1) {
				thePair->leftChild = NULL;
			}
			else if(nodeDirection == 2){
				thePair->rightChild = NULL;
			}
			pp->~TreeNode();
			delete pp;
		}
		return;
	}
}
// ------------------------------------------------------------------

int main() {
	BST<int, int> Tree;
	
	cout << "#1: �̿� Ž�� Ʈ���� ��带 �߰��մϴ�." << endl;
	Tree.Insert(make_pair(8, 88));
	Tree.Insert(make_pair(4, 44));
	Tree.Insert(make_pair(9, 99));
	Tree.Insert(make_pair(2, 22));
	Tree.Insert(make_pair(1, 11));
	Tree.Insert(make_pair(6, 66));
	Tree.Insert(make_pair(3, 33));
	Tree.Insert(make_pair(5, 55));
	Tree.Insert(make_pair(7, 77));
	
	cout << "#2: ���� ��ȸ�� �����Ͽ� ����� ���� ����Ѵ�." << endl;
	Tree.Inorder();

	cout << "#3: ��� 4�� ���� �Ѵ�." << endl;
	Tree.Delete(4);

	cout << "#4: ���� ��ȸ�� �����Ͽ� ����� ���� ����Ѵ�." << endl;
	Tree.Inorder();

	cout << "#5: ��� 5�� ���� �Ѵ�." << endl;
	Tree.Delete(5);

	cout << "#6: ���� ��ȸ�� �����Ͽ� ����� ���� ����Ѵ�." << endl;
	Tree.Inorder();
	
	cout << "#7: ��� 2�� ���� �Ѵ�." << endl;
	Tree.Delete(2);

	cout << "#8: ���� ��ȸ�� �����Ͽ� ����� ���� ����Ѵ�." << endl;
	Tree.Inorder();

	cout << "#9: ��� 2�� �ִ��� Ȯ���Ͽ� second ����� ���" << endl;
	Tree.Showinfo(Tree.Get(2));

	cout << "#10: ��� 9�� �ִ��� Ȯ���Ͽ� second ����� ���" << endl;
	Tree.Showinfo(Tree.Get(9));

	return 0;
}