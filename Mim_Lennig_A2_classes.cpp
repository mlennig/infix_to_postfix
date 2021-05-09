//
//  Mim_Lennig_A2_classes.cpp
//  Mim_Lennig_A2
//
//  Created by Miriam Lennig on 2016-09-28.
//  Copyright © 2016 Miriam Lennig. All rights reserved.
//

#include "Mim_Lennig_A2_classes.hpp"
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <math.h>
using namespace std;

// Turn infix notation into postfix notation
deque <string> ShuntingYard::infix2postfix(){
    deque<string> postfix;                   // Postfix result
    stack<string> operatorStack;        // The operator stack
    
    // Iterate thru infix tokens
    for (int i = 0; i < infix.size(); i++){
        if(isnumber(infix[i])){
            // Token is a number, push into postfix stack
            postfix.push_back(infix[i]);
        }
        else if (infix[i] == "(" )
            // Token is an open paren, push onto operator stack
            operatorStack.push(infix[i]);
        else if (infix[i] == ")" ){
            // Token is a close paren
            while (!operatorStack.empty())
                if (operatorStack.top() == "(" ){
                    // Top of the stack is an open paren, remove the open paren, end loop
                    operatorStack.pop();
                    break;
                }
                else{
                    // Top of stack is not an open paren,
                    postfix.push_back(operatorStack.top());      // copy the operator at the top of the stack to the postfix vector
                    operatorStack.pop();                           // Remove the operator from the top of the stack
                    
                }
        }
        else if ((infix[i] == "+") || (infix[i] == "-") || (infix[i] == "*") || (infix[i] == "/") || (infix[i] == "^")){
            // Token is an operator
            if (operatorStack.empty())
                // Operator stack is empty, so add new operator to operator stack
                operatorStack.push(infix[i]);
            else {
                while (!operatorStack.empty()){
                    // The operator stack is not empty,
                    if (!has_higher_precedence(operatorStack.top(), infix[i])){
                        // Token at the top of the stack has lower precedence, so add the new operator to the operator stack
                        operatorStack.push(infix[i]);
                        break;
                    }
                    else {
                        // Operator has equal or higher precedence, so copy the operator to the postfix stack
                        postfix.push_back(operatorStack.top());
                        // Delete the operator from the operator stack
                        operatorStack.pop();
                        // Add new operator to operator stack
                        operatorStack.push(infix[i]);
                        break;
                    }
                }
            }
        }
        else
            cout << "We didn't expect to get here." << endl;
}
    
    while (!operatorStack.empty()) {
        // Operator stack is not empty, so push operator from the top of the operator stack onto postfix stack
        postfix.push_back(operatorStack.top());
        // Remove operator from the top of the operator stack
        operatorStack.pop();
    }
    
     return postfix;
}

bool ShuntingYard::has_higher_precedence(string opStackToken, string inVectorToken){
    int x = 0, y = 0;
        if (opStackToken == "^")
            x = 2;
        else if ((opStackToken == "*") || (opStackToken == "/"))
            x = 1;
        else if ((opStackToken == "+") || (opStackToken == "-"))
            x = 0;
        else if (opStackToken == "(")
            return false;

        if (inVectorToken == "^")
            y = 2;
        else if ((inVectorToken == "*") || (inVectorToken == "/"))
            y = 1;
        else if ((inVectorToken == "+") || (inVectorToken == "-"))
            y = 0;
        else if (inVectorToken == "(")
            return false;
    
        if(x > y)
            return true;
        else
            return false;
};

bool ShuntingYard::isnumber(string inVectorToken){
   return inVectorToken.find_first_not_of("0123456789.") == string::npos;
};

vector<string> ShuntingYard::parser(){
    vector<string> infix;
    string buffer = "";
    
    for(int i = 0; i < inputString.size(); i++){
        if((isdigit(inputString[i])) || (inputString[i] == '.'))
           buffer += inputString[i];
        else if(isspace(inputString[i]))
            continue;
        else if(isoperator(inputString[i])){
            if(buffer == ""){
                buffer += inputString[i];
                infix.push_back(buffer);
                buffer = "";
            }
            else{
                infix.push_back(buffer);
                buffer = "";
                buffer += inputString[i];
                infix.push_back(buffer);
                buffer = "";
            }
        }
    }
    if(buffer != "")
        infix.push_back(buffer);
    return infix;
}

bool ShuntingYard::isoperator(char x){
    return (x == '(') || (x == ')') || (x == '^') || (x == '*') || (x == '/') || (x == '+') || (x == '-');
}

void ShuntingYard::printinputString(){
    cout << inputString;
}

void ShuntingYard::printinfix(){
    for(int i = 0; i < infix.size(); i++)
        cout << infix[i] << "\t\t";
}

void ShuntingYard::printpostfix(){
    for (int i = 0; i < postfix.size(); i++)
        cout << postfix[i] << "\t";
    cout << endl;
}

ShuntingYard::ShuntingYard(string inString){
    inputString = inString;
    infix = parser();
    postfix = infix2postfix();
    computeResult();
}

void ShuntingYard::computeResult(){
    stack<double> resultStack;
    
    for (int i = 0; i < postfix.size(); i++){
        if (isnumber(postfix[i])){
            resultStack.push(stof(postfix[i]));
        }
        else {
                float c;
                float b = resultStack.top();
                resultStack.pop();
                float a = resultStack.top();
                resultStack.pop();
                
                if(postfix[i] == "^"){
                    c = pow(a, b);
                    resultStack.push(c);
                }
                
                if(postfix[i] == "*"){
                    c = a*b;
                    resultStack.push(c);
                }
                
                if(postfix[i] == "/"){
                    c = a/b;
                    resultStack.push(c);
                }
                   
                if(postfix[i] == "+"){
                    c = a + b;
                    resultStack.push(c);
                }
                   
                if(postfix[i] == "-"){
                    c = a - b;
                    resultStack.push(c);
                }
            }
    }
    result = resultStack.top();
}

void ShuntingYard::printresult(){
    cout << result << endl << endl;
}



