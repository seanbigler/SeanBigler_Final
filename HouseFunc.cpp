// File: HouseFunc
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include "HouseFunc.h"
#include "HousePrice.h"
#include "csv.h" // library to read csv files
#include <algorithm>

using namespace std;

/*!
 * Read CSV Mock Data. Parses each record in the file to
 * an object of HousePrice house. Then, populate a vector
 * of HousePrice objects with all the records.
 * It uses special library to parse CSV file "csv.h"
 * @param fileIn File name <string>
 * @param hp Reference to Vector of HousePrice Objects
 */
void readCSV(const string fileIn,vector<HousePrice>& hp)
{
    io::CSVReader <7> in(fileIn);
    in.read_header(io::ignore_extra_column, "id", "number", "street", "city", "state", "postalCode", "price");
    int id; int number; string street; string city; string state; int postalCode; double price;
    while(in.read_row(id, number, street, city, state, postalCode, price))
    {
        HousePrice h1 (id, number, street, city, state, postalCode, price);
        hp.push_back(h1);
    }

    for(auto item:hp)
    {
        cout << item << endl;
    }
    cout << endl;
}


/*!
 * Sort the Vector of HousePrice Objects by price. Display the most affordable
 * and the most expensive house from the vector.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketValues(vector<HousePrice> &hp)
{
    // Sort by Price
    sort(begin(hp), end(hp));
    cout << "Most Affordable Home: " << hp[0] << endl;
    cout << "Most Expensive Home: " << hp.back() << endl;
    cout << endl;

}


/*!
 * Sort the Vector of HousePrice Objects by state. Display the
 * number of houses per state.
 * It uses a map to count instances per state.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketPerState(vector<HousePrice> &hp)
{
    // Sort by State
    sort(begin(hp), end(hp), [](const HousePrice& lhs, const HousePrice& rhs){return lhs.getState() < rhs.getState();});
    map<string, int> housemap;
    vector<string> states;
    int line = 1;
    string result;
    for (auto item:hp)
    {
        if (!housemap[item.getState()])
        {
            housemap[item.getState()] = 1;
            states.push_back(item.getState());
        }
        else
        {
            housemap[item.getState()] += 1;
        }

    }
    cout << "#Homes per State: " << endl;
    for (auto item:states)
    {
        result = item + " " + to_string(housemap[item]);
        cout << setw(10) << left << result;
        line++;
        if (line > 1 && line % 10 == 1)
        {
            cout << endl;
        }

    }


}
