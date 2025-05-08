#include <bits/stdc++.h>
#include "Vector.h"
#include "Person.h"
#include "ContactsBook.h"
using namespace std;
void print_menu()
{
    cout << "\t\t\t================================================================" << endl;
    cout << "\t\t\tContact Book Menu:" << endl;
    cout << "\t\t\t-------------------------" << endl;
    cout << "\t\t\t1. Add a new contact." << endl;
    cout << "\t\t\t2. Search by last name (Enter last name correctly)." << endl;
    cout << "\t\t\t3. Search by classification (friend , family , work , other)?" << endl;
    cout << "\t\t\t4. Print all contacts." << endl;
    cout << "\t\t\t5. Print fav contacts." << endl;
    cout << "\t\t\t6. Save to file." << endl;
    cout << "\t\t\t7. Load from file." << endl;
    cout << "\t\t\t8. Delete contact" << endl;
    cout << "\t\t\t9. Update contact information." << endl;
    cout << "\t\t\t10. Reverse contact book." << endl;
    cout << "\t\t\t11. Exit" << endl;
    cout << "\t\t\t================================================================" << endl;
    cout << "Enter your choise : ";
}
void adding_message();
void person_message();
Person readInfo();
void print_address(contact_book &contact);
void add_contact(contact_book &contact);
void print_all_contacts(contact_book &contact);
void print_fav_contacts(contact_book &contact);
void search_by_last_name(contact_book &contact);
void search_by_classification(contact_book &contact);
void save_to_file(contact_book &contact);
void load_from_file(contact_book &contact);
void delete_contact(contact_book &contact);
void update_contact_info(contact_book &contact);
void reverse_all_contacts(contact_book &contact);
int main()
{
    contact_book contact;
    print_address(contact);
    return 0;
    int choise;
    do
    {
        print_menu();
        cin >> choise;
        cin.ignore();
        switch (choise)
        {
        case 1:
            add_contact(contact);
            break;
        case 2:
            search_by_last_name(contact);
            break;
        case 3:
            search_by_classification(contact);
            break;
        case 4:
            print_all_contacts(contact);
            break;
        case 5:
            print_fav_contacts(contact);
            break;
        case 6:
            save_to_file(contact);
            break;
        case 7:
            load_from_file(contact);
            break;
        case 8:
            delete_contact(contact);
            break;
        case 9:
            update_contact_info(contact);
            break;
        case 10:
            reverse_all_contacts(contact);
            break;
        case 11:
            break;
        default:
            cout << "Enter A number from 1 to 11.\n";
            break;
        }
    } while (choise != 11);
    return 0;
}
void person_message()
{
    cout << "\t\t\t--- Add a new contact ---\n";
}
void address_message()
{
    cout << "\t\t\t:: Enter Address Details ::\n";
}
bool valid_num(string &s)
{
    if (s.find_first_not_of("0123456789") != string::npos)
        return false;
    return true;
}
bool valid_email(string &s)
{
    if (s.find('@') != string::npos && s.find('.') != string::npos)
        return true;
    return false;
}
Person readInfo()
{
    person_message();

    string firstname, lastname, classification;

    cout << "First Name : ";
    getline(cin, firstname);

    cout << "Last Name : ";
    getline(cin, lastname);

    cout << "classification (Friend , Work , Family , Other) : ";
    getline(cin, classification);
    for (auto c : classification)
        tolower(c);

    bool isFav;
    string favourite;
    cout << "Set as Fav: (Press 1 (Fav) or 0 (Not)) : ";
    cin >> favourite;
    cin.ignore();
    if (favourite == "1" || favourite == "yes")
        isFav = true;
    else
        isFav = false;

    int count;
    cout << "How many number : ";
    cin >> count;
    cin.ignore();

    Vector<string> phone_numbers, emails;
    for (int i = 1; i <= count; ++i)
    {
        cout << "Phone #" << i << " : ";
        string num;
        getline(cin, num);
        if (valid_num(num))
        {
            phone_numbers.PushBack(num);
        }
        else
        {
            while (!valid_num(num))
            {
                cout << "Enter valid number : ";
                getline(cin, num);
            }
            phone_numbers.PushBack(num);
        }
    }

    cout << "How many emails : ";
    cin >> count;
    cin.ignore();

    for (int i = 1; i <= count; ++i)
    {
        cout << "email #" << i << " : ";
        string email;
        getline(cin, email);
        if (valid_email(email))
        {
            emails.PushBack(email);
        }
        else
        {
            while (!valid_email(email))
            {
                cout << "Enter valid email : ";
                getline(cin, email);
            }
            emails.PushBack(email);
        }
    }

    address_message();

    string city, country, street_name, street_number;

    cout << "Country : ";
    getline(cin, country);

    cout << "City : ";
    getline(cin, city);

    cout << "Street name : ";
    getline(cin, street_name);

    cout << "Street Number : ";
    getline(cin, street_number);

    Address address(street_name, street_number, city, country);
    Person object(firstname, lastname, phone_numbers, emails, classification, isFav, address);

    return object;
}
void add_contact(contact_book &contact)
{
    Person object = readInfo();
    contact.add_new_contact(object);
}
void reverse_all_contacts(contact_book &contact)
{
    contact.reverse_contacts();
    contact.print_contacts();
}
void print_all_contacts(contact_book &contact)
{
    contact.print_contacts();
}
void print_fav_contacts(contact_book &contact)
{
    contact.print_fav();
}
void delete_contact(contact_book &contact)
{
    contact.print_contacts();
    int index;
    cout << "Enter Index : ";
    cin >> index;
    contact.remove_contact(index);
}
void search_by_last_name(contact_book &contact)
{
    string lname;
    cout << "Enter Last Name in Correct form : ";
    getline(cin, lname);
    contact.search_by_Lname(lname);
}
void search_by_classification(contact_book &contact)
{
    string classification;
    cout << "Enter Classification in Correct form : ";
    getline(cin, classification);
    contact.search_by_class(classification);
}
void update_contact_info(contact_book &contact)
{
    int index;
    cout << "Enter Index : ";
    cin >> index;
    cin.ignore();
    Person object = readInfo();
    contact.update_contact(object, index);
    contact.print_contacts();
}
void save_to_file(contact_book &contact)
{
    contact.save();
}
void load_from_file(contact_book &contact)
{
    contact.load();
}
void print_address(contact_book &contact)
{
    Person object = readInfo();
    contact.print_address_in();
}