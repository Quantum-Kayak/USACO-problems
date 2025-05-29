# 🌳 Binary Trees in C++

A **binary tree** is a data structure in which each node has at most two children, usually called the left child and the right child. It’s like a family tree, but with fewer awkward reunions.

---

## 🏗️ Structure of a Binary Tree Node

A simple binary tree node in C++ typically looks like this:

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
```
This defines a Node with a constructor, because we’re fancy like that.

## ⚙️ Insertion Function
Here’s a basic example of how to insert a new value into a binary search tree (BST):
```cpp
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}
```
This function places smaller values on the left and larger ones on the right. No balancing or self-respect included.

## 🔍 Inorder Traversal (Just to Show Off)
Here’s a way to traverse the tree in “inorder” (left, root, right):
```cpp
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}
```
This will print the values in ascending order, like your social anxiety when meeting new people.

## 💡 Putting It All Together
Here’s a tiny example of usage:
```cpp
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);

    std::cout << "Inorder traversal: ";
    inorder(root);

    return 0;
}
```
## 📝 Conclusion
Binary trees in C++ are pretty straightforward once you understand that you’re just gluing nodes together. And yes, they’re pretty easy to implement, so if you mess this up, that’s on you. Happy coding!
