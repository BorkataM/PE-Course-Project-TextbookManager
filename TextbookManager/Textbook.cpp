#include "Textbook.h"

using namespace std;

Textbook::Textbook() : edition(0), copies(0), approved(false) {}

Textbook::Textbook(const string& t, const string& a, int e, const string& i, const string& r, int c, bool ap, const string& ad)
    : title(t), author(a), edition(e), isbn(i), releaseDate(r), copies(c), approved(ap), approvalDate(ad) {}

string Textbook::getTitle() const { return title; }
void Textbook::setTitle(const string& t) { title = t; }

string Textbook::getAuthor() const { return author; }
void Textbook::setAuthor(const string& a) { author = a; }

int Textbook::getEdition() const { return edition; }
void Textbook::setEdition(int e) { edition = e; }

string Textbook::getISBN() const { return isbn; }
void Textbook::setISBN(const string& i) { isbn = i; }

string Textbook::getReleaseDate() const { return releaseDate; }
void Textbook::setReleaseDate(const string& r) { releaseDate = r; }

int Textbook::getCopies() const { return copies; }
void Textbook::setCopies(int c) { copies = c; }

bool Textbook::isApproved() const { return approved; }
void Textbook::setApproved(bool ap) { approved = ap; }

string Textbook::getApprovalDate() const { return approvalDate; }
void Textbook::setApprovalDate(const string& ad) { approvalDate = ad; }

ostream& operator<<(ostream& os, const Textbook& t) {
    os << "Title: " << t.title << "\n"
        << "Author: " << t.author << "\n"
        << "Edition: " << t.edition << "\n"
        << "ISBN: " << t.isbn << "\n"
        << "Release Date: " << t.releaseDate << "\n"
        << "Copies: " << t.copies << "\n"
        << "Approved: " << (t.approved ? "Yes" : "No") << "\n";
    if (t.approved) {
        os << "Approval Date: " << t.approvalDate << "\n";
    }
    return os;
}