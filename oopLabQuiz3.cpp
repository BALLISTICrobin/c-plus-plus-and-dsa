#include <iostream>
#include <string>
using namespace std;

class Book
{
    string title, author;
    bool availability;

public:
    Book()
    {
        availability = false;
    }
    ~Book()
    {
    }
    void SetDet(string s1, string s2)
    {
        title = s1;
        author = s2,
        availability = true;
    }

    void setAvail(bool v)
    {
        availability = v;
    }
    string Gettitle()
    {
        return title;
    }
    string Getauthor()
    {
        return author;
    }
    int getavail()
    {
        return availability;
    }
    void display()
    {
        cout << "TITLE: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Availability: ";
        if (availability)
            cout << "available" << endl;
            else
        cout << "not available" << endl;
    }
    friend class Library;
};

class LibraryMember
{
    string name;
    int librarycard;

public:
    LibraryMember()
    {
    }
    ~LibraryMember()
    {
    }

    void SetMem(string s1, int num)
    {
        name = s1;
        librarycard = num;
    }
    string Getname()
    {
        return name;
    }
    int getcar()
    {
        return librarycard;
    }

    void DisplayMem()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Library Card Number: "<<librarycard<<endl; 
    }
};

class Library
{
    int i, j;
    Book *arr1;
    LibraryMember *arr2;

public:
    Library()
    {
        i = 0;
        j = 0;
        arr1 = new Book[100];
        arr2 = new LibraryMember[100];
    }
    ~Library(){
        delete []arr1;
        delete []arr2;
    }

    void addBook(string str1, string str2)
    {
        arr1[i].SetDet(str1, str2);
        i++;
    }
    void registerMember(string str3, int value)
    {
        arr2[j].SetMem(str3, value);
        j++;
    }
    void displayAllBooks()
    {
        for (int p = 0; p < i; p++)
        {

            arr1[p].display();
        }
    }
    void displayAllMembers()
    {
        for (int p = 0; p < i; p++)
        {
            arr2[p].DisplayMem();
        }
    }
    void borrowBook(string s, int n)
    {
        for (int k = 0; k < i; k++)
        {
            if (arr1[k].Gettitle() == s)
            {
                arr1[k].setAvail(false);
                cout<<"Book "<<s<<" has been borrowed by";
                for(int x =0 ;x<j; x++){
                    if(arr2[x].getcar()==n)
                    arr2[x].DisplayMem();
                }
            }
        }
    }
    void returnBook(string s, int num)
    {
        for (int k = 0; k < i; k++)
        {
            if (arr1[k].Gettitle() == s)
            {
                arr1[k].setAvail(true);
                cout<<"Book "<<s<<" has been returned by";
                for(int x =0 ;x<j; x++){
                    if(arr2[x].getcar()==num)
                    arr2[x].DisplayMem();
                }
                break;
            }
        }
    }
    // removeBook
    void removeBook(string s){
        for(int k=0; k<i; k++){
            if(arr1[k].Gettitle() == s){
                for(int x =k; x<i-1; x++){
                    arr1[k] = arr1[k+1];
                }
                i--;
                break;
            }
        }
        cout<<"the book "<<s<<" is removed from the library"<<endl;
    }
    // removeMember
};

int main()
{
    Library library;
    // Adding books
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("Pride and Prejudice", "Jane Austen");
    // Displaying all books
    library.displayAllBooks();
    // Registering members
    library.registerMember("John Doe", 1234);
    library.registerMember("Jane Smith", 5678);
    // Displaying all members
    library.displayAllMembers();
    // Borrowing books
    library.borrowBook("The Great Gatsby", 1234);
    library.borrowBook("To Kill a Mockingbird", 5678);
    // Displaying all books (after borrowing)
    library.displayAllBooks();
    // Returning a book
    library.returnBook("The Great Gatsby", 1234);
    // Displaying all books (after returning)
    library.displayAllBooks();
    // Removing a book
    library.removeBook("Pride and Prejudice");
    // Displaying all books (after removal)
    library.displayAllBooks();
    // Removing a member
    // library.removeMember(5678);
    // Displaying all members (after removal)
    // library.displayAllMembers();
    return 0;
}
