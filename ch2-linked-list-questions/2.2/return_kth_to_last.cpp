#include <iostream>
#include <vector>

/* NOTE: List Node */
#include "list_node.hpp"

using namespace std;



/* helper function */
ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur){
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
        }
        return prev;
}

/* solution */
// NOTE: asssuming kth last's 'k' is greater or equal to 0 with 0 being the last element
int returnKLast(ListNode* head, int k){
        ListNode* cur = reverseLL(head);

        while(k > 0){
                cur = cur->next;
                k--;
                if(cur == nullptr) return -1;
        }

        return cur->val;
}

/* solution 2 */
// KEY: another solution using two pointers
// Time = O(N)
// Space = O(1)

int main() {

        vector<int> vals{1,2,3,4,5};

        ListNode* head = constructLL(vals);

        int result = returnKLast(head, 14);

        cout << result << endl;

        return 0;
}