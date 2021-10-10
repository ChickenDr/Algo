#include <iostream>
#include <utility>

using namespace std;

template <class K, class E> class BST;

// 트리의 노드 class
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

// Pair 사전
template <class K, class E>
class Dictionary {
public:
	virtual bool IsEmpty() const = 0;
	//공백이면 true 반환
	virtual pair<K, E>*Get(const K&) const = 0;
	//지시한 키 값을 가진 쌍에 대한 포인터 반환, 쌍이 없으면 0 반환
	virtual void Insert(const pair<K, E>&) = 0;
	//쌍을 삽입, 키가 중복되면 관련 원소 갱신
	virtual void Delete(const K&) = 0;
	//지시된 키를 가진 쌍 삭제
};

// 이원 탐색 트리
template <class K, class E>
class BST : Dictionary<K, E>{
public:
	BST() { root = 0; }
	// 트리 조작 관련함수
	bool IsEmpty() const;
	pair<K, E>* Get(const K&) const;
	pair<K, E>* Get(TreeNode<pair<K, E>>* p, const K& k) const;
	void Insert(const pair<K, E>&);
	void Delete(const K&);
	
	//중위 순회 함수
	void Inorder();
	void Inorder(TreeNode<pair<K, E>> *);
	//방문 함수
	void Visit(TreeNode<pair<K, E>> *);

	void Showinfo(pair<K, E> *);
private:
	TreeNode<pair<K, E>> *root; // 트리의 root
};

// ----------------- 트리 data 출력 함수 ----------------------------
template <class K, class E>
void BST<K, E>::Showinfo(pair<K, E> *p) {
	if(p) {
		cout << p->second << endl;
	}
	else {
		cout << "노드가 존재하지 않습니다." << endl;
	}
}
// ------------------------------------------------------------------

// ---------------- 트리의 중회 순환 함수 ----------------------------
// 트리의 방문 함수
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

// ---------------- 트리의 공백을 확인하는 함수 ---------------------
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

// ---------------- 이원 탐색 트리의 탐색 코드 ---------------------
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

// ------------------------ 노드 삽입 함수 --------------------------
template <class K, class E>
void BST<K, E>::Insert(const pair<K, E>& thePair) {
	TreeNode<pair<K, E>> *p = root, *pp = 0;
	// 삽입될 노드의 부모노드의 탐색
	while (p) {
		pp = p;
		if (thePair.first < p->data.first) { // 받은 키값이 작으면 왼쪽
			p = p->leftChild;
		}
		else if (thePair.first > p->data.first) { // 받은 키값이 크면 오른쪽
			p = p->rightChild;
		}
		else // duplicate, update associated element
		{
			// 같은경우 갱신후 return
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

// ------------------------ 노드 삭제 함수 --------------------------
template <class K, class E>
void BST<K, E>::Delete(const K& k) {
	// p 현재노드 pp 지울노드 thePair 지울 노드의 부모노드
	TreeNode<pair<K, E>> *p = root, *pp = 0, *thePair = 0;
	int nodeDirection = 0;
	// 삭제할 노드의 부모노드 탐색
	while (p) {
		if (k < p->data.first) {
			thePair = p; // 부모 노드의 저장
			p = p->leftChild;
			nodeDirection = 1;
		}
		else if (k > p->data.first) {
			thePair = p; // 부모 노드의 저장
			p = p->rightChild;
			nodeDirection = 2;
		}
		else
		{
			pp = p; // 삭제할 노드를 찾음
			break;
		}
	}

	if (!pp) {
		cout << "잘못된 키의 입력입니다." << endl;
	} 
	// 자식을 가진 비리프 노드의 경우
	while (p) {
		if (pp->leftChild) {
			// 왼쪽 서브트리에서 가장 큰 원소
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
			// 오른쪽 서브트리에서 가장 작은 원소s
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
	
	cout << "#1: 이원 탐색 트리의 노드를 추가합니다." << endl;
	Tree.Insert(make_pair(8, 88));
	Tree.Insert(make_pair(4, 44));
	Tree.Insert(make_pair(9, 99));
	Tree.Insert(make_pair(2, 22));
	Tree.Insert(make_pair(1, 11));
	Tree.Insert(make_pair(6, 66));
	Tree.Insert(make_pair(3, 33));
	Tree.Insert(make_pair(5, 55));
	Tree.Insert(make_pair(7, 77));
	
	cout << "#2: 중위 순회를 수행하여 노드의 값을 출력한다." << endl;
	Tree.Inorder();

	cout << "#3: 노드 4를 삭제 한다." << endl;
	Tree.Delete(4);

	cout << "#4: 중위 순회를 수행하여 노드의 값을 출력한다." << endl;
	Tree.Inorder();

	cout << "#5: 노드 5를 삭제 한다." << endl;
	Tree.Delete(5);

	cout << "#6: 중위 순회를 수행하여 노드의 값을 출력한다." << endl;
	Tree.Inorder();
	
	cout << "#7: 노드 2를 삭제 한다." << endl;
	Tree.Delete(2);

	cout << "#8: 중위 순회를 수행하여 노드의 값을 출력한다." << endl;
	Tree.Inorder();

	cout << "#9: 노드 2가 있는지 확인하여 second 결과를 출력" << endl;
	Tree.Showinfo(Tree.Get(2));

	cout << "#10: 노드 9가 있는지 확인하여 second 결과를 출력" << endl;
	Tree.Showinfo(Tree.Get(9));

	return 0;
}