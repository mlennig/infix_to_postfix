//
//  Mim_Lennig_A2_testcases.cpp
//  Mim_Lennig_A2
//
//  Created by Miriam Lennig on 2016-09-28.
//  Copyright © 2016 Miriam Lennig. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include "Mim_Lennig_A2_classes.hpp"
using namespace std;



int main() {
    string inputString;
    
    while(true){
        cout << "Please enter a mathematical expression: ";
        getline (cin, inputString);
        cout << endl;
        
        ShuntingYard sy = ShuntingYard(inputString);
       
        cout << "sy.printinputString():\t\t";
        sy.printinputString();
        cout << endl << endl;
        cout << "sy.printinfix():\t\t";
        sy.printinfix();
        cout << endl << endl;
        cout << "sy.printpostfix():\t\t";
        sy.printpostfix();
        cout << endl << endl;
        cout << "sy.printresult():\t\t";
        sy.printresult();
        cout << endl << endl;
        
    }

}
