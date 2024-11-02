#include <iostream>
#include "UserAVL.h"

int main()
{
    AVLTree tree; //create a tree

    //create users
    User* user1 = new User(1, "Alice", "alice@example.com", "2024-01-01");
    User* user2 = new User(2, "Bob", "bob@example.com", "2024-01-02");
    User* user3 = new User(3, "Charlie", "charlie@example.com", "2024-01-03");

    //insert users to the tree
    tree.root = tree.insert(tree.root, user1);
    tree.root = tree.insert(tree.root, user2);
    tree.root = tree.insert(tree.root, user3);

    //search for users in the tree
    tree.search(tree.root, 1);
    tree.search(tree.root, 2);
    tree.search(tree.root, 3);
    tree.search(tree.root, 4);

    //show the users in order
    cout << "Stored users in the AVL tree:" << endl;
    tree.inorder(tree.root);

    return 0;
}
