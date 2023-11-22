#include <iostream>
using namespace std;


// Global variables
int a[10];
int n = 0;

// Function prototypes
void createArray();
void displayArray();
void insertElement(int m, int pos);
void deleteElement(int pos);

int main() {
    int ch, m, pos;
// While loop for menu selection
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create an Array\n";
        cout << "2. Display Array\n";
        cout << "3. Insert Element\n";
        cout << "4. Delete Element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
// Switch case for menu selection
        switch (ch) {
            case 1:
                createArray();
                break;
            case 2:
                displayArray();
                break;
            case 3:
                cout << "Enter element to insert: ";
                cin >> m;
                cout << "Enter position to insert at: ";
                cin >> pos;
                insertElement(m, pos);
                break;
            case 4:
                cout << "Enter position to delete from: ";
                cin >> pos;
                deleteElement(pos);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
// Function definition

// Create Array
void createArray() {
    cout << "Enter the size of the array: ";
    cin >> n;
    
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Array created successfully.\n";
}
//Display Array
void displayArray() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array elements:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
// Insert Array
void insertElement(int m, int pos) {

    for (int i = n; i >= pos; i--) {
        a[i] = a[i - 1];
    }

    a[pos] = m;
    n++;
    displayArray();
    cout << "Element inserted successfully.\n";
}
// Delete Array
void deleteElement(int pos) {

    for (int i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n--;
    displayArray();
    cout << "Element deleted successfully.\n";
}
