//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

Book.h

*/
//============================================================================

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    unsigned isbn;
    double price;

public:
    Book();
    Book(string t, string a, int i, double p);

    /**Access Functions*/
    string get_title();
    string get_author();
    unsigned get_isbn();
    double get_price();

    /**Manipulation Procedures*/
    void set_title(string t);
    void set_author(string a);
    void set_isbn(unsigned i);
    void set_price(double p);

    /**Additional Functions*/
    void print_book();
    bool operator==(Book& book);

};

#endif /* BOOK_H_ */
