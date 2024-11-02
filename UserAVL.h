#ifndef USERAVL_H
#define USERAVL_H
#include <string>
#include <iostream>
using namespace std;

class User {
public:
    int id;
    string name;
    string email;
    string creationDate;

    User(int id, string name, string email, string creationDate);
};

class Node {
public:
    User* user;
    Node* left;
    Node* right;
    int height;

    Node(User* user);
};

class AVLTree {
public:
    Node* root;

    AVLTree();

    int height(Node* node);
    int getBalance(Node* node);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* insert(Node* node, User* user);
    User* search(Node* node, int id);
    void inorder(Node* node);
};

#endif
