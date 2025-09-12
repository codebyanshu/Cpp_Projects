#include<iostream>
#include<fstream>
#include <string>
#include <cstdlib>
using namespace std;

// ------------------ Candidate Class ------------------
class candidate {
private:
    string name;
    string fname;
    string dbo;
    string party;
    string pass;

public:
    void sign_up() {
        cout << "New Candidate Signup Page:\n" << endl;
        cout << "Enter your username       : ";
        getline(cin, name);
        cout << "Enter your father's name  : ";
        getline(cin, fname);
        cout << "Enter your date of birth  : ";
        getline(cin, dbo);
        cout << "Enter your party name     : ";
        getline(cin, party);
        cout << "Enter your password       : ";
        getline(cin, pass);
        cout << "\nCandidate Sign-up successful!" << endl;
        cout << "--------------------------------------------------------------------------------\n\n" << endl;
    }

    void info_file() {
        ofstream store("candidates.txt", ios::app); // append mode
        store << "Username      : " << name << endl;
        store << "Father name   : " << fname << endl;
        store << "Date of birth : " << dbo << endl;
        store << "Party name    : " << party << endl;
        store << "Password      : " << pass << endl;
        store << "-----------------------------" << endl;
        store.close();
    }

    friend void display_candidates();
};

// ------------------ Voter Class ------------------
class voter {
private:
    string name, fname, dbo, voter_id, pass;
    int age;

public:
    void sign_up() {
        cout << "New Voter Signup Page:\n" << endl;
        cout << "Enter your name           : ";
        getline(cin, name);
        cout << "Enter your father's name  : ";
        getline(cin, fname);
        cout << "Enter your date of birth  : ";
        getline(cin, dbo);
        cout << "Enter your age            : ";
        cin >> age;
        cin.ignore();
        if (age < 18) {
            cout << "\n❌ You are not eligible for a voter ID (must be 18+)." << endl;
            return;
        }
        cout << "Enter your voter ID       : ";
        getline(cin, voter_id);
        cout << "Enter your password       : ";
        getline(cin, pass);
        cout << "\n✅ Voter Sign-up successful!" << endl;
        cout << "--------------------------------------------------------------------------------\n\n";

        info_file();
    }

    void info_file() {
        if (age < 18) return; // don’t save ineligible
        ofstream store("voters.txt", ios::app);
        store << "Name          : " << name << endl;
        store << "Father name   : " << fname << endl;
        store << "Date of birth : " << dbo << endl;
        store << "Age           : " << age << endl;
        store << "Voter ID      : " << voter_id << endl;
        store << "Password      : " << pass << endl;
        store << "-----------------------------" << endl;
    }

    friend void display_voters();
};

// ------------------ Display Functions ------------------
void display_candidates() {
    ifstream show("candidates.txt");
    string line;
    if (!show) {
        cout << "No candidates found.\n";
        return;
    }
    cout << "\nList of Candidates:\n";
    cout << "---------------------------------------------\n";
    while (getline(show, line)) {
        cout << line << endl;
    }
    cout << "---------------------------------------------\n";
    show.close();
}

void display_voters() {
    ifstream show("voters.txt");
    if (!show) {
        cout << "No voters found.\n";
        return;
    }
    string line;
    cout << "\nList of Voters:\n";
    cout << "---------------------------------------------\n";
    while (getline(show, line)) {
        cout << line << endl;
    }
    cout << "---------------------------------------------\n";
}

// ------------------ Menu Class ------------------
class Menu {
public:
    void show_menu() {
        candidate c1;
        voter v1;
        int choice;
        string input;

        while (true) {
            cout << "-------------------------WELCOME TO THE E-VOTING SYSTEM-----------------------" << endl;
            cout << "\nOptions :-\n" << endl;
            cout << "1. New Candidate." << endl;
            cout << "2. List of Candidates." << endl;
            cout << "3. New Voter." << endl;
            cout << "4. List of Voters." << endl;
            cout << "5. Show Election Result." << endl;
            cout << "6. Exit." << endl;
            cout << "\nEnter your choice : ";

            getline(cin, input);
            try {
                choice = stoi(input);
            } catch (...) {
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            system("CLS"); // use "clear" on Linux/Mac

            switch (choice) {
            case 1:
                c1.sign_up();
                c1.info_file();
                break;
            case 2:
                display_candidates();
                break;
            case 3:
                v1.sign_up();
                v1.info_file();
                break;
            case 4:
                display_voters();
                break;
            case 5:
                cout << "Election results feature will be added soon.\n";
                break;
            case 6:
                cout << "Exited the system successfully!" << endl;
                return; // exit loop
            default:
                cout << "Invalid choice. Try again." << endl;
            }
        }
    }
};

// ------------------ Main Function ------------------
int main() {
    Menu m1;
    m1.show_menu();
    return 0;
}
