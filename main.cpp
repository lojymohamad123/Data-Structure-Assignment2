#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#include "Book.h"
#include "BST.h"
#include "AVL.h"

void runComparison() {
    int numBooks = 25;
    
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║              BST vs AVL COMPARISON REPORT                  ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    // CASE 1: RANDOM IDs
    cout << "\n📊 CASE 1: RANDOM IDs (" << numBooks << " books)\n";
    cout << "----------------------------------------\n";
    
    vector<Book> randomBooks = getRandomBooksFixed();
    
    BSTNode* bstRoot = buildBSTFromBooks(randomBooks);
    int bstHeight = getHeightBST(bstRoot);
    int searchId = randomBooks[12].id;
    int bstSteps = getSearchStepsBST(bstRoot, searchId, 0);
    
    AVL avlTree;
    for (const auto& book : randomBooks) {
        avlTree.root = avlTree.insert(avlTree.root, book.id, book.title, book.author);
    }
    int avlHeight = avlTree.getHeight(avlTree.root);
    int avlSteps = 0;
    avlTree.search(avlTree.root, searchId, avlSteps);
    
    cout << "   BST Height:           " << bstHeight << endl;
    cout << "   AVL Height:           " << avlHeight << endl;
    cout << "   BST Search steps for ID " << searchId << ": " << bstSteps << endl;
    cout << "   AVL Search steps for ID " << searchId << ": " << avlSteps << endl;
    
    deleteTreeBST(bstRoot);
    avlTree.deleteTree(avlTree.root);
    
    // CASE 2: SORTED IDs
    cout << "\n📊 CASE 2: SORTED IDs (" << numBooks << " books)\n";
    cout << "----------------------------------------\n";
    
    vector<Book> sortedBooks = getSortedBooksFixed();
    
    bstRoot = buildBSTFromBooks(sortedBooks);
    bstHeight = getHeightBST(bstRoot);
    searchId = sortedBooks[12].id;
    bstSteps = getSearchStepsBST(bstRoot, searchId, 0);
    
    AVL avlTree2;
    for (const auto& book : sortedBooks) {
        avlTree2.root = avlTree2.insert(avlTree2.root, book.id, book.title, book.author);
    }
    avlHeight = avlTree2.getHeight(avlTree2.root);
    avlSteps = 0;
    avlTree2.search(avlTree2.root, searchId, avlSteps);
    
    cout << "   BST Height:           " << bstHeight << endl;
    cout << "   AVL Height:           " << avlHeight << endl;
    cout << "   BST Search steps for ID " << searchId << ": " << bstSteps << endl;
    cout << "   AVL Search steps for ID " << searchId << ": " << avlSteps << endl;
    
    deleteTreeBST(bstRoot);
    avlTree2.deleteTree(avlTree2.root);
    
    cout << "\n📝 CONCLUSION:\n";
    cout << "----------------------------------------\n";
    cout << "   • BST with sorted data becomes skewed (height is large)\n";
    cout << "   • AVL maintains balance even with sorted data\n";
    cout << "   • AVL is better when search performance must be guaranteed\n";
    cout << "\n==========================================\n";
}

int main() {
    cout << "========================================\n";
    cout << "   SMART LIBRARY BOOK MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    
    demoBST();
    
    AVL avlTree;
    avlTree.demoAVL();
    
    runComparison();
    
    cout << "\n✅ PROGRAM COMPLETED SUCCESSFULLY!\n";
    
    return 0;
}