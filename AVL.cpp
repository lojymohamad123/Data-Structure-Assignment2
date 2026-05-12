#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

// Book structure
struct Book {
    int id ;
    string title ;
    string author ;

    Book(int id_num ,string title_name ,string author_name ){
        id = id_num ;
        title = title_name ;
        author = author_name ;

    }

};

//fixed data sorted ids (1 to 25)
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

// Node structure
struct Node {
    Book data;
    Node* left;
    Node* right;
    int height;

    Node(int id_num , string title_name , string author_name) : data (id_num,title_name,author_name) {
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
public:
    Node* root;

    AVL() {
        root = nullptr;
    }

    // Get height
    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Get balance factor
    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // Right rotation (LL case)
    Node* rightRotate(Node* parent) {
        Node* child = parent->left;
        Node* Temp = child->right;

        child->right = parent;
        parent->left = Temp;

        parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
        child->height = max(getHeight(child->left), getHeight(child->right)) + 1;

        return child ;
    }

    // Left rotation (RR case)
    Node* leftRotate(Node* parent) {
        Node* child = parent->right;
        Node* Temp = child->left;

        child->left = parent;
        parent->right = Temp;

        parent->height = max(getHeight(parent->left), getHeight(parent->right)) + 1;
        child->height = max(getHeight(child->left), getHeight(child->right)) + 1;

        return child ;
    }

    // Insert
    Node* insert(Node* node, int value , string title_name , string author_name) {

        // Normal BST insert
        if (node == nullptr)
            return new Node(value , title_name ,author_name);

        if (value < node->data.id)
            node->left = insert(node->left, value , title_name , author_name);
        else if (value > node->data.id)
            node->right = insert(node->right, value , title_name , author_name);
        else
            return node;

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get balance
        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && value < node->left->data.id)
            return rightRotate(node);

        // RR Case
        if (balance < -1 && value > node->right->data.id)
            return leftRotate(node);

        // LR Case
        if (balance > 1 && value > node->left->data.id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (balance < -1 && value< node->right->data.id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Find minimum
    Node* minValue(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Find maximum
    Node* maxValue(Node* node) {
        while (node->right != nullptr)
            node = node->right;
        return node;
    }

    // Delete
    Node* deleteNode(Node* node, int value ) {

        if (node == nullptr)
            return node;

        // BST delete
        if (value < node->data.id)
            node->left = deleteNode(node->left, value);
        else if (value > node->data.id)
            node->right = deleteNode(node->right, value);
        else {
            // one or zero child
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            }
            else {
                // two children
                Node* temp = minValue(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data.id);
            }
        }

        if (node == nullptr)
            return node;

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // LL
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        // LR
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RR
        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        // RL
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Search
    Node* search(Node* node, int value , int& steps) {
        steps++ ;
        if (node == nullptr || node->data.id == value )
            return node;

        if (value > node->data.id)
            return search(node->right, value , steps);

        return search(node->left,value , steps );

    }

    // search to find Closest ID
    Node* findClosestID(Node* node, int value , int& steps ) {
        Node* closest = node ;
        while (node != nullptr){
            steps++ ;
            if ( abs (node->data.id - value ) < abs (closest->data.id - value ) )
                closest = node ;

            if (value > node->data.id)
                node = node->right;
            
            else if (value < node->data.id)
                node = node->left ;

            else 
               return node ;
        }
        return closest ;
    
    }

    void AllBooksInRange (Node* node, int low , int high , vector <Node*>& result ){
        if (node==nullptr)
            return ;
        if (node->data.id > low)
           AllBooksInRange(node->left, low, high, result );

       if (node->data.id >= low && node->data.id <= high)
           result.push_back(node);

       if (node->data.id < high)
           AllBooksInRange(node->right, low, high, result );

    }
    // inorder Traversals
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << "Book ID : " << node->data.id << "  ,";
            cout << "Book Title : " << node->data.title << "  ,";
            cout << "Book Author : " << node->data.author << "  \n";
            inorder(node->right);
        }
    }

    void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

};

void demoAVL() {
    cout << "\n========== AVL SAMPLE RUN ==========" << endl;
    AVL tree;
    vector <Node*> result ;
    vector<Book> books = getSortedBooks() ;
    int steps = 0 ;
    cout << "\n[1] Inserting first 7 books..." << endl;
    // Insert ID: 1,2,3,4,5,6,7
    for (int i = 0; i < 7; i++)tree.root = tree.insert(tree.root, books[i].id , books[i].title , books[i].author);
    
    cout << "\n[2] In-order traversal (should show IDs 1-7):" << endl;
    tree.inorder(tree.root);
    
    cout << "\n[3] Search ID 4 (exists):" << endl;
    Node* found = tree.search(tree.root, 4 , steps);
    steps = 0 ;
    if (found) cout << "    Found: " << found->data.title << endl;
    
    cout << "\n[4] Search ID 100 (does NOT exist):" << endl;
    found = tree.search(tree.root, 100,steps);
    steps = 0 ;
    if (!found) cout << "    Not found (correct)" << endl;
    
    cout << "\n[5] Range search (IDs 3-10):" << endl;
    tree.AllBooksInRange(tree.root, 3, 10,result);
    
    // Test closest with a value NOT in the tree
    cout << "\n[6] Find closest ID to 7.5 (NOT in tree):" << endl;
    Node* closest = tree.findClosestID(tree.root, 7 , steps); 
    steps = 0 ;
    cout << "   Closest ID to 7 is: " << closest->data.id << endl;
    
    cout << "\n[7] Find closest ID to 100 (NOT in tree):" << endl;
    Node* closest = tree.findClosestID(tree.root, 100 , steps);
    steps = 0 ;
    cout << "   Closest ID to 100 is: " << closest->data.id << " (should be 7)" << endl;
    
    cout << "\n[8] Delete ID 4:" << endl;
    tree.root = tree.deleteNode(tree.root, 4);
    cout << "   After deletion, in-order traversal (ID 4 missing):" << endl;
    tree.inorder(tree.root);
    
    cout << "\n[9] Tree Height: " << tree.getHeight(tree.root) << endl;
    Node* element =  tree.search(tree.root, 6, steps) ;
    cout << "\n[10] Search steps for ID 6: " << steps << endl;
    
    tree.deleteTree(tree.root) ;
    cout << "\n========== AVL DEMO COMPLETED ==========" << endl;
}
