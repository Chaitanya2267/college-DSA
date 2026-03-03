#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[50];
    int n, choice, key, i;
    bool found;

    // Array creation
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Display array
    cout << "Array elements: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    do {
        cout << "\n\n----- SEARCH MENU -----";
        cout << "\n1. Linear Search";
        cout << "\n2. Binary Search";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1: { // Linear Search
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

                if (!found)
                    cout << "Element not found.";
                break;
            }

            case 2: { // Binary Search
                cout << "Enter element to search: ";
                cin >> key;

                sort(arr, arr + n); // required for binary search

                cout << "Sorted Array: ";
                for (i = 0; i < n; i++)
                    cout << arr[i] << " ";

                int low = 0, high = n - 1, mid;
                found = false;

                while (low <= high) {
                    mid = (low + high) / 2;

                    if (arr[mid] == key) {
                        cout << "\nElement found at position " << mid;
                        found = true;
                        break;
                    }
                    else if (arr[mid] < key)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }

                if (!found)
                    cout << "\nElement not found.";
                break;
            }

            case 0: {
                cout << "Exiting program...";
                break;
            }

            default:
                cout << "Invalid choice.";
        } 

    } while (choice != 0);

    return 0;
}
