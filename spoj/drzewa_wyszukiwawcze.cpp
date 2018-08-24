#include <iostream>
#include <algorithm>
using namespace std;

class Tree {
	struct Node {
		int key;
		Node* left, *right, *prev;
		Node() {}
		Node(int kk, Node* n = 0) : key(kk), prev(n) {}
	} *root;
	int maxKey, minKey;
	Node* find(int key) {
		Node* r = root;
		while(r != 0) {
			if(key < r->key)
				r = r->left;
			else if(r->key < key)
				r = r->right;
			else
				return r;
		}
		return 0;
	}
	Node* minLeft(Node* r) {
		while(r->left != 0)
			r = r->left;
		return r;
	}
	Node* minRight(Node* r) {
		while(r->right != 0)
			r = r->right;
		return r;
	}
	void removeKey(Node*& node) {
		Node *tmp = node;
		if(node != 0) {
			if(node->right == 0)
				node = node->left;
			else if(node->left == 0)
				node = node->right;
			else {
				tmp = node->left;
				while(tmp->right != 0)
					tmp = tmp->right;
				tmp->right = node->right;
				tmp = node;
				node = node->left;
			}
			delete tmp;
		}
	}
	void clear(Node* node) {
		if(node != 0) {
			clear(node->left);
			delete node->left;
			clear(node->right);
			delete node->right;
		}
	}
public:
	Tree() : root(0) {}
	void insert(int k) {
		Node* r = root, *poprzednik = 0;
		while(r != 0) {
			poprzednik = r;
			if(k < r->key)
				r = r->left;
			else
				r = r->right;
		}
		if(root == 0)
			root = new Node(k);
		else if(k < poprzednik->key)
			poprzednik->left = new Node(k, poprzednik);
		else
			poprzednik->right = new Node(k, poprzednik);
	}
	int isKey(int key) {
		Node* t = find(key);
		return t != 0 ? t->key : 0;
	}
	int getMin() {
		return minLeft(root)->key;
	}
	int getMax() {
		return minRight(root)->key;
	}
	int prev(int key) {
		Node* r = find(key), *t = 0;
		if(r == 0)
			return 0;
		if(r->left != 0) {
			return minRight(r->left)->key;
		}
		t = r->prev;
		while(t != 0 && t->left == r) {
			r = t;
			t = t->prev;
		}
		return t != 0 ? t->key : 0;
	}
	int next(int key) {
		Node* r = find(key), *t = 0;
		if(r == 0)
			return 0;
		if(r->right != 0) {
			return minLeft(r->right)->key;
		}
		t = r->prev;
		while(t != 0 && t->right == r) {
			r = t;
			t = t->prev;
		}
		return t != 0 ? t->key : 0;
	}
	void remove(int key) {
		Node* node = root, *prev = 0;
		while(node != 0) {
			if(node->key == key)
				break;
			prev = node;
			if(key < node->key)
				node = node->left;
			else
				node = node->right;
		}
		if(node != 0 && node->key == key) {
			if(node == root)
				removeKey(root);
			else if(prev->left == node)
				removeKey(prev->left);
			else if(prev->right == node)
				removeKey(prev->right);
		}
	}
	void inorder(Node* p) {
		if(p != 0) {
			inorder(p->left);
			cout << p->key << " ";
			inorder(p->right);
		}
	}
	void preorder(Node* p) {
		if(p != 0) {
			cout << p->key << " ";
			preorder(p->left);
			preorder(p->right);
		}
	}
	void postorder(Node* p) {
		if(p != 0) {
			postorder(p->left);
			postorder(p->right);
			cout << p->key << " ";
		}
	}
	Node* getRoot() {
		return root;
	}
	void clear() {
		clear(root);
		root = 0;
	}
} *tree;

int main() {
	int t, index = 0;
	cin >> t;
	while(t--) {
		char komenda;
		int w, liczba, tmp;
		cin >> w;
		cout << "test " << (++index) << endl;
		tree = new Tree;
		while(w--) {
			cin >> komenda >> liczba;
			if(komenda == 'I')
				tree->insert(liczba);
			else if(komenda == 'D')
				tree->remove(liczba);
			else if(komenda == 'S') {
				if((tmp = tree->isKey(liczba)) != 0)
					cout << liczba;
				else
					cout << "-";
			} else if(komenda == 'X')
				cout << (liczba == 1 ? (tree->getMax()) : (tree->getMin()));
			else if(komenda == 'N') {
				if((tmp = tree->next(liczba)) == 0)
					cout << "-";
				else
					cout << tmp;
			} else if(komenda == 'P') {
				if((tmp = tree->prev(liczba)) == 0)
					cout << "-";
				else
					cout << tmp;
			} else if(komenda == 'R') {
				if(liczba == 0)
					tree->inorder(tree->getRoot());
				else if(liczba == 1)
					tree->preorder(tree->getRoot());
				else
					tree->postorder(tree->getRoot());
			}
			if(komenda != 'I' && komenda != 'D')
			cout << endl;
		}
	}
}
