#include <iostream>
#include "palindrome.hpp"

using namespace std;

int main(){

        // not palindrome - odd case
        vector<int> test1{1,2,3,4,5};
        ListNode* head = constructLL(test1);

        if(isPalindrome(head)){
                cout << "Test 1 Failed" << endl;
        } else {
                cout << "Test 1 Success!" << endl;
        }

        // not palindrome - even case
        vector<int> test2{1,2,3,4,5,6};
        head = constructLL(test2);

        if(isPalindrome(head)){
                cout << "Test 2 Failed" << endl;
        } else {
                cout << "Test 2 Success!" << endl;
        }

        // palindrome - odd case
        vector<int> test3{5,4,3,4,5};
        head = constructLL(test3);

        if(!isPalindrome(head)){
                cout << "Test 3 Failed" << endl;
        } else {
                cout << "Test 3 Success!" << endl;
        }

        // palindrome - even case
        vector<int> test4{1,2,3,3,2,1};
        head = constructLL(test4);

        if(!isPalindrome(head)){
                cout << "Test 4 Failed" << endl;
        } else {
                cout << "Test 4 Success!" << endl;
        }


        return 0;
}