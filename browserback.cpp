#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

stack<string> history;
stack<string> forward_stack;
map<string, int> visitCount;

void visitPage(const string& page) {
    history.push(page);
    while (!forward_stack.empty()) forward_stack.pop();

    visitCount[page]++;
    cout << "Visited: " << page << endl;
}

void goBack() {
    if (history.empty()) {
        cout << "No pages in history." << endl;
        return;
    }

    string lastPage = history.top();
    history.pop();
    forward_stack.push(lastPage);

    cout << "Going back from: " << lastPage << endl;

    if (!history.empty()) {
        cout << "Current page: " << history.top() << endl;
    } else {
        cout << "No pages left in history." << endl;
    }
}

void goForward() {
    if (forward_stack.empty()) {
        cout << "No pages to go forward to." << endl;
        return;
    }

    string nextPage = forward_stack.top();
    forward_stack.pop();
    history.push(nextPage);

    cout << "Going forward to: " << nextPage << endl;
    cout << "Current page: " << nextPage << endl;
}

void showHistory() {
    if (history.empty()) {
        cout << "History is empty." << endl;
        return;
    }

    vector<string> pages;
    stack<string> temp = history;
    while (!temp.empty()) {
        pages.push_back(temp.top());
        temp.pop();
    }
    reverse(pages.begin(), pages.end());

    cout << "History: ";
    for (size_t i = 0; i < pages.size(); ++i) {
        cout << pages[i] << "(" << visitCount[pages[i]] << ")";
        if (i != pages.size() - 1) cout << " -> ";
    }
    cout << endl;
}

void countVisits() {
    cout << "Enter page name: ";
    string page;
    getline(cin, page);

    int count = visitCount[page];
    cout << "Page " << page << " visited " << count << " times." << endl;
}

void menu() {
    int choice;
    string page;

    while (true) {
        cout << "\n1. Visit Page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Show History" << endl;
        cout << "4. Forward" << endl;
        cout << "5. Count Visits" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter page name: ";
                getline(cin, page);
                visitPage(page);
                break;

            case 2:
                goBack();
                break;

            case 3:
                showHistory();
                break;

            case 4:
                goForward();
                break;

            case 5:
                countVisits();
                break;

            case 6:
                cout << "Exiting browser simulation." << endl;
                return;

            default:
                cout << "Invalid choice." << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
