#include "palindrome.hpp"

/* Runner Technique */
bool isPalindrome(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        stack<int> s;

        // push the first half of the List into the stack
        while(fast != nullptr && fast->next != nullptr){
                s.push(slow->val);
                fast = fast->next->next;
                slow = slow->next;
        }

        // KEY: if the list's length is odd, then the fast ptr will end at the last node
        // else if the list's length is even, then the fast ptr will be a nullptr
        if(fast != nullptr){
                // no need to check the middle node for the odd case because it is definitely equal to itself
                slow = slow->next;
        }

        // check if the second half equals the first half
        while(slow){
                int curVal = slow->val;
                if(curVal != s.top()) return false;

                s.pop();
                slow = slow->next;
        }

        return true;
}