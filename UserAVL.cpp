#include "UserAVL.h"

User::User(int id, string name, string email, string creationDate): id(id), name(name), email(email), creationDate(creationDate) {} //user constructor

Node::Node(User *user): user(user), left(nullptr), right(nullptr), height(1) {} //node constructor, these nodes store user data

AVLTree::AVLTree() : root(nullptr) {} //AVL tree constructor, sets the root to a nullptr, meaning the tree starts as empty

int AVLTree::height(Node *node) {   //'?' is used as a simple if-else statement. 
    return node ? node->height : 0; //'?' checks if node is not null. If condition is true -> 'node->height'. If false -> '0'
};

int AVLTree::getBalance(Node *node) {                           //calculation of balance
    return node ? height(node->left) - height(node->right) : 0; //height: length of the longest path from the node to a leaf-node
}

Node *AVLTree::rightRotate(Node *y) { //when node y is unbalanced
    Node* x = y->left; //assigns x to be the left child of y
    Node* z = x->right; //assigns z to be the right child of x

    x->right = y; //makes y the right child of x, x becomes the new root of the subtree
    y->left = z; //makes z the left child of y

    y->height = max(height(y->left), height(y->right)) +1; //max returns larger from the two arguments passed
    x->height = max(height(x->left), height(x->right)) + 1; //take the larger leaf-node's height, add 1 to it and it becomes the new height

    return x;
}

Node *AVLTree::leftRotate(Node *x) { //when node x is unbalanced
    Node* y = x->right; //y becomes the right child of x
    Node* z = y->left; //z becomes the left child of y

    y->left = x; //makes x the left child of y
    x->right = z; //makes z the right child of x

    x->height = max(height(x->left), height(x->right)) +1;
    y->height = max(height(y->left), height(y->right)) +1;

    return y;
}

Node *AVLTree::insert(Node *node, User *user) {
    if(!node) return new Node(user); //if node is nullptr, position to insert has been found, a new user node is created

    if(user->id < node->user->id) {
        node -> left = insert(node->left, user); //move to left subtree and insert
    } else if(user->id > node->user->id) {
        node->right = insert(node->right, user); //move to right subtree and insert
    } else {
        return node; //keys can't have duplicates, return the node that has the current key
    }

    node->height = 1 + max(height(node->left), height(node->right)); //update height of current node


    int balance = getBalance(node); //calculate and get the new balance of the current node

    if(balance > 1 && user->id < node->left->user->id) { //fix the balance, left-left case
        return rightRotate(node);
    }

    if(balance < -1 && user->id > node->right->user->id) { //right-right case
        return leftRotate(node);
    }

    if(balance > 1 && user->id > node->left->user->id) { //left-right case
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && user->id < node->right->user->id) { //right-left case
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;

}

User* AVLTree::search(Node* node, int id) { //search user by id
    if (!node) {
        cout << "User " << id << " not found." << endl;
        return nullptr; //user not found case
    }

    if (node->user->id == id) { //user found case
        //return node->user;
        cout << "User " << id << " found in " << node->user << endl;
    }

    if (id < node->user->id) { //user in left subtree
        return search(node->left, id);
    }

    if (id > node->user->id) { //user in right subtree
        return search(node->right, id);
    }
}

//go through the tree in order and print the users' data
void AVLTree::inorder(Node* root) {
    if (!root)
        return;

    inorder(root->left);
    std::cout << "ID: " << root->user->id << ", Name: " << root->user->name
         << ", Email: " << root->user->email
         << ", Creation date: " << root->user->creationDate << endl;
    inorder(root->right);
}



