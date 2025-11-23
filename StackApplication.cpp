#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function 1: Reverse a string
string reverseString(const string &str) {
    stack<char> st;
    for (char c : str) st.push(c);

    string rev = "";
    while (!st.empty()) {
        rev += st.top();
        st.pop();
    }
    return rev;
}

// Function 2: Check balanced parentheses
bool isBalanced(const string &expr) {
    stack<char> st;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                cout << "Unmatched closing bracket: " << c << endl;
                return false;
            }
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                cout << "Mismatched bracket: " << top << " and " << c << endl;
                return false;
            }
            st.pop();
        }
    }

    if (st.empty()) {
        cout << "Expression is Balanced and Stack is Empty\n";
        return true;
    } else {
        cout << "Expression is Not Balanced \n";
        cout << "Remaining stack elements: ";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
        return false;
    }
}

// Function 3: Undo operations
string undoOperations(const string &input) {
    stack<char> st;
    for (char c : input) {
        if (c == '#') {   // '#' = undo last operation
            if (!st.empty()) st.pop();
        } else {
            st.push(c);
        }
    }
    string result = "";
    while (!st.empty()) {
        result = st.top() + result; // collect in reverse
        st.pop();
    }
    return result;
}

int main() {
    int choice;
    string input;

    do {
        cout << "\n=== Stack Applications Menu ===\n";
        cout << "1. Reverse a String\n";
        cout << "2. Check Balanced Parentheses\n";
        cout << "3. Undo Operations (use # as undo)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

        switch (choice) {
            case 1: {
                cout << "Enter string: ";
                getline(cin, input);
                cout << "Reversed string: " << reverseString(input) << endl;
                break;
            }
            case 2: {
                cout << "Enter expression: ";
                getline(cin, input);
                isBalanced(input);  // function already handles printing
                break;
            }
            case 3: {
                cout << "Enter text (use # for undo): ";
                getline(cin, input);
                cout << "Final text after undo: " << undoOperations(input) << endl;
                break;
            }
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}