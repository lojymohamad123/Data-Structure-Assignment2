// ============================================
// File: Book.h (Shared between BST and AVL)
// ============================================

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Book Structure
struct Book {
    int id;
    string title;
    string author;
    
    Book() {}
    Book(int id_num, string title_name, string author_name) {
        id = id_num;
        title = title_name;
        author = author_name;
    }
};

// ============================================
// FIXED DATA (Sorted IDs - 1 to 25)
// ============================================

inline vector<Book> getSortedBooksFixed() {
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

// ============================================
// FIXED DATA (Random IDs - unsorted)
// ============================================

inline vector<Book> getRandomBooksFixed() {
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

#endif // BOOK_H
