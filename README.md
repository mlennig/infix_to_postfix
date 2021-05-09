// In main
string profInput;
string exp;

// Remove spaces from input string and copies chars into new string location
for (int i = 0; i < size.profInput; i ++)
int j = 0;
	if (!isspace(profInput[i]))
		exp[j] = profInput[i];
		j++;

// In header file

// Turns infix notation into postfix notation
infix2postfix(stack<string> infix){

stack<string> result;

stack<string> operator;	// Class Stack in header file

// Run thru end of expression size
for (int i = 0; i < infix.size(); i ++){

	// If char is a digit or a decimal, copy char into char array result
	if ((infix[i] == isdigit()) || (infix[i] == ‘.’)) 
		result += exp[i];
	
	// If char is an open paren, push it onto the operator stack
	else if (exp[i] == ‘(‘ )
		s.push();
	
	// If the char is a close paren,
	else if (exp[i] == ‘)’ )
		while (!s.empty())		//  While there are still operators left in the stack,
			if (s.top() == ‘(‘ )		// if the top of the stack is an open paren, 
				s.pop();		// remove the open paren					
				break;		// end the loop
			else 
				result += s.top();	// if the top of the stack is not an open paren, 
								// copy the operator at the top of the stack to the result array
				s.pop();			// delete the operator from the top of the stack


	// If the char is one of these operators
	else if ((exp[i] == ‘+’)||(exp[i] == ‘-’)||(exp[i] == ‘*’)||(exp[i] == ‘/’)||(exp[i] == ‘^’) )
		// If operator stack is empty, push the operator onto the stack
		if (s.empty())
			s.push(exp[i]);
		// If the stack is not empty, 
		else
			while (!s.empty())
				if (!has_higher_precedence)	// and the char at the top of the stack has lower precedence
					s.push(exp[i]);			// add the new operator
					break;				// exit loop
				else 						// If the char at the top of the stack has equal or higher precedence
					result += s.top();		// copy the operator to the result array		
					s.pop();				// delete the operator from the stack		
					s.push(exp[i]);			// add new operator to stack
}

// While the stack is not empty add the operators from the stack 
// to the result array.
// Delete the operator from the array once it has been copied. 
// Continue until operator stack is empty. 
while (!s.empty()) {
	result += s.top();
	s.pop();
}
				
		
// Determine if operator at the top of the stack has higher precedence
// compared to the operator currently being looked at in the expression
bool has_higher_precedence (char s.top(), char operator) {
int x, y; 
if (s.top() == ‘(‘) // not a thing
	return true;
if (s.top() == ^)
	x = 2;
if ((s.top() == ‘ * ‘) || (s.top() == ‘/ ‘))
	x = 1;
if ((s.top() == ‘ + ‘) || (s.top() == ‘- ‘))
	x = 0

if (operator == ‘(‘)
	return false;
if (operator == ^)
	y = 2;
if ((operator == ‘ * ‘) || (operator == ‘/ ‘))
	y = 1;
if ((operator == ‘ + ‘) || (operator == ‘- ‘))
	y = 0

if(x > y)
	return true;
else
	return false;

}


