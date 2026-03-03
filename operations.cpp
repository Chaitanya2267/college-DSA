#include <iostream>
using namespace std;

int main() {
    int arr[50] = {20, 30, 52, 47, 60}; 
    int n = 5;
    int choice, pos, value, key, i;
    bool found;

    do {
        cout << "\n\n----- ARRAY OPERATIONS MENU -----";
        cout << "\n1. Insert Element";
        cout << "\n2. Delete Element";
        cout << "\n3. Traverse (Display) Array";
        cout << "\n4. Search Element";
        cout << "\n5. Update Element";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Insertion
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter value: ";
                cin >> value;

                for (i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;

                cout << "Element inserted successfully. \nUpdated Array: ";
                for (i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                break;

            case 2: // Deletion
                cout << "Enter position to delete: ";
                cin >> pos;

                for (i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;

                cout << "Element deleted successfully. \nUpdated Array: ";
                for (i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                break;

            case 3: // Traversal
                cout << "Array elements: ";
                for (i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                break;

            case 4: // Searching
                cout << "Enter element to search: ";
                cin >> key;
                found = false;
                for (i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        cout << "Element found at position " << i;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Element not found.";
                }
                break;

            case 5: // Updation
                cout << "Enter position to update: ";
                cin >> pos;
                cout << "Enter new value: ";
                cin >> value;
                
                arr[pos] = value;

                cout << "Element updated successfully. \nUpdated Array: ";
                for (i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                break;

            case 0:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice! Please try again.";
        }

    } while (choice != 0);

    return 0;
}