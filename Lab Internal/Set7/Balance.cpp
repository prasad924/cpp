#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool areParenthesesBalanced(const string& expression) {
    stack<char> parenthesesStack;

    for (size_t i = 0; i < expression.size(); ++i) {
        char bracket = expression[i];

        if (bracket == '(' || bracket == '{' || bracket == '[') {
            parenthesesStack.push(bracket);
        } else if (bracket == ')' || bracket == '}' || bracket == ']') {
            if (parenthesesStack.empty()) {
                return false; // Closing bracket with no matching opening bracket
            }

            char top = parenthesesStack.top();
            parenthesesStack.pop();

            if ((bracket == ')' && top != '(') ||
                (bracket == '}' && top != '{') ||
                (bracket == ']' && top != '[')) {
                return false; // Mismatched opening and closing brackets
            }
        }
    }

    return parenthesesStack.empty(); // Check if any opening brackets are unmatched
}

int main() {
    string expression = "((a+b)*(c-d)";
    
    if (areParenthesesBalanced(expression)) {
        cout << "The parentheses are balanced.\n";
    } else {
        cout << "The parentheses are not balanced.\n";
    }

    return 0;
}

