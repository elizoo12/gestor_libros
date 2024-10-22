#ifndef CLASSIFICACIO_HPP
#define CLASSIFICACIO_HPP
#include <iostream>
#include "BinaryTree.hpp"
#include "LlibreE.hpp"

using namespace std;


class Classification {

private:
    BinaryTree<string> scheme;

    // Pre: true
    // Post: keywords will contain one element that is the lower common father of all elements of the keywords
    void searchTopic(list<string>&keywords);

public:


    //*********************************************************
    // Builders
    //*********************************************************

    // Pre: true
    // Post: it creates an object Classification with a binary tree for string and a list for strings
    Classification();

    // Pre: true
    // Post: it creates an object Classification with the binary tree of the parameter and a list filled by all topics of the tree
    Classification(BinaryTree<string> Tree);


    //*********************************************************
    // Destroyer
    //*********************************************************

    // default destroyer
    ~Classification();

    //*********************************************************
    // Getter
    //*********************************************************

    // Pre: true.
    // Post: it returns a boolean value, true if the string topic is into the list topics and false if not.
    bool inTopics(string &topic)const;

    //*********************************************************
    // Setters
    //*********************************************************

    // Pre: true
    // Post: the list topics contain all the nodes of the binary tree tree
    void setScheme(BinaryTree<string>&tree);

    // Pre: true
    // Post: the topic's book will contain the topic of the book
    void classify(Book &b);

};

#endif
