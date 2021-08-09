//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* Book.cpp

*/
//============================================================================
#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book():title(""), author(""), isbn(0), price(0.0){};

Book::Book(string t, string a, int i, double p) {
    title = t;
    author = a;
    isbn = i;
    price = p;
}

/**Access Functions*/

string Book::get_title() {
    return title;
}

string Book::get_author() {
    return author;
}

unsigned Book::get_isbn() {
    return isbn;
}

double Book::get_price() {
    return price;
}

/**Manipulation Procedures*/

void Book::set_title(string t){
    title = t;
}

void Book::set_author(string a) {
    author = a;
}

void Book::set_isbn(unsigned i) {
    isbn = i;
}

void Book::set_price(double p) {
    price = p;
}

/**Additional Functions*/
void Book::print_book() {
    cout << title << endl;

    cout << " by " << author << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "$" << fixed << setprecision(2) << price;
}

bool Book::operator==(Book& book) {
    return (title == book.title && author==book.author && isbn==book.isbn && price == book.price);
}



