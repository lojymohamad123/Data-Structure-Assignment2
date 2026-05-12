#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

// FIXED DATA 
// Sorted IDs (1 to 25)

vector<Book> getSortedBooks() {
    vector<Book> books = {
        {1, "Data Structures Basics", "A. Smith"},
        {2, "Algorithms Unlocked", "B. Johnson"},
        {3, "Operating Systems Concepts", "C. Lee"},
        {4, "Database Systems Intro", "D. Kumar"},
        {5, "Computer Networks", "E. Brown"},
        {6, "Artificial Intelligence Basics", "F. Davis"},
        {7, "Machine Learning Intro", "G. Wilson"},
        {8, "Deep Learning Guide", "H. Moore"},
        {9, "Software Engineering Principles", "I. Taylor"},
        {10, "Design Patterns Explained", "J. Anderson"},
        {11, "Python Programming", "K. Thomas"},
        {12, "Java Fundamentals", "L. Jackson"},
        {13, "C++ Essentials", "M. White"},
        {14, "Web Development Basics", "N. Harris"},
        {15, "Django Framework Guide", "O. Martin"},
        {16, "SQL Mastery", "P. Thompson"},
        {17, "Computer Architecture", "Q. Garcia"},
        {18, "Discrete Mathematics", "R. Martinez"},
        {19, "Theory of Computation", "S. Robinson"},
        {20, "Mobile App Development", "T. Clark"},
        {21, "Cyber Security Basics", "U. Rodriguez"},
        {22, "Cloud Computing Intro", "V. Lewis"},
        {23, "Big Data Analytics", "W. Walker"},
        {24, "Data Science Handbook", "X. Hall"},
        {25, "Problem Solving Techniques", "Y. Allen"}
    };
    return books;
}

// Random IDs (unsorted)
vector<Book> getRandomBooks() {
    vector<Book> books = {
        {12, "Data Structures Basics", "A. Smith"},
        {87, "Algorithms Unlocked", "B. Johnson"},
        {34, "Operating Systems Concepts", "C. Lee"},
        {150, "Database Systems Intro", "D. Kumar"},
        {66, "Computer Networks", "E. Brown"},
        {91, "Artificial Intelligence Basics", "F. Davis"},
        {23, "Machine Learning Intro", "G. Wilson"},
        {58, "Deep Learning Guide", "H. Moore"},
        {199, "Software Engineering Principles", "I. Taylor"},
        {44, "Design Patterns Explained", "J. Anderson"},
        {73, "Python Programming", "K. Thomas"},
        {120, "Java Fundamentals", "L. Jackson"},
        {5, "C++ Essentials", "M. White"},
        {168, "Web Development Basics", "N. Harris"},
        {39, "Django Framework Guide", "O. Martin"},
        {102, "SQL Mastery", "P. Thompson"},
        {77, "Computer Architecture", "Q. Garcia"},
        {185, "Discrete Mathematics", "R. Martinez"},
        {11, "Theory of Computation", "S. Robinson"},
        {96, "Mobile App Development", "T. Clark"},
        {141, "Cyber Security Basics", "U. Rodriguez"},
        {60, "Cloud Computing Intro", "V. Lewis"},
        {28, "Big Data Analytics", "W. Walker"},
        {175, "Data Science Handbook", "X. Hall"},
        {83, "Problem Solving Techniques", "Y. Allen"}
    };
    return books;
}

struct BSTNode {
    Book book;
    BSTNode* left;
    BSTNode* right;
};

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
    for (const auto& book : books) root = insertBST(root, book);
    return root;
}

void demoBST() {
    cout << "\n========== BST SAMPLE RUN ==========" << endl;
    BSTNode* root = nullptr;
    vector<Book> demoBooks = getSortedBooks();
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
