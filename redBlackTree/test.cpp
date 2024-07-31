#include <iostream>
#include <string>

enum Color { RED, BLACK };

template <typename T>
class Node {
public:
    T key;
    std::string value;
    Node* parent;
    Node* left;
    Node* right;
    Color color;

    Node(T key, const std::string& value) : key(key), value(value), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}
};

template <typename T>
class RedBlackTree {
private:
    Node<T>* root;
    Node<T>* nil;

    // Helper functions
    void leftRotate(Node<T>* x);
    void rightRotate(Node<T>* y);
    void fixInsert(Node<T>* z);
    void fixDelete(Node<T>* x);
    Node<T>* findSuccessor(Node<T>* node);
    void transplant(Node<T>* u, Node<T>* v);

public:
    RedBlackTree();
    ~RedBlackTree();
    
    // Public methods
    void insert(T key, const std::string& value);
    void remove(T key);
    Node<T>* search(T key);
    void inorderTraversal(Node<T>* node);
    Node<T>* getRoot() const { return root; }
};

template <typename T>
RedBlackTree<T>::RedBlackTree() {
    nil = new Node<T>(0, "");
    nil->color = BLACK;
    root = nil;
}

template <typename T>
RedBlackTree<T>::~RedBlackTree() {
    // Add cleanup logic if needed
}

template <typename T>
void RedBlackTree<T>::leftRotate(Node<T>* x) {
    Node<T>* y = x->right;
    x->right = y->left;

    if (y->left != nil) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nil) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

template <typename T>
void RedBlackTree<T>::rightRotate(Node<T>* y) {
    Node<T>* x = y->left;
    y->left = x->right;

    if (x->right != nil) {
        x->right->parent = y;
    }

    x->parent = y->parent;

    if (y->parent == nil) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

template <typename T>
void RedBlackTree<T>::fixInsert(Node<T>* z) {
    while (z->parent != nil && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node<T>* y = z->parent->parent->right;
            if (y != nil && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            Node<T>* y = z->parent->parent->left;
            if (y != nil && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

template <typename T>
void RedBlackTree<T>::insert(T key, const std::string& value) {
    Node<T>* node = new Node<T>(key, value);
    Node<T>* y = nil;
    Node<T>* x = root;

    while (x != nil) {
        y = x;
        if (node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == nil) {
        root = node;
    } else if (node->key < y->key) {
        y->left = node;
    } else {
        y->right = node;
    }

    fixInsert(node);
}

template <typename T>
void RedBlackTree<T>::remove(T key) {
    Node<T>* z = search(key);
    if (z == nil) {
        std::cout << "Node with key " << key << " not found in the tree." << std::endl;
        return;
    }

    Node<T>* y = z;
    Node<T>* x;
    Color yOriginalColor = y->color;

    if (z->left == nil) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nil) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = findSuccessor(z->right);
        yOriginalColor = y->color;
        x = y->right;

        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    delete z;

    if (yOriginalColor == BLACK) {
        fixDelete(x);
    }
}

template <typename T>
void RedBlackTree<T>::fixDelete(Node<T>* x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            Node<T>* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }

            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            Node<T>* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }

            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }

    if (x != nullptr) {
        x->color = BLACK;
    }
}

template <typename T>
Node<T>* RedBlackTree<T>::findSuccessor(Node<T>* node) {
    while (node->left != nil) {
        node = node->left;
    }
    return node;
}

template <typename T>
void RedBlackTree<T>::transplant(Node<T>* u, Node<T>* v) {
    if (u->parent == nil) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    v->parent = u->parent;
}

template <typename T>
Node<T>* RedBlackTree<T>::search(T key) {
    Node<T>* current = root;
    while (current != nil && current->key != key) {
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

template <typename T>
void RedBlackTree<T>::inorderTraversal(Node<T>* node) {
    if (node != nil) {
        inorderTraversal(node->left);
        std::cout << "(" << node->key << ", " << node->value << ", " << (node->color == RED ? "RED" : "BLACK") << ") ";
        inorderTraversal(node->right);
    }
}

int main() {
    RedBlackTree<int> rbt;

    rbt.insert(10, "Thors");
    rbt.insert(34, "Canute");
    rbt.insert(43, "Olaf");
    rbt.insert(15, "Einer");
    rbt.insert(40, "Olmar");
    rbt.insert(53, "Floki");
    rbt.insert(90, "Thorfinn");
    rbt.insert(12, "Snake");
    rbt.insert(78, "Askeladd");

    rbt.inorderTraversal(rbt.getRoot());
    std::cout << std::endl;

    rbt.remove(15);
    rbt.remove(53);

    rbt.inorderTraversal(rbt.getRoot());
    std::cout << std::endl;

    return 0;
}
