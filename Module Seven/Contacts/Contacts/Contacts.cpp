#include <iostream>
#include <string>
using namespace std;

class ContactNode {
public:
    // Constructor
    ContactNode(string name, string phoneNumber) {
        contactName = name;
        contactPhoneNumber = phoneNumber;
        nextNodePtr = nullptr;
    }

    // Accessors
    string GetName() const {
        return contactName;
    }

    string GetPhoneNumber() const {
        return contactPhoneNumber;
    }

    ContactNode* GetNext() const {
        return nextNodePtr;
    }

    // Mutator: Inserts a node after current one
    void InsertAfter(ContactNode* newNode) {
        ContactNode* temp = nextNodePtr;
        nextNodePtr = newNode;
        newNode->nextNodePtr = temp;
    }

    // Print contact details
    void PrintContactNode() const {
        cout << "Name: " << contactName << endl;
        cout << "Phone number: " << contactPhoneNumber << endl;
    }

private:
    string contactName;
    string contactPhoneNumber;
    ContactNode* nextNodePtr;
};

int main() {
    string name1, phone1;
    string name2, phone2;
    string name3, phone3;

    // Read input for 3 contacts
    getline(cin, name1);
    getline(cin, phone1);
    getline(cin, name2);
    getline(cin, phone2);
    getline(cin, name3);
    getline(cin, phone3);

    // Create ContactNode objects
    ContactNode* person1 = new ContactNode(name1, phone1);
    ContactNode* person2 = new ContactNode(name2, phone2);
    ContactNode* person3 = new ContactNode(name3, phone3);

    // Link the contacts
    person1->InsertAfter(person2);
    person2->InsertAfter(person3);

    // Output individual persons
    cout << "Person 1: " << person1->GetName() << ", " << person1->GetPhoneNumber() << endl;
    cout << "Person 2: " << person2->GetName() << ", " << person2->GetPhoneNumber() << endl;
    cout << "Person 3: " << person3->GetName() << ", " << person3->GetPhoneNumber() << endl;

    // Output full contact list
    cout << "\nCONTACT LIST";
    ContactNode* current = person1;

    while (current != nullptr) {
        cout << endl;
        current->PrintContactNode();
        current = current->GetNext();
    }

    cout << endl;

    // Free allocated memory
    delete person1;
    delete person2;
    delete person3;

    return 0;
}