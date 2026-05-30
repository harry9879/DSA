#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

// class BST{
//     public:
//     Node* root;

//     BST() {
//         root = NULL;
//     }

//     void insertBST(Node* root, int val) {
//         Node* newNode = new Node(val);

//         if (root == NULL) {
//             root = newNode;
//             return;
//         }

//         Node*current = root;

//         while(true) {
//             if (current->value > val) {
//                 if (current->left == NULL) {
//                     current->left= newNode;
//                     return;
//                 }
//                 current = current->left;
//             } else {
//                 if (current->right == NULL){
//                     current->right = newNode;
//                     return;
//                 }

//                 current = current->right;
//             }
//         }
//     }
// };
//
// int main() {
// return 0;
// }

Node *largestNodeBST(Node *root)
{
    Node *curr = root;
    while (curr && curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr;
}

Node *deleteBST(Node *root, int key)
{

    if (root == NULL)
    {
        return root;
    }

    if (root->value < key)
    {
        root->right = deleteBST(root->right, key);
    }
    else if (root->value > key)
    {
        root->left = deleteBST(root->left, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *justSmallerNode = largestNodeBST(root->left);
            root->value = justSmallerNode->value;
            root->left = deleteBST(root->left, justSmallerNode->value);
        }
    };
    return root;
}
Node *insertBST(Node *root, int val)
{

    if (root == NULL)
    {
        Node *newNode = new Node(val);
        return newNode;
    }
    if (val < root->value)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
};

bool searchBST(Node *root, int key)
{

    if (root == NULL)
    {
        return false;
    }

    //       10
    //    4      15
    //  2   5  11   19

    // 10 < 15
    if (root->value < key)
    {
        return searchBST(root->right, key);
    }
    else if (root->value > key)
    {
        return searchBST(root->left, key);
    }
    else if (root->value == key)
    {
        return true;
    }
}

int main()
{
    Node *root = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insertBST(root, x);
    };

    inorder(root);
    cout << searchBST(root, 11);
    return 0;
}