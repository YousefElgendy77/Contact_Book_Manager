#ifndef PERSON_H
#define PERSON_H
#include <bits/stdc++.h>
#include "Vector.h"
#include "Address.h"
using namespace std;

class Person
{
private:
    Address address;
    string first_name;
    string last_name;
    Vector<string> phone_number;
    Vector<string> emails;
    string classification;
    bool favourite;

public:
    Person() : first_name(""), last_name(""), phone_number(Vector<string>()), emails(Vector<string>()), classification(""), address(), favourite(false) {}
    Person(string FirstName, string LastName, Vector<string> numbers, Vector<string> emails, string Classification, bool fav, Address a) : first_name(FirstName), last_name(LastName), phone_number(numbers), emails(emails), classification(Classification), favourite(fav), address(a) {}
    void set_first_name(string &first_name)
    {
        this->first_name = first_name;
    }
    string get_first_name() const
    {
        return first_name;
    }
    void set_last_name(string &last_name)
    {
        this->last_name = last_name;
    }
    string get_last_name() const
    {
        return last_name;
    }
    void set_Classification(string &classification)
    {
        this->classification = classification;
    }
    string get_Classification() const
    {
        return classification;
    }
    void set_Phone_numbers(Vector<string> &numbers)
    {
        for (int i = 0; i < numbers.getSize(); i++)
            phone_number.PushBack(numbers[i]);
    }
    Vector<string> get_Phone_numbers() const
    {
        return phone_number;
    }
    void set_emails(Vector<string> &mails)
    {
        for (int i = 0; i < mails.getSize(); i++)
            emails[i] = mails[i];
    }
    Vector<string> get_emails() const
    {
        return emails;
    }
    void isFav(bool fav)
    {
        favourite = fav;
    }
    bool get_fav() const
    {
        return favourite;
    }
    bool operator==(const Person &other)
    {
        return (first_name == other.first_name && last_name == other.last_name);
    }
    void set_address(Address a)
    {
        this->address = a;
    }
    Address get_address() const
    {
        return address;
    }
    void print_address() const
    {
        address.get_full_address();
    }
    Person &operator=(const Person &other)
    {
        if (this != &other)
        {
            first_name = other.first_name;
            last_name = other.last_name;
            classification = other.classification;
            favourite = other.favourite;
            phone_number = other.phone_number;
            emails = other.emails;
        }
        return *this;
    }
    bool operator!=(const Person &other) const
    {
        return first_name != other.first_name ||
               last_name != other.last_name ||
               classification != other.classification ||
               address != other.get_address() ||
               favourite != other.favourite ||
               phone_number != other.phone_number;
    }
    ~Person()
    {
        phone_number.clear();
        emails.clear();
    }
    void print_personInfo()
    {
        cout << left << setw(20) << "Full Name: " << get_first_name() << ' ' << get_last_name() << '\n';
        cout << left << setw(20) << "Classification : " << get_Classification() << '\n';
        cout << left << setw(20) << "Numbers : ";
        get_Phone_numbers().display();
        cout << left << setw(20) << "Emails : ";
        get_emails().display();
        if (favourite)
            cout << "Contact is Favourite\n";
        else
            cout << "Contact is not Favourite\n";
    }
    friend ostream &operator<<(ostream &os, const Person &person);
};

ostream &operator<<(ostream &os, const Person &person)
{
    os << setw(12) << person.first_name << ' '
       << setw(12) << person.last_name << ' '
       << setw(12) << person.classification << ' '
       << setw(12) << (person.favourite ? "YES" : "NO") << ' ';
    for (int i = 0; i < person.get_Phone_numbers().getSize(); ++i)
    {
        os << person.get_Phone_numbers()[i] << ' ';
    }
    for (int i = 0; i < person.get_emails().getSize(); ++i)
    {
        os << person.get_emails()[i] << ' ';
    }
    os << setw(12) << person.get_address() << ' ';
    return os;
}
#endif