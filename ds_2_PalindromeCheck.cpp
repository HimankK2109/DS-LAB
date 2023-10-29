#include <iostream>
using namespace std;

bool isPalindrome(string word) {
    int left = 0;
    int right = word.length() - 1;
    
    while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string word;

    cout << "Enter a word: ";
    cin >> word;

    if (isPalindrome(word)) {
        cout << word << " is a palindrome." << endl;
    } else {
        cout << word << " is not a palindrome." << endl;
    }

    return 0;
}
