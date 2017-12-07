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

ostream &operator<<(ostream &os, const HousePrice &price)
{
    os << "id: " << price.id << " number: " << price.number << " postalCode: " << price.postalCode << " street: " << price.street << " city: " << price.city
       << " state: " << price.state << " price: " << price.price;
    return os;
}

