#include <iostream>
using namespace std;


void bubblesort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


void selectionsort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;    
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}


void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[50], n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    do {
        cout << "\n--- SORTING MENU ---";
        cout << "\n1. Bubble Sort";
        cout << "\n2. Selection Sort";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bubblesort(a, n);
                cout << "After Bubble Sort: ";
                display(a, n);
                break;

            case 2:
                selectionsort(a, n);
                cout << "After Selection Sort: ";
                display(a, n);
                break;

            case 0:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice.";
        }
 
    } while (choice != 0);

    return 0;
}
