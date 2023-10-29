#include<iostream>
using namespace std;

int main() {
    int marks[5][5];

    // Inputting marks
    for (int i = 0; i < 5; i++) {
        cout << "Enter marks for student " << i+1 << ":\n";
        for (int j = 0; j < 5; j++) {
            cout << "Subject " << j+1 << ": ";
            cin >> marks[i][j];
        }
    }

    // Calculate total and average for each student
    for (int i = 0; i < 5; i++) {
        int total = 0;
        for (int j = 0; j < 5; j++) {
            total += marks[i][j];
        }
        float average = total / 5.0;
        cout << "Student " << i+1 << " - Total: " << total << ", Average: " << average << endl;
    }

    return 0;
}