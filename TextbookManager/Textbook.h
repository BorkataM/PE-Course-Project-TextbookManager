#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include <string>
#include <iostream>

using namespace std;

class Textbook {
private:
    string title;
    string author;
    int edition;
    string isbn;
    string releaseDate;
    int copies;
    bool approved;
    string approvalDate;

public:
    Textbook();
    Textbook(const string& t, const string& a, int e, const string& i, const string& r, int c, bool ap, const string& ad = "");

    string getTitle() const;
    void setTitle(const string& t);

    string getAuthor() const;
    void setAuthor(const string& a);

    int getEdition() const;
    void setEdition(int e);

    string getISBN() const;
    void setISBN(const string& i);

    string getReleaseDate() const;
    void setReleaseDate(const string& r);

    int getCopies() const;
    void setCopies(int c);

    bool isApproved() const;
    void setApproved(bool ap);

    string getApprovalDate() const;
    void setApprovalDate(const string& ad);

    friend ostream& operator<<(ostream& os, const Textbook& t);
};

#endif