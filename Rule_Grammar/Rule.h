//
// Created by ahmed on 20/11/2021.
//

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Rule {
public:
    Rule();
    Rule(string rule_as_string);
    string rule_as_string;
    string mother;
    vector<string> daughters;
    void show();

};
