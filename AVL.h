#ifndef AVL_H
#define AVL_H

#include <string>
#include <vector>
using namespace std;

#include "Book.h"

struct Node {
    Book data;
    Node* left;
    Node* right;
    int height;
    Node(int id_num, string title_name, string author_name);
};

class AVL {
public:
    Node* root;
    AVL();
    int getHeight(Node* node);
    int getBalance(Node* node);
    Node* rightRotate(Node* parent);
    Node* leftRotate(Node* parent);
    Node* insert(Node* node, int value, string title_name, string author_name);
    Node* minValue(Node* node);
    Node* maxValue(Node* node);
    Node* deleteNode(Node* node, int value);
    Node* search(Node* node, int value, int& steps);
    Node* findClosestID(Node* node, int value, int& steps);
    void AllBooksInRange(Node* node, int low, int high, vector<Node*>& result);
    void inorder(Node* node);
    void deleteTree(Node* root);
    void demoAVL();
};

#endif
