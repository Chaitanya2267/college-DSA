#include <iostream>
using namespace std;

int main() {
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;
    int choice, i, j, k;

    
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter elements of first matrix:\n";
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            cin >> A[i][j];
        }
    }

    
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    cout << "Enter elements of second matrix:\n";
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            cin >> B[i][j];
        }
    }

    do {
        cout << "\n\n----- MATRIX OPERATIONS MENU -----";
        cout << "\n1. Matrix Addition";
        cout << "\n2. Matrix Subtraction";
        cout << "\n3. Matrix Multiplication";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                if (r1 == r2 && c1 == c2) {
                    for (i = 0; i < r1; i++) {
                        for (j = 0; j < c1; j++) {
                            C[i][j] = A[i][j] + B[i][j];
                        }
                    }

                    cout << "Resultant Matrix (Addition):\n";
                    for (i = 0; i < r1; i++) {
                        for (j = 0; j < c1; j++) {
                            cout << C[i][j] << " ";
                        }
                        cout << endl;
                    }
                } else {
                    cout << "Addition not possible. Matrix dimensions must be same.";
                }
                break;

            case 2: 
                if (r1 == r2 && c1 == c2) {
                    for (i = 0; i < r1; i++) {
                        for (j = 0; j < c1; j++) {
                            C[i][j] = A[i][j] - B[i][j];
                        }
                    }

                    cout << "Resultant Matrix (Subtraction):\n";
                    for (i = 0; i < r1; i++) {
                        for (j = 0; j < c1; j++) {
                            cout << C[i][j] << " ";
                        }
                        cout << endl;
                    }
                } else {
                    cout << "Subtraction not possible. Matrix dimensions must be same.";
                }
                break;

            case 3: 
                if (c1 == r2) {
                    for (i = 0; i < r1; i++) {
                        for (j = 0; j < c2; j++) {
                            C[i][j] = 0;
                            for (k = 0; k < c1; k++) {
                                C[i][j] += A[i][k] * B[k][j];
                            }
                        }
                    }

                    cout << "Resultant Matrix (Multiplication):\n";
                    for (i = 0; i < r1; i++) {
                        for (j = 0; j < c2; j++) {
                            cout << C[i][j] << " ";
                        }
                        cout << endl;
                    }
                } else {
                    cout << "Multiplication not possible. Columns of first matrix must equal rows of second matrix.";
                }
                break;

            case 0:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice.";
        }

    } while (choice != 0);

    return 0;
}
