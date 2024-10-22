#ifndef LLIBREE_HPP
#define LLIBREE_HPP
#include "Data.hpp"
#include <iostream>
#include <sstream>
#include <list>
using namespace std;

#define nat unsigned int

class Book {
// Modul type: date
// Type description: it represents an e-book that has a
// title, publication date, a topics and keywords
// that describes the content

	private:
	string title;
	Date pubDate;
	string topics;
	list<string> keywords;

	//pre: a iterators' index is lower than b's.
	//post: it return the distance between a anb b.
	int dist_it(list<string>::iterator a, list<string>::iterator b);


	//pre: the list keywords must be sorted.
	//post: it returns an iterator pointing to x if it's in the list or the element that must be next to x if it was in the same sorted list.
	list <string>::iterator dicotomic_search(list<string> &keywords, string x);
	public:

		//*********************************************************
		// Builders and assignation
		//*********************************************************

		// Pre: true.
		// Post: it creates a book with title, publication date
		// and topics emptys, without keywords.
		Book();

		// Pre: true.
		// Post: it creates a book with a title, publication date,
		// topics and the keywords of the book b
		Book(const Book &b);

		// Pre: true.
		// Post: the restul is a book with title, publication
		// date, topics and keywords of the book b
		Book& operator=(const Book &b);



		//*********************************************************
		// Destroyer
		//*********************************************************

		// Default destroyer
		~Book();

	    //*********************************************************
		// Getters
		//*********************************************************

		// Pre: true.
		// Post: the result is the title of the book of the implicit parameter.
		string getTitle() const;

		// Pre: true.
		// Post: the result it the publication date of the book of the implicit parameter.
		Date getPubDate() const;

		// Pre: true.
		// Post: the result is the topics of the book of the implicit parameter.
		string getTopics() const;

		// Pre: true.
		// Post: the result is the keywords of the book of the implicit parameter.
		list<string> getKeywords() const;

		// Pre: true.
		// Post: it returnt a boolean value, true if the publication date is later
		// that the publication date of the book b and false in the other case.
	    bool compare(const Book &b) const;

		// Pre: true.
		// Post: it returnt a boolean value, true if the publication date is later
		// that the publication date of the book b and false in the other case.
		bool operator>(const Book &b)const;

		// Pre: true.
		// Post: it returnt a boolean value, true if the publication date is greater
		// that the publication date of the book b and false in the other case.
		bool operator<(const Book &b)const;

		// Pre: true.
		// Post: it returns a boolean value, true if both books are the same and false in the other case.
		bool operator==(const Book &b)const;

		// Pre: true.
		// Post: it returns a boolean value, true if btoh books are diferents and false in the other case.
		bool operator!=(const Book &b)const;

		 //*********************************************************
		// Setters
		//*********************************************************


		// Pre: true.
		// Post: the result is the book's title with the value of title.
		void setTitle(string title);

		// Pre: true.
		// Post: the result is the book's pubDate with the value of pubDate.
		void setPubDate(Date pubDate);

		// Pre: true.
		// Post: the result is the book's keywords with the value of keywords.
		void setKeywords(list<string> &keywords);

		// Pre: true.
		// Post: the result is the book's topics with the value of s.
		void  setTopic(string s);

		// ...
		// AFEGIU ELS MÈTODES QUE CALGUIN
		// ...


		//*********************************************************
		// Reading and writting
		//*********************************************************

		// Pre: there si preparated into the standar input channel a book.
		// Post: the book is filled up with the parameters solicited by the standart input channel.
		friend istream& operator>>(istream &is, Book &b);

		// Pre: true.
		// Post: it writes the atributes of the book b into the standar output channel.
		friend ostream& operator<<(ostream &os, Book &b);




};
#endif

