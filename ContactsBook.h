#ifndef CONTACTSBOOK_H
#define CONTACTSBOOK_H

#include <bits/stdc++.h>
#include "Person.h"
#include "Vector.h"
#include <fstream>
using namespace std;

class contact_book
{
    Vector<Person> contacts;

public:
    void print_header()
    {
        cout << setw(5) << left << "ID"
             << setw(18) << left << "First Name"
             << setw(18) << left << "Last Name"
             << setw(20) << left << "Classification"
             << setw(28) << left << "Address"
             << setw(7) << left << "Fav"
             << setw(30) << left << "Phone Numbers" << '\n';

        cout << string(115, '-') << '\n';
    }
    void print_single_contacts(int index)
    {
        print_header();

        Person p = contacts[index];
        Address a = p.get_address();
        cout << setw(5) << left << index + 1
             << setw(18) << left << p.get_first_name()
             << setw(18) << left << p.get_last_name()
             << setw(20) << left << p.get_Classification()
             << setw(28) << left << a.get_full_address()
             << setw(7) << left << (p.get_fav() ? "Yes" : "No");

        cout << setw(30) << left;
        for (int j = 0; j < p.get_Phone_numbers().getSize(); ++j)
        {
            cout << p.get_Phone_numbers().getElement(j);
            if (j != p.get_Phone_numbers().getSize() - 1)
                cout << ',';
            cout << '\n';
            cout << string(115, '-') << '\n';
        }
    }
    void add_new_contact(Person &new_contact)
    {
        contacts.PushBack(new_contact);
        cout << "\n\tContact was added successfully.\n";
    }
    void search_by_Lname(string lastName)
    {
        bool found = false;
        for (int i = 0; i < contacts.getSize(); ++i)
        {
            if (contacts[i].get_last_name() == lastName)
            {
                print_single_contacts(i);
                found = true;
                break;
            }
        }
        if (!found)
            cout << "There is No contact with this last name";
    }
    void search_by_class(string classify)
    {
        bool found = false;
        for (auto c : classify)
            tolower(c);
        for (int i = 0; i < contacts.getSize(); ++i)
        {
            if (contacts[i].get_Classification() == classify)
            {
                print_single_contacts(i);
                found = true;
                break;
            }
        }
        if (!found)
            cout << "There is No contact with this classification";
    }
    void reverse_contacts()
    {
        if (contacts.isempty())
        {
            cout << "Contact book is empty.\n";
            return;
        }
        contacts.reverse();
        cout << "Contacts are reversed successfully.\n";
    }
    void print_contacts()
    {
        print_header();

        for (int i = 0; i < contacts.getSize(); ++i)
        {
            Person p = contacts[i];
            Address a = p.get_address();
            cout << setw(5) << left << i + 1
                 << setw(18) << left << p.get_first_name()
                 << setw(18) << left << p.get_last_name()
                 << setw(20) << left << p.get_Classification()
                 << setw(28) << left << add
                 << setw(7) << left << (p.get_fav() ? "Yes" : "No");

            cout << setw(30) << left;
            for (int j = 0; j < p.get_Phone_numbers().getSize(); ++j)
            {
                cout << p.get_Phone_numbers().getElement(j);
                if (j != p.get_Phone_numbers().getSize() - 1)
                    cout << ',';
            }
            cout << '\n';
            cout << string(115, '-') << '\n';
        }
    }
    void print_fav()
    {
        print_header();

        for (int i = 0; i < contacts.getSize(); ++i)
        {
            Person p = contacts[i];
            Address a = p.get_address();
            if (!p.get_fav())
                continue;
            cout << setw(5) << left << i + 1
                 << setw(18) << left << p.get_first_name()
                 << setw(18) << left << p.get_last_name()
                 << setw(20) << left << p.get_Classification()
                 << setw(28) << left << a.get_full_address()
                 << setw(7) << left << (p.get_fav() ? "Yes" : "No");

            cout << setw(30) << left;
            for (int j = 0; j < p.get_Phone_numbers().getSize(); ++j)
            {
                cout << p.get_Phone_numbers().getElement(j);
                if (j != p.get_Phone_numbers().getSize() - 1)
                    cout << ',';
            }
            cout << '\n';
            cout << string(115, '-') << '\n';
        }
    }
    void remove_contact(int index)
    {
        contacts.delete_at(index - 1);
        cout << "Contact is deleted successfully.\n";
    }
    void update_contact(const Person p, int index)
    {
        index -= 1;
        Person old = contacts[index];
        if (p != old)
        {
            contacts[index] = p;
            cout << "Contact is updated successfully.\n";
        }
    }
    void save()
    {
        ofstream file("contact.txt");
        if (!file.is_open())
        {
            cout << "Error opening file!" << endl;
            return;
        }
        file << setw(5) << left << "ID"
             << setw(18) << left << "First Name"
             << setw(18) << left << "Last Name"
             << setw(20) << left << "Classification"
             << setw(28) << left << "Address"
             << setw(7) << left << "Fav"
             << setw(30) << left << "Phone Numbers" << '\n';
        file << string(115, '-') << '\n';

        for (int i = 0; i < contacts.getSize(); ++i)
        {
            Person p = contacts[i];
            Address a = p.get_address();
            file << setw(5) << left << i + 1
                 << setw(18) << left << p.get_first_name()
                 << setw(18) << left << p.get_last_name()
                 << setw(20) << left << p.get_Classification()
                 << setw(28) << left << a.get_full_address()
                 << setw(7) << left << (p.get_fav() ? "Yes" : "No");

            file << setw(30) << left;
            for (int j = 0; j < p.get_Phone_numbers().getSize(); ++j)
            {
                file << p.get_Phone_numbers().getElement(j);
                if (j != p.get_Phone_numbers().getSize() - 1)
                    cout << ',';
            }
            file << '\n';
            file << string(115, '-') << '\n';
        }
        file.close();
        cout << "Data is saved to file.\n";
    }
    void load()
    {
        ifstream file("contact.txt");
        if (!file.is_open())
        {
            cout << "Error opening file!" << endl;
            return;
        }

        string first_name, last_name, classification, street_name, street_number, city, country, phone_number, email;
        bool fav;
        Vector<string> phone_numbers;
        Vector<string> emails;

        string header;
        getline(file, header);

        while (getline(file, first_name, ','))
        {
            getline(file, last_name, ',');
            getline(file, classification, ',');
            getline(file, street_number, ',');
            getline(file, street_name, ',');
            getline(file, city, ',');
            getline(file, country, ',');
            file >> fav;
            file.ignore(); // To discard the comma between the fav and phone number fields

            phone_numbers.clear();
            while (getline(file, phone_number, ',') && !phone_number.empty())
            {
                phone_numbers.PushBack(phone_number);
            }
            emails.clear();
            while (getline(file, email, ',') && !email.empty())
            {
                emails.PushBack(email);
            }

            Address addr(street_name, street_number, city, country);
            Person person(first_name, last_name, phone_numbers, emails, classification, fav, addr);

            contacts.PushBack(person);
        }

        file.close();
        cout << "Data loaded from file.\n";
    }
};
#endif