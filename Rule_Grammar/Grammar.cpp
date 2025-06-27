//
// Created by ahmed on 20/11/2021.
//
#include "Grammar.h"
#include <iostream>
#include <fstream>
#include <vector>

Grammar::Grammar(){}

// open the file, get its lines one-by-one, feeding these to Rule constructor
// and using to build up rules member
Grammar::Grammar(string fname) {
    ifstream file;
    string line;
    file.open(fname);

    while (getline(file, line)) {
        Rule rule(line);
        rules.push_back(rule);
    }
}

// go thru rules using each members show method
void Grammar::show() {
    for (int i = 0; i < rules.size(); i++) {
        rules[i].show();
    }
    cout << "Number of rules - " << rules.size() << endl;
}