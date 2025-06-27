//
// Created by ahmed on 20/11/2021.
//

#include "Rule.h"
#include <iostream>

Rule::Rule() {}

// make the rule_as_string member be same as 'rule_as_string'
Rule::Rule(string input) {
    rule_as_string = input;
    size_t i, start,len; // len is number of characters in a category
    string category;

    i = input.find(" --> "); // i is first after mother
    start = i + 5;          // start is first of daughter
    len = i;                // length of mother is i
    mother = input.substr(0, len); // make string from mother

    /* push all daughters up to last comma */
    while((i = input.find(",", start)) != string::npos) {
        len = i-start;     // length of current daughter
        category = input.substr(start, len);
        daughters.push_back(category);
        start = i + 1;
    }
    category = input.substr(start);
    daughters.push_back(category);
}


// show the the rule_as_string member
void Rule::show() {
    cout << mother;
    cout << " --> " << endl;
    for(int i = 0; i < daughters.size(); i++) {
        cout << "     " << daughters[i] << endl;
    }
}
