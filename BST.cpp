#include <iostream>
#include <string>
#include <algorithm>
#include <queue> //for breadth-first

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* Create_Root(int data){
    Node* root = new Node;
    root -> value = data;
    root -> left = nullptr;
    root -> right = nullptr;

    return root;
}

Node* Insert_Element(Node* root, int data){
    if (root == nullptr){
        return Create_Root(data);
    }

    if(data <= root->value){
        root->left = Insert_Element(root->left, data);
    }
    else if (data > root->value){
        root->right = Insert_Element(root->right, data);
    }

    return root;
}

bool Search_Element(Node* root, int data){
    if(root == nullptr){
        return false;
    }

    if(root->value == data){
        return true;
    }

    if(data <= root->value){
        return Search_Element(root->left, data);
    }
    else {
        return Search_Element(root->right, data);
    }
}

/* 3 possible cases exist for deleting a node from a tree
Case 1: Node has NO child
Case 2: Node has ONE child
Case 3: Node has TWO children

Case 1: Simply set root-> right or root->left to NULL
Case 2: Make the parent link directly to the grandchild
Case 3: (i) Find the MINIMUM value in the LEFT sub-tree
        (ii)Copy the value in the node to be deleted. Essentially, replace that value with a new one
        (iii)Delete the duplicate/copied value from the right subtree
                                OR
        (i) Find the MAXIMUM value in the LEFT sub-tree
        (ii)Copy the value in the node to be deleted. Essentially, replace that value with a new one
        (iii)Delete the duplicate/copied value from the right subtree 
*/
Node* Delete_Node(Node* root, int data){     
    // First step is to find the node in question
    if (root == NULL){
        return root;
    }

    else if(data < root->value){
        root->left = Delete_Node(root->left, data);
    } 

    else if(data > root->value){
        root->right = Delete_Node(root->right, data);
    }

    else{ //equal
        //Case 1: No child
        if(root->left == NULL && root->right == NULL){
            delete root; //deallocates from the heap
            root = NULL;
        }

        //Case 2: One child
        else if(root->left == NULL){ //One child: right 
            struct Node *temp = root;
            root = root->right;
            delete temp;
        }

        else if(root->right == NULL){ //One child: left 
            struct Node* temp = root;
            root = root-> left;
            delete temp;
        }

        //case 3: 2 children
        else{
            struct Node *temp = FindMin(root->right);
            root->value = temp->value;
            root->right = Delete_Node(root->right, temp->value);
        }

    }

    return root;
}

Node* FindMin(Node* root){ //Find Minimum in a subtree
    
    while(root->left != NULL){
        root = root->left;
    }
    
    return root;
}

/*Binary Tree Traversal

                                    10
                                /       \
                                7       15
                              /   \    /   \
                            4     9   8    19
Tree traversal: The process of visiting each node in the tree exactly once in some order
Visiting: reading/processing data in a node

Two categories: (these methods are also used in graphs. A tree is a type of graph.)
1. Breadth-First: Visit all nodes at the same depth/level before visiting those at the next level

Level-order
In above tree, that is: 10, 7, 15, 4, 9, 8, 19


2. Depth-First: 
Visit whole sub-tree up to grandchildren. Left-to-right or Right-to-left. Visiting a child involves visiting the entire sub-tree of that child
https://youtu.be/9RHO6jU--GU?si=8mNG7quuUCRrQlLL
Strategies: <root><left><right> - Preorder (DLR) -> F, D, B, A, C, E, J, G, I, H, K
            <left><root><right> - Inorder  (LDR) -> A, B, C, D, E, F, G, H, I, J, K. Inorder traversal of a BST gives you a sorted list.
            <left><right><root> - Postorder (LRD) -> A, C, B, E, D, H, I, G, K, J, F
Prefixes of order are based on stage at which "root" is visited, Pre (first), In (second/middle), Post(third/last)
*/

void Breadth_First(Node* root){
// The way to establish links across the levels (breadth) is to keep reference of each DISCOVERED node's children in a queue (FIFO).
// A DISCOVERED node is one which has been found but not yet read. Keeping its info enables links across the tree without returning to the root.
    if (root == NULL){
        return;
    }
    
    std::queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node* current = Q.front();
        std::cout << current->value << "\n";
        if(current->left != NULL){
            Q.push(current->left);
        }
        if(current->right != NULL){
            Q.push(current->right);
        }
        Q.pop();                                                //Time Complexity: O(n) - all cases. Each visit to a node involved printing it and inserting
                                                                // its children in the queue. A visit takes constant time and each node is visited once

                                                                //Space Complexity (rate of growth of extra memory used with input size) queue is growing and shrinking
                                                                // with each iteration/visit/discovery Maximum amount of extra memory used will depend
                                                                // on maximum amount of elements in the queue.
                                                                // O(1) - best; O(n) - worst/average
    }
}

int main(){
    Node* root = new Node;
    root = Create_Root(9);
    Insert_Element(root, 10);
    Insert_Element(root, 23);
    Insert_Element(root, 9);
    Insert_Element(root, 20);
    Insert_Element(root, 4);
    Insert_Element(root, 198);
    Insert_Element(root, 7);

    if(Search_Element(root, 9)){
        std::cout << "Found\n";
    }
    else{
        std::cout << "Not Found\n";
    }

    return 0;
}