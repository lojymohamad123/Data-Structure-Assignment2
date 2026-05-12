#ifndef AVL_H
#define AVL_H

#include<string>
#include<vector>
using namespace std ;

struct Book {
    int id ;
    string title ;
    string author ;

    Book(int id_num ,string title_name ,string author_name ) ;

};

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

struct Node {
    Book data;
    Node* left;
    Node* right;
    int height;

    Node(int id_num , string title_name , string author_name) : data (id_num,title_name,author_name) {}
};


class AVL {
public:
    Node* root;

    AVL() ;

    // Get height
    int getHeight(Node* node) ;

    // Get balance factor
    int getBalance(Node* node) ;

    Node* rightRotate(Node* parent) ;

    Node* leftRotate(Node* parent) ;

    Node* insert(Node* node, int value , string title_name , string author_name) ;

    Node* minValue(Node* node) ;

    Node* maxValue(Node* node) ;

    Node* deleteNode(Node* node, int value ) ;

    Node* search(Node* node, int value , int& steps) ;

    Node* findClosestID(Node* node, int value , int& steps ) ;

    void AllBooksInRange (Node* node, int low , int high , vector <Node*>& result ) ;

    void inorder(Node* node) ;

    void deleteTree(Node* root) ;

    void demoAVL() ;
};    


#endif // AVL_H
