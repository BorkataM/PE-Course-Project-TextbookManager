#include "Textbook.h"

Textbook::Textbook() : edition(0), copies(0), approved(false) {}

Textbook::Textbook(const std::string& t, const std::string& a, int e, const std::string& i, const std::string& r, int c, bool ap, const std::string& ad)
    : title(t), author(a), edition(e), isbn(i), releaseDate(r), copies(c), approved(ap), approvalDate(ad) {}

std::string Textbook::getTitle() const { return title; }
void Textbook::setTitle(const std::string& t) { title = t; }

std::string Textbook::getAuthor() const { return author; }
void Textbook::setAuthor(const std::string& a) { author = a; }

int Textbook::getEdition() const { return edition; }
void Textbook::setEdition(int e) { edition = e; }

std::string Textbook::getISBN() const { return isbn; }
void Textbook::setISBN(const std::string& i) { isbn = i; }

std::string Textbook::getReleaseDate() const { return releaseDate; }
void Textbook::setReleaseDate(const std::string& r) { releaseDate = r; }

int Textbook::getCopies() const { return copies; }
void Textbook::setCopies(int c) { copies = c; }

bool Textbook::isApproved() const { return approved; }
void Textbook::setApproved(bool ap) { approved = ap; }

std::string Textbook::getApprovalDate() const { return approvalDate; }
void Textbook::setApprovalDate(const std::string& ad) { approvalDate = ad; }

std::ostream& operator<<(std::ostream& os, const Textbook& t) {
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