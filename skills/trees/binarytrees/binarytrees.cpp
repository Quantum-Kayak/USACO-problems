#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Define the Node structure
struct Node {
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int v) : val(v) {}
};

int main() {
    int n;
    cin >> n;

    // Create an array of Node pointers
    vector<Node*> nodes(n + 1, nullptr);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
    }

    // Read in the edges (parent, child) and build the tree
    for (int i = 0; i < n - 1; i++) {
        int p, c;
        cin >> p >> c;

        // Attach child to first empty side of parent
        if (!nodes[p]->left)
            nodes[p]->left = nodes[c];
        else
            nodes[p]->right = nodes[c];
    }

    // Now you have the tree rooted at nodes[1]
    Node* root = nodes[1];

    // Print the tree in pre-order to verify
    cout << "Pre-order traversal: ";
    function<void(Node*)> dfs = [&](Node* node) {
        if (!node) return;
        cout << node->val << " ";
        dfs(node->left);
        dfs(node->right);
    };
    dfs(root);
    cout << endl;

    // Clean up memory (delete the entire tree recursively)
    function<void(Node*)> destroy = [&](Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    };
    destroy(root);

    return 0;
}
