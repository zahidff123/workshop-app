#include <iostream>
using namespace std;

int main() {
    string name, reg_no;
    int choice;

    cout<<"Enter Student Name";
    cin >> name;

    cout << "Enter Registration Number";
    cin >> reg_no;

    cout << "Workshops: 1.AI  2.Web  3.Cyber\n";
    cout << "Enter Choice (1, 2, or 3): ";
    cin >> choice;

    if (choice == 1 || choice == 2 || choice == 3) {
        cout << "Success! " << name << " (" << reg_no << ") registered for Workshop " << choice;
    } else {
        cout << "Error! Invalid workshop choice.";
    }

    return 0;
}