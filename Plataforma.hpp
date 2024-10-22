#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP
#include <iostream>
#include <list>
#include <stack>
#include "Classificacio.hpp"
#include "LlibreE.hpp"
#include "PriorityQueue.hpp"
#include "BinaryTree.hpp"

using namespace std;


class Platform {

private:
Classification classifier;
Queue <Book> not_classificated;
list <Book> storage;

// Pre: the iterator a must be lower that the iterator b
// Post: it returns the distance between both iterators.
int dist_it(list<Book>::iterator a, list<Book>::iterator b);

// Pre: true.
// Post: it returns the iterator that points to the book or the inmediatly after if the book is not in the storage.
list <Book>::iterator dicotomic_search(list<Book> &l, Book x);


public:
    //*********************************************************
    // Builders
    //*********************************************************

    // Pre: true.
    // Post: it creates a platform with a queue and a list empty.
    Platform();

    // Pre: true.
    // Post: it creates a platform with an object Clasification that contains the binary tree and a list with all the nodes of the tree
    Platform(BinaryTree<string> &Tree);

    //*********************************************************
    // Destroyer
    //*********************************************************

    // default destroyer
    ~Platform();

    //*********************************************************
    // Consultors
    //*********************************************************

    // Pre: true.
    // Post: it returns a boolean value that is false if the book isn't in the storage list and true if there is.
    bool isInStorage(Book &b);

    //*********************************************************
    // Setters
    //*********************************************************

    // Pre: true.
    // Post: if the priority queue is not empty, it clasifitate all the books into the queue.
    void classify();

    // Pre: true.
    // Post: if the priority queue is not empty, it clasifiate the first book into the queue.
    void classifyBook();

    // Pre: true.
    // Post: if the book isn't in the storage it will be registrated and it will get in the priority queue
    void registerBook(string title, Date date, list <string> keywords);

    // Pre:
    // Post: if the book is in the storage it will be eliminated of the storage list.
    void eliminateBook(string &title);
    //*********************************************************
    // Reading and writting
    //*********************************************************

    // Pre: true.
    // Post: it prints the priority queue of the not clasificated books.
    void pendingsList();

    // Pre: true
    // Post: it prints the storage list into the standar channel output
    void writeStorage();

    // Pre: true
    // Post: it prints all book that belong to a topic.
    void showBooksTopic(string &topic);

};



#endif
