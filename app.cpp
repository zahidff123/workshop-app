#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string regNo;
    int workshopChoice;

public:
    Student(string n, string r, int w) {
        name = n;
        regNo = r;
        workshopChoice = w;
    }

    string getName() const { return name; }
    string getRegNo() const { return regNo; }
    int getWorkshopChoice() const { return workshopChoice; }

    void display() const {
        cout << "Name: " << name << " | Reg No: " << regNo << " | Workshop: " << workshopChoice << endl;
    }
};

class WorkshopManager {
private:
    vector<Student> students;

public:
    bool registerStudent(string name, string regNo, int choice) {
        if (name.empty() || regNo.empty()) {
            cout << "Error! Please fill all fields.\n";
            return false;
        }

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getRegNo() == regNo) {
                cout << "Error! Registration number already exists.\n";
                return false;
            }
        }

        if (choice < 1 || choice > 3) {
            cout << "Error! Select workshop between 1 and 3.\n";
            return false;
        }

        students.push_back(Student(name, regNo, choice));
        cout << "Successfully registered " << name << "!\n";
        return true;
    }

    void listRegistrations() const {
        if (students.empty()) {
            cout << "No records found.\n";
            return;
        }
        cout << "\n--- All Registered Students ---\n";
        for (int i = 0; i < students.size(); i++) {
            cout << i + 1 << ". ";
            students[i].display();
        }
        cout << "-------------------------------\n";
    }
};

int main() {
    WorkshopManager manager;
    int choice;

    do {
        cout << "\n=== Campus Event Registration ===\n";
        cout << "1. Register\n";
        cout << "2. View All\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, regNo;
            int wChoice;
            cout << "Enter Name: ";
            cin >> ws;
            getline(cin, name);
            cout << "Enter Reg No: ";
            cin >> regNo;
            cout << "Workshops: 1. AI  2. Web  3. Cyber\n";
            cout << "Enter Workshop choice: ";
            cin >> wChoice;

            manager.registerStudent(name, regNo, wChoice);
        } 
        else if (choice == 2) {
            manager.listRegistrations();
        }
        else if (choice == 3) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 3);

    return 0;
}