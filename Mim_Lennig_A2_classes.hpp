//
//  Mim_Lennig_A2_classes.hpp
//  Mim_Lennig_A2
//
//  Created by Miriam Lennig on 2016-09-28.
//  Copyright © 2016 Miriam Lennig. All rights reserved.
//

#ifndef Mim_Lennig_A2_classes_hpp
#define Mim_Lennig_A2_classes_hpp
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <math.h>
using namespace std;

class ShuntingYard{
    string inputString;
    vector<string> infix;
    deque<string> postfix;
    deque<string> infix2postfix();
    vector<string> parser();
    void computeResult();
    double result;
    bool isnumber(string);
    bool has_higher_precedence(string, string);
    bool isoperator(char);
public:
    ShuntingYard(string);
    void printinputString();
    void printinfix();
    void printpostfix();
    void printresult();
};



#endif /* Mim_Lennig_A2_classes_hpp */