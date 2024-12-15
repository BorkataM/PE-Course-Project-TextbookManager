#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include <string>
#include <iostream>

class Textbook {
private:
    std::string title;
    std::string author;
    int edition;
    std::string isbn;
    std::string releaseDate;
    int copies;
    bool approved;
    std::string approvalDate;

public:
    Textbook();
    Textbook(const std::string& t, const std::string& a, int e, const std::string& i, const std::string& r, int c, bool ap, const std::string& ad = "");

    std::string getTitle() const;
    void setTitle(const std::string& t);

    std::string getAuthor() const;
    void setAuthor(const std::string& a);

    int getEdition() const;
    void setEdition(int e);

    std::string getISBN() const;
    void setISBN(const std::string& i);

    std::string getReleaseDate() const;
    void setReleaseDate(const std::string& r);

    int getCopies() const;
    void setCopies(int c);

    bool isApproved() const;
    void setApproved(bool ap);

    std::string getApprovalDate() const;
    void setApprovalDate(const std::string& ad);

    friend std::ostream& operator<<(std::ostream& os, const Textbook& t);
};

#endif