#ifndef ADDRESS_H
#define ADDRESS_H

#include <bits/stdc++.h>
using namespace std;

class Address
{
    string city;
    string country;
    string street_name;
    string street_number;

public:
    Address() : street_name(" "), street_number(" "), city(" "), country(" ") {}
    Address(string streetName, string streetNumber, string City, string Country) : street_name(streetName), street_number(streetNumber), city(City), country(Country) {}
    void set_city(string city)
    {
        this->city = city;
    }
    string get_city() const
    {
        return city;
    }
    void set_country(string country)
    {
        this->country = country;
    }
    string get_country() const
    {
        return country;
    }
    void set_street_name(string street_name)
    {
        this->street_name = street_name;
    }
    string get_street_name() const
    {
        return street_name;
    }
    void set_street_number(string street_number)
    {
        this->street_number = street_number;
    }
    string get_street_number() const
    {
        return street_number;
    }
    bool operator==(const Address &object) const
    {
        return street_name == object.street_name && street_number == object.street_number && city == object.city && country == object.country;
    }
    bool operator!=(const Address &object) const
    {
        return street_name != object.street_name || street_number != object.street_number || city != object.city || country != object.country;
    }
    Address &operator=(const Address &object)
    {
        if (this != &object)
        {
            city = object.city;
            country = object.country;
            street_name = object.street_name;
            street_number = object.street_number;
        }
        return *this;
    }
    void get_full_address() const
    {
        cout << "Full Adress : ";
        cout << street_number << ' ' << street_name << ' ' << city << ' ' << country << '\n';
    }
    friend ostream &operator<<(ostream &os, const Address &address);
};

ostream &operator<<(ostream &os, const Address &address)
{
    os << address.street_number << ' '
       << address.street_name << ' '
       << address.city << ' '
       << address.country;
    return os;
}
#endif
