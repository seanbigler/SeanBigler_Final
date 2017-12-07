// File: HousePrice
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include "HousePrice.h"

/**
 * Default constructor with no arguments
 */
HousePrice::HousePrice() {}
/**
 * Constructor with 7 arguments
 * @param id : id of house
 * @param number : house number
 * @param street : street name
 * @param city : city name
 * @param state : state name
 * @param postalCode : postal code number
 * @param price : price as decimal number
 */
HousePrice::HousePrice(int id, int number, const string &street, const string &city, const string &state,
                       int postalCode, double price) : id(id), number(number), street(street), city(city), state(state),
                                                       postalCode(postalCode), price(price)
{}
/**
 * Method to get house price
 * @return : price of house
 */
double HousePrice::getPrice() const
{
    return price;
}
/**
 * Method to get State house is in
 * @return : the state name
 */
const string &HousePrice::getState() const
{
    return state;
}
/**
 * Function overloading << operator to output object
 * @param os : output stream
 * @param price : HousePrice object
 * @return : HousePrice object members as output
 */
ostream &operator<<(ostream &os, const HousePrice &price)
{
    os << "id: " << price.id << " number: " << price.number << " postalCode: " << price.postalCode << " street: " << price.street << " city: " << price.city
       << " state: " << price.state << " price: " << price.price;
    return os;
}
/**
 * Overloads < operator based on price
 * @param rhs : HousePrice object that current object is compared against
 * @return : true or false depending on which object price is greater
 */
bool HousePrice::operator<(const HousePrice &rhs) const
{
    return price < rhs.price;
}
/**
 * Overloads > operator based on price
 * @param rhs : HousePrice object that current object is compared against
 * @return : true or false depending on which object price is greater
 */
bool HousePrice::operator>(const HousePrice &rhs) const
{
    return rhs < *this;
}
/**
 * Overloads <= operator based on price
 * @param rhs : HousePrice object that current object is compared against
 * @return : true or false depending on if object is less-than or equal to rhs
 */
bool HousePrice::operator<=(const HousePrice &rhs) const
{
    return !(rhs < *this);
}
/**
 * Overloads >= operator based on price
 * @param rhs : HousePrice object that current object is compared against
 * @return : true or false depending on if object is greater-than or equal to rhs
 */
bool HousePrice::operator>=(const HousePrice &rhs) const
{
    return !(*this < rhs);
}

