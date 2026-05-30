// #include <iostream>
// using namespace std;


// int maxDepth(Node* root) {

//     // base case 
//     if (root == NULL ){
//         return 0;
//     }
//     int leftDept = maxDepth(root->left);
//     int rightDept = maxDept(root-> right);

//     return max(leftDepth, rightDepth) + 1;
// }

// int leafNodes(Node *root) {
//     if (root == NULL ){
//         return 0;
//     }
//     if (root -> left || root -> right ){
//         return 1;
//     }
//     int leftSubtreeLeafNodes = leafNodes(root -> left);
//     int rightSubtreeLeafNodes = leafNodes(root -> right);

//     return leftSubtreeLeafNodes + rightSubtreeLeafNodes;
// }


// vector<int> rightView(Node *root) {

//     vec<int> ans;
//     if (root == NULL ){ 
//         return ans;
//     }

//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()){
//         int nodesAtCurrentLevel = q.size();

//         while(nodesAtCurrentLevel) {
//             Node* currNode = q.front();
//             q.pop();

//             if(nodesAtCurrentLevel == 1) {
//                 ans.push_back(currNode->value);
//             }

//         }

//     }
// }

// vector<int> rightViewBinaryTree(Node * root) {
//     //      3
//     //  4      5
//     //2  7   22 44


//     vector<int> ans;
//     if (root == NULL) {
//         return ans;
//     }

//     queue<Node*> q;
//     q.push(root);
//     // [3]

//     while(!q.empty() ){
//         int nodesAtCurrentLevel = q.size();
//         // nodesAtcurrentlevel = 1;
//         while(nodesAtCurrentLevel) {

//             Node* currNode = q.front();
//             // currNode = 5
//             q.pop();
//             // [2,7]

//             if(nodesAtCurrentLevel == 1){
//                 ans.push_back(currNode->value);
//                 // [3, 5]
                
//             }

//             if(currNode-> left) {
//                 q.push(currNode -> left);
//                 // []
//             }
//             if(currNode-> right) {
//                 q.push(currNode -> right);
//                 // [5,2,7]
                
//             }
//             nodesAtCurrentLevel--;
//         }
//     }
// }



// int main() {
//     return 0;
// }

// class Solution {
// public:

//     int pathSumHelper(TreeNode* root, int targetSum, long currSum,
//                       unordered_map<long, int>& pathCount) {

//         if (root == NULL) {
//             return 0;
//         }

//         // Add current node value to prefix sum
//         currSum += root->val;

//         // Check if there exists a prefix sum that we can subtract
//         int ansCount = 0;
//         if (pathCount.find(currSum - targetSum) != pathCount.end()) {
//             ansCount = pathCount[currSum - targetSum];
//         }

//         // Add current prefix sum to map
//         pathCount[currSum]++;

//         // Recur left + right
//         ansCount += pathSumHelper(root->left, targetSum, currSum, pathCount);
//         ansCount += pathSumHelper(root->right, targetSum, currSum, pathCount);

//         // Backtrack (VERY IMPORTANT)
//         pathCount[currSum]--;

//         return ansCount;
//     }

//     int pathSum(TreeNode* root, int targetSum) {
//         unordered_map<long, int> pathCount;

//         // Base case: prefix sum 0 occurs once
//         pathCount[0] = 1;

//         return pathSumHelper(root, targetSum, 0, pathCount);
//     }
// };


// class Solution {
//     public:

//     int pathSumHelper(TreeNode* root, int targetSum, long currSum, unordered_map<long int, int> & pathCount) {

//         if (root == NULL) {
//             return 0;
//         }

//         int ansCount = 0;

//         if (pathCount.find(currSum - targetSum) != pathCount.end()) {
//             ansCount = pathCount[currSum - targetSum];
//         }

//         pathCount[currSum] ++;

//         ansCount +=pathSumHelper(root->left, targetSum, currSum, pathCount);
//         ansCount += pathSumHelper(root->right, targetSum, currSum, pathCount);

//         pathCount[currSum] --;

//         return ansCount;
//     }
    
//     int pathSum(TreeNode * root, int targetSum) {
//         unordered_map<long int , int> pathCount;

//         pathCount[0] = 1;

//         return pathSumHelper(root, targetSum, 0, pathCount);
//     }
// }


#include <iostream>
using namespace std;

// // Define Node structure
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

// // Insert into BST (return updated root)
// Node* insertBST(Node* root, int val) {

//     Node* newNode = new Node(val);

//     if (root == NULL) {
//         return newNode;   // important
//     }

//     Node* current = root;

//     while (true) {
//         if (val < current->value) {
//             if (current->left == NULL) {
//                 current->left = newNode;
//                 return root;
//             }
//             current = current->left;
//         }
//         else {
//             if (current->right == NULL) {
//                 current->right = newNode;
//                 return root;
//             }
//             current = current->right;
//         }
//     }
// }

// Inorder Traversal (to verify BST)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

Node* insertBST(Node* root, int val) {

    // base case 
    if(root == NULL ){
        Node* newNode = new Node(val);
        return newNode;
    }

    if(root->value > val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right , val);
    }

    return root;
}

int main() {

    Node* root = NULL;

    root = insertBST(root, 10);
    root = insertBST(root, 5);
    root = insertBST(root, 15);
    root = insertBST(root, 3);
    root = insertBST(root, 17);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}


