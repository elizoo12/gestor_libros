#include "Plataforma.hpp"
using namespace std;
//*********************************************************
// Builders
//*********************************************************

//Pre: true.
//Post: it creates a platform with a queue and a list empty.
Platform::Platform(){
    not_classificated = {};
}

// Pre: true.
// Post: it creates a platform with an object Clasification that contains the binary tree and a list with all the nodes of the tree
Platform::Platform(BinaryTree<string> &Tree){
    classifier.setScheme(Tree);
}

//*********************************************************
// Destroyer
//*********************************************************
// default destroyer
Platform::~Platform(){

}

///*********************************************************
// Consultors
//*********************************************************

// Pre: true.
// Post: it returns a boolean value that is false if the book isn't in the storage list and true if there is.
bool Platform::isInStorage(Book &b){
    bool there_is;
    list<Book>::iterator it=dicotomic_search(storage,b);
    if(storage.empty() or it == storage.end()){
        there_is = false;
    }else{
        if(b==(*it)){
            there_is=true;
        }else{
            there_is=false;
        }
    }


    return there_is;
}

// Pre: the iterator a must be lower that the iterator b
// Post: it returns the distance between both iterators.
int Platform::dist_it(list<Book>::iterator a, list<Book>::iterator b){
    int result = 0;
    while(a != b){
        //INV: it count the distance between a and b.
       ++a;
       ++result;
    }
    return result;
}
// Pre: true.
// Post: it returns the iterator that points to the book or the inmediatly after if the book is not in the storage.
list <Book>::iterator Platform::dicotomic_search(list<Book> &l, Book x){

    list<Book>::iterator it1 = l.begin(), it2, it3 = l.end(), result;
    if(l.size() == 0){
        result = it3;
    }else{
        --it3;
        if(l.size() == 1){

            if(x>(*it1)){
                result = it1;

            }else{
                result = l.end();
            }
        }else if((*it1) == x){
            result = it1;
        }else if((*it3) == x){
            result = it3;
        }else{
            bool encontrado = false;
            while(not encontrado){
                //INV: it look for the iterator that points to the book x
                //or the inmediatly after if the book is not in the storage
                it2 = it1;
                for(int i = 0; i < dist_it(it1, it3)/2; ++i){

                    ++it2;
                }
                if(x == (*it2)){
                    encontrado=true;
                    result = it2;
                }else{

                    if(x > (*it2)){
                        if(dist_it(it1, it2)==1 or dist_it(it1,it2)==0){
                            encontrado = true;
                            result = it2;
                            if(x >(*it1)){
                                result=it1;
                            }
                        }else{
                            it3 = it2;
                        }
                    }else{
                        if(dist_it(it2, it3)==1){
                            encontrado = true;
                            result = it3;
                            if((*it3)>x){
                                ++result;
                            }
                        }else{
                            it1 = it2;
                        }
                    }
                }
            }
        }
    }


    return result;
}

//*********************************************************
// Setters
//*********************************************************


// Pre: true.
// Post: if the priority queue is not empty, it clasifitate all the books into the queue.
void Platform::classify(){
    if(not_classificated.size() != 0){
        while(not not_classificated.empty()){
            // INV: it classifitate all the books into the priority queue
            Book b=not_classificated.front();
            not_classificated.pop();
            list<Book>::iterator it= dicotomic_search(storage, b);
            classifier.classify((*it));
            cout<<(*it)<<endl;
        }
    }
}

// Pre: true.
// Post: if the priority queue is not empty, it clasifiate the first book into the queue.
void Platform::classifyBook(){

    if(not not_classificated.empty()){
        Book b=not_classificated.front();
        not_classificated.pop();
        list<Book>::iterator it= dicotomic_search(storage, b);
        classifier.classify((*it));
        cout<<*it<<endl;
    }else{
        cout<<"  error"<<endl;
    }

}

// Pre: true.
// Post: if the book isn't in the storage it will be registrated and it will get in the priority queue
void Platform::registerBook(string title, Date date, list <string> keywords){
    Book b;
    b.setTitle(title);
    b.setPubDate(date);
    b.setKeywords(keywords);
    cout << b << endl;
    if(not isInStorage(b)){
        not_classificated.push(b);
        list<Book>::iterator it;
        it = dicotomic_search(storage, b);
        storage.insert(it, b);
    }else{
        cout<<"  error"<<endl;

    }
}


// Pre:
// Post: if the book is in the storage it will be eliminated of the storage list.
void Platform::eliminateBook(string &title){
    bool encontrado = false;
    list<Book>::iterator it1 = storage.begin(), it2 = storage.end();
    while(not encontrado and it1!=it2){
        // INV: it looks for the title's books into the storage
        if(title == (*it1).getTitle()){
            encontrado = true;
        }else{
            ++it1;
        }
    }
    if(encontrado == true){
        if((*it1).getTopics() == ""){
            not_classificated.remove((*it1));
        }
        it1 = storage.erase(it1);
    }else{
        cout << "  error"<< endl;
    }
}

//*********************************************************
// Reading and writting
//*********************************************************

// Pre: true.
// Post: it prints the priority queue of the not clasificated books.
void Platform::pendingsList(){
    cout << not_classificated;
}


// Pre: true
// Post: it prints the storage list into the standar channel output
void Platform::writeStorage(){
    list<Book>::iterator it1 = storage.begin(), it2 = storage.end();
    while(it1 != it2){
        // INV: it travels for the storage printing all the books
        cout << (*it1) << endl;
        ++it1;
    }
}

// Pre: true
// Post: it prints all book that belong to a topic.
void Platform::showBooksTopic(string &topic){

    if(classifier.inTopics(topic)){
        bool there_are = false;
        list<Book>::iterator it1 = storage.begin(), it2 = storage.end();
        while(it1 != it2){
            // INV: it looks for the book with the topic equal to the string topic and print them
            if((*it1).getTopics() == topic){
                there_are=true;
                cout << (*it1) << endl;
            }
            ++it1;
        }
        if(not there_are){
            cout<<"  No hi ha cap llibre de l'àrea "<<topic<<endl;
        }
    }else{
        cout << "  error" << endl;
    }



}


