#include<bits/stdc++.h>
using namespace std;



class Constants{
    static const int MAXIMUM_BOOK_LIMIT = 5;
    static const int MAXIMUM_DAYS_LIMIT = 10;
};


class Person{
    string name;
    string address;
    string email;
    long long phoneNumber;
};

class ManageBook{
    virtual void addBook() = 0;
    virtual void removeBook() = 0;
    virtual void showBookDetails() = 0;
    virtual void modifyBook() = 0;
};

//Abstract Class
class NewBook{
    virtual void bookName() = 0;
    virtual void booktitle() = 0;
    virtual void bookAuthor() = 0;
    virtual void bookSubject() = 0;
    virtual void publisher() = 0;
    virtual void publicationDate() = 0;
};

class Book : NewBook{
    int bookId;
    int rackNumber;
    string title;
    string author;
    string subject;
    string publisher;
    DATE publicaton_Date;
};

//AbstractClass
class ReadBarcode{
    virtual void getInfoFromBarcode() = 0;
};

//Abstract class
class GenerateBarcode{
    virtual void getBarcode() = 0;
};


class Barcode : GenerateBarcode{
    string barcode;
};

//Abstract Classes
class BookStatusReserved{};
class BookSatausAvailable{};
class BookStatusNotAvailable{};

//Abstract Class
class BookStatus : BookSatausAvailable,
                   BookStatusReserved,BookStatusNotAvailable{
};

//Abstract class for copies of book
class ManageBookItem{
    virtual void addBookItem() = 0;
    virtual void removeBookItem() = 0;
};


class BookItem : Book{
    BookStatus bookStatus;
    DATE issueDate;
    DATE dueDate;
    Barcode barcode;
    Member issuedTo;
};

//Abstract classes
class SearchByTitle{};
class SearchByAuthor{};
class SearchBySuject{};
class SearchByPublicationDate{};

class SearchBookMode : SearchByAuthor,SearchByPublicationDate,SearchBySuject,SearchByTitle{
};

class SearchBook{
    BookItem bookName;
    SearchBookMode searchBy;
};

//Abstract class
class ManageMember{
    virtual void addMember() = 0;
    virtual void removeMember() = 0;
    virtual void showMemberDetails(Member) = 0;
};

//Abstract classes
class BookReturn{};
class BookRenew{};
class BookIssue{};
class BookReserve{};

//Abstract Class
class MemberPower : BookReturn,BookRenew,BookIssue,BookReserve{
    virtual void searchBook(SearchBookMode,Book) = 0;


};

class Member : Person , MemberPower{
    int memberId;
    vector<BookItem> borrowedBooks(Constants::MAXIMUM_BOOK_LIMIT);
    SearchBook searchBook;
    int bookReturnDays = Constants::MAXIMUM_DAYS_LIMIT;
    Barcode barcode;
};


//Abstract class
class NotificationControls{
    virtual void sendNotification(Member);
};

class SendNotification{
    string message;
};

//Abstract class
class RetrieveInformation{
    virtual void getBookDetails() = 0;
    virtual void getMemberDetials() = 0;
};

//Abstract Class
class CalculateFine{};


class CollectFine : CalculateFine{
    BookItem bookName;
};


class BookReservation{};
class CancelReservation{};

class Reservation{
    BookReservation bookReservation;
    CancelReservation cancelReservation;
};

//Abstract class
class SystemControls : ReadBarcode,SearchBook
                       NotificationControls,Reservation,
                       BookReturn,BookRenew,BookIssue,BookRenew,
                       RetrieveInformation,CalculateFine,
                       ManageBook,ManageItem{

    virtual void getFullInfoAboutMember(Member) = 0;


};

//Abstract classes
class ManageAccountControls{
    virtual void newAccout() = 0;
    virtual void deleteAccount() = 0;
    virtual void cancelMembership() = 0;
};

class Account : AccountControls{
    Member newMember;
    vector<BookItem> books;
};


class System : SystemControls,AccoutControls{
    vector<Book> Books;
    vector<BookItem> bookItems;
    vector<Member> members;
    SendNotification notification;
    CalcuateFine fine;
};

//Abstract class
class LibraryAdminPower : SystemControls{};

class LibraryAdmin : LibraryAdminPower{
    System master;
};
