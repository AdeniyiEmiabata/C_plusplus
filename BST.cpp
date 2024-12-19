#include <iostream>
#include <string>
#include <algorithm>

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

    return root;
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