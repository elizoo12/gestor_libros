#include "LlibreE.hpp"

using namespace std;

//*********************************************************
// Builders and assignation
//*********************************************************

// Pre: true.
// Post: it creates a book with title, publication date
// and topics emptys, without keywords.
Book::Book(){
    title="";
    pubDate={0,0,0};
	topics="";

}

// Pre: true.
// Post: it creates a book with a title, publication date,
// topics and the keywords of the book b
Book::Book(const Book &b){
    title = b.title;
    pubDate = b.pubDate;
    topics = b.topics;
    keywords=b.keywords;
}

// Pre: true.
// Post: the restul is a book with title, publication
// date, area and keywords of the book b
Book& Book::operator=(const Book &b){
    title = b.title;
    pubDate = b.pubDate;
    topics = b.topics;
    keywords=b.keywords;
    return (*this);
}

//*********************************************************
// Destroyer
//*********************************************************

// Default destroyer
Book::~Book(){

}

//*********************************************************
// Consultors
//*********************************************************

// Pre: true.
// Post: the result is the title of the book of the implicit parameter.
string Book::getTitle() const{
    return title;
}

// Pre: true.
// Post: the result it the publication data of the book of the implicit parameter.
Date Book::getPubDate() const{
    return pubDate;
}

// Pre: true.
// Post: the result is the topic area of the book of the implicit parameter.
string Book::getTopics() const{
    return topics;
}

//Pre: true.
// Post: the result is the keywords of the book of the implicit parameter.
list<string> Book::getKeywords() const{
    return keywords;
}

// Pre: true.
// Post: it returns a boolean value, true if the publication date is later
// that the publication date of the book b and false in the other case.
bool Book::compare(const Book &b) const{

    bool greater=false;

    if(pubDate<b.pubDate){
        greater=true;

    }else if(pubDate==b.pubDate){
        if(title<b.title){
            greater= true;
        }
    }

    return greater;
}

// Pre: true.
// Post: it returnt a boolean value, true if the publication date is later
// that the publication date of the book b and false in the other case.
bool Book::operator>(const Book &b)const{

    bool greater=false;

    if(pubDate<b.pubDate){
        greater=true;

    }else if(pubDate==b.pubDate){
        if(title<b.title){
            greater= true;
        }
    }




    return greater;
}

// Pre: true.
// Post: it returnt a boolean value, true if the publication date is greater
// that the publication date of the book b and false in the other case.
bool Book::operator<(const Book &b)const{
    bool lower=false;
    if(pubDate>b.pubDate){

        lower=true;
    }else if(pubDate==b.pubDate){
        if(title<b.title){
            lower=true;
        }
    }

    return lower;
}

// Pre: true.
// Post: it returns a boolean value, true if both books are the same and false in the other case.
bool Book::operator==(const Book &b)const{
    bool equal = false;

    if(title == b.title){
        equal = true;
    }
    return equal;
}

// Pre: true.
// Post: it returns a boolean value, true if btoh books are diferents and false in the other case.
bool Book::operator!=(const Book &b)const{
    bool not_equal = false;
    if(title != b.title or pubDate!=b.pubDate){
        not_equal = true;
    }
    return not_equal;
}

//settes
// Pre: true.
// Post: the result is the book's title with the value of title.
void Book::setTitle(string title){
    this->title = title;
}
// Pre: true.
// Post: the result is the book's pubDate with the value of pubDate.
void Book::setPubDate(Date pubDate){
    this->pubDate = pubDate;
}
// Pre: true.
// Post: the result is the book's keywords with the value of keywords.
void Book::setKeywords(list<string> &keywords){
    this->keywords = keywords;
}

// Pre: true.
// Post: the result is the book's topics with the value of s.
void  Book::setTopic(string s){
    this->topics = s;
}

// Pre: the iterator a must be lower that the iterator b
// Post: it returns the distance between both iterators.
int Book::dist_it(list<string>::iterator a, list<string>::iterator b){
    int result = 0;
    while(a != b){
        //INV: it count the distance between a and b.
       ++a;
       ++result;
    }
    return result;
}

//pre: the list keywords must be sorted.
//post: it returns an iterator pointing to x if it's in the list or the element that must be next to x if it was in the same sorted list.
list <string>::iterator Book::dicotomic_search(list<string> &l, string x){

    list<string>::iterator it1 = l.begin(), it2, it3 = l.end(), result;
    if(l.size() == 0){
        result = it3;
    }else{
        --it3;
        if(l.size() == 1){
            if(x>(*it1)){
                result = l.end();

            }else{
                result = it1;
            }
        }else if((*it1) == x){
            result = it1;
        }else if((*it3) == x){
            result = it3;
        }else{
            bool encontrado = false;
            while(not encontrado){
                //INV: the hipotetical position of x if it was on l is between it1 and it3
                it2 = it1;
                for(int i = 0; i < dist_it(it1, it3)/2; ++i){
                    ++it2;
                }
                if(x == (*it2)){
                    encontrado=true;
                    result = it2;
                }else{
                    if(x < (*it2)){
                        if(dist_it(it1, it2)==1 or dist_it(it1,it2)==0){
                            encontrado = true;
                            result = it2;
                            if((*it1) > x){
                                result=it1;
                            }
                        }else{
                            it3 = it2;
                        }
                    }else{
                        if(dist_it(it2, it3)==1){
                            encontrado = true;
                            result = it3;
                            if((*result) < x ){
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
// ...
// AFEGIU ELS MÈTODES QUE CALGUIN
// ...


//*********************************************************
// Reading and writting
//*********************************************************

// Pre: there si preparated into the standar input channel a book.
// Post: the book is filled up with the parameters solicited by the standart input channel.
istream& operator>>(istream &is, Book &b){
    string s;
    getline(cin,s);
    istringstream ss(s);
    ss>>b.title;
    ss>>b.pubDate;
    string words;
    ss>>words;
    list<string>::iterator it;
    while(words!="."){
        //INV: it's setting all the keywords in orden in keywords' list.
        it = b.dicotomic_search(b.keywords, words);
        b.keywords.insert(it, words);
        ss>>words;
    }

    return is;
}

// Pre: true.
// Post: it writes the atributes of the book b into the standar output channel.
ostream& operator<<(ostream &os, Book &b){
    os << "  títol: " << b.title << endl;
    os << "  data publicació: " << b.pubDate << endl;
    os << "  paraules clau: ";
    list<string>::iterator it = b.keywords.begin();
    while(it != b.keywords.end()){
        //INV: it write all the keywords in the list.
        os << (*it);
        ++it;
        if(it != b.keywords.end()){
            os << " ";
        }
    }
    os << endl;
    os << "  àrea temàtica: " << b.topics << endl;
    os << "  --------------------";
    return os;
}





