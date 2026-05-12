
#ifndef BST_H
#define BST_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Include shared Book structure
#include "Book.h"

// ============================================
// BST Node Structure
// ============================================

struct BSTNode {
    Book book;
    BSTNode* left;
    BSTNode* right;
};

// ============================================
// BST Function Declarations
// ============================================

BSTNode* createNode(Book b);
BSTNode* insertBST(BSTNode* root, Book b);
BSTNode* findMinBST(BSTNode* root);
BSTNode* deleteBST(BSTNode* root, int id);
BSTNode* searchBST(BSTNode* root, int id);
void inorderBST(BSTNode* root);
void rangeSearchBST(BSTNode* root, int minId, int maxId);
int findClosestHelperBST(BSTNode* root, int target, int closestSoFar);
int findClosestBST(BSTNode* root, int target);
int getHeightBST(BSTNode* root);
int getSearchStepsBST(BSTNode* root, int id, int steps);
void deleteTreeBST(BSTNode* root);
BSTNode* buildBSTFromBooks(const vector<Book>& books);
void demoBST();

// ============================================
// BST Function Implementations
// ============================================

BSTNode* createNode(Book b) {
    BSTNode* newNode = new BSTNode();
    newNode->book = b;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

BSTNode* insertBST(BSTNode* root, Book b) {
    if (root == nullptr) return createNode(b);
    if (b.id < root->book.id)
        root->left = insertBST(root->left, b);
    else if (b.id > root->book.id)
        root->right = insertBST(root->right, b);
    return root;
}

BSTNode* findMinBST(BSTNode* root) {
    while (root && root->left) root = root->left;
    return root;
}

BSTNode* deleteBST(BSTNode* root, int id) {
    if (!root) return nullptr;
    if (id < root->book.id)
        root->left = deleteBST(root->left, id);
    else if (id > root->book.id)
        root->right = deleteBST(root->right, id);
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        } else {
            BSTNode* temp = findMinBST(root->right);
            root->book = temp->book;
            root->right = deleteBST(root->right, temp->book.id);
        }
    }
    return root;
}

BSTNode* searchBST(BSTNode* root, int id) {
    if (!root || root->book.id == id) return root;
    if (id < root->book.id) return searchBST(root->left, id);
    return searchBST(root->right, id);
}

void inorderBST(BSTNode* root) {
    if (!root) return;
    inorderBST(root->left);
    cout << "ID: " << root->book.id << " | " << root->book.title << " | " << root->book.author << endl;
    inorderBST(root->right);
}

void rangeSearchBST(BSTNode* root, int minId, int maxId) {
    if (!root) return;
    if (root->book.id > minId) rangeSearchBST(root->left, minId, maxId);
    if (root->book.id >= minId && root->book.id <= maxId)
        cout << "ID: " << root->book.id << " | " << root->book.title << endl;
    if (root->book.id < maxId) rangeSearchBST(root->right, minId, maxId);
}

int findClosestHelperBST(BSTNode* root, int target, int closestSoFar) {
    if (!root) return closestSoFar;
    if (abs(root->book.id - target) <= abs(closestSoFar - target))
        closestSoFar = root->book.id;
    if (target < root->book.id)
        return findClosestHelperBST(root->left, target, closestSoFar);
    else if (target > root->book.id)
        return findClosestHelperBST(root->right, target, closestSoFar);
    return root->book.id;
}

int findClosestBST(BSTNode* root, int target) {
    if (!root) return -1;
    return findClosestHelperBST(root, target, root->book.id);
}

int getHeightBST(BSTNode* root) {
    if (!root) return 0;
    return 1 + max(getHeightBST(root->left), getHeightBST(root->right));
}

int getSearchStepsBST(BSTNode* root, int id, int steps) {
    if (!root) return steps;
    steps++;
    if (root->book.id == id) return steps;
    if (id < root->book.id) return getSearchStepsBST(root->left, id, steps);
    return getSearchStepsBST(root->right, id, steps);
}

void deleteTreeBST(BSTNode* root) {
    if (!root) return;
    deleteTreeBST(root->left);
    deleteTreeBST(root->right);
    delete root;
}

BSTNode* buildBSTFromBooks(const vector<Book>& books) {
    BSTNode* root = nullptr;
    for (const auto& book : books) {
        root = insertBST(root, book);
    }
    return root;
}

// ============================================
// Demo Function (النسخة الجديدة اللي انتي عايزاها)
// ============================================

void demoBST() {
    cout << "\n========== BST SAMPLE RUN ==========" << endl;
    BSTNode* root = nullptr;
    vector<Book> demoBooks = getSortedBooksFixed();
    cout << "\n[1] Inserting first 7 books..." << endl;
    // Insert ID: 1,2,3,4,5,6,7
    for (int i = 0; i < 7; i++) root = insertBST(root, demoBooks[i]);
    
    cout << "\n[2] In-order traversal (should show IDs 1-7):" << endl;
    inorderBST(root);
    
    cout << "\n[3] Search ID 4 (exists):" << endl;
    BSTNode* found = searchBST(root, 4);
    if (found) cout << "    Found: " << found->book.title << endl;
    
    cout << "\n[4] Search ID 100 (does NOT exist):" << endl;
    found = searchBST(root, 100);
    if (!found) cout << "    Not found (correct)" << endl;
    
    cout << "\n[5] Range search (IDs 3-10):" << endl;
    rangeSearchBST(root, 3, 10);
    
    // Test closest with a value NOT in the tree
    cout << "\n[6] Find closest ID to 7.5 (NOT in tree):" << endl;
    int closest = findClosestBST(root, 7); 
    cout << "   Closest ID to 7 is: " << closest << endl;
    
    cout << "\n[7] Find closest ID to 100 (NOT in tree):" << endl;
    closest = findClosestBST(root, 100);
    cout << "   Closest ID to 100 is: " << closest << " (should be 7)" << endl;
    
    cout << "\n[8] Delete ID 4:" << endl;
    root = deleteBST(root, 4);
    cout << "   After deletion, in-order traversal (ID 4 missing):" << endl;
    inorderBST(root);
    
    cout << "\n[9] Tree Height: " << getHeightBST(root) << endl;
    
    cout << "\n[10] Search steps for ID 6: " << getSearchStepsBST(root, 6, 0) << endl;
    
    deleteTreeBST(root);
    cout << "\n========== BST DEMO COMPLETED ==========" << endl;
}

#endif // BST_H
