#include "Classificacio.hpp"
using namespace std;

//*********************************************************
// Builders
//*********************************************************

// Pre: true
// Post: it creates an object Classification with a binary tree for string and a list for strings
Classification::Classification(){

}

// Pre: true
// Post: it creates an object Classification with the binary tree of the parameter and a list filled by all topics of the tree
Classification::Classification(BinaryTree<string> Tree){
    scheme=Tree;
}


//*********************************************************
// Destroyer
//*********************************************************

// Default destroyer
Classification::~Classification(){

}

//*********************************************************
// Getter
//*********************************************************



// Pre: true.
// Post: it returns a boolean value, true if the string topic is into the list topics and false if not.
bool Classification::inTopics(string &topic)const{

  return scheme.search(topic);
}

//*********************************************************
// Setters
//*********************************************************


// Pre: true
// Post: keywords will contain one element that is the lower common father of all elements of the keywords
void Classification::searchTopic(list<string> &keywords){
  if(keywords.size() > 1){
      list<string>::iterator it = keywords.begin();
      string a = (*it);
      it = keywords.erase(it);
      string b = (*it);
      it = keywords.erase(it);
      string c = scheme.search_lower_common_father(a,b);
      keywords.insert(it,c);
      searchTopic(keywords);
      //H.I: keywords will contain one element that is the lower father of all elements of the actual keywords.
      //FITA: keywords size will decrease.
  }
}

// Pre: true
// Post: the list topics contain all the nodes of the binary tree tree
void Classification::setScheme(BinaryTree<string>&tree){
  scheme = tree;
}

// Pre: true
// Post: the topic's book will contain the topic of the book
void Classification::classify(Book &b){
    list<string> keywords= b.getKeywords();
    searchTopic(keywords);
    list<string>::iterator it=keywords.begin();
    b.setTopic((*it));

}
