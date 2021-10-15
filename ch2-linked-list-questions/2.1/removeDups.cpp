#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
        int val;
        ListNode* next;

        ListNode(): val(0), next(nullptr) {}
        ListNode(int val): val(val), next(nullptr) {}
        ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* constructLL(vector<int>& vals){
        if(vals.size() == 0) return nullptr;

        ListNode* head = nullptr;
        ListNode* current = nullptr;
        for(int val : vals){
                if(head == nullptr){
                        head = new ListNode(val);
                        current = head;
                } else {
                        ListNode* node = new ListNode(val);
                        current->next = node;
                        current = node;
                }
        }
        return head;
}

void printLL(ListNode* head){
        ListNode* cur = head;
        int i = 0;
        while(cur){
                printf("%i: %i\n", i, cur->val);
                i++;
                cur = cur->next;
        }
}

/* NOTE: with hashmap */
// time = O(N)
// space = O(N)
ListNode* removeDupsHashMap(ListNode* head){
        unordered_set<int> uset;
        ListNode* cur = head;
        uset.insert(cur->val);
        while(cur->next){
                int nextNodeVal = cur->next->val;
                if(uset.find(nextNodeVal) != uset.end()){
                        // KEY: if next node value is a duplicate, remove it and delete it from memory
                        // NOTE: do not move the cur ptr to the next node because the next node MIGHT also be a duplicate
                        ListNode* tmp = cur->next;
                        cur->next = cur->next->next;
                        delete tmp;
                } else {
                        uset.insert(nextNodeVal);
                        cur = cur->next;
                }  
        }
        return head;
}

/* NOTE: with no hashmap or any other temprary buffer */
// time = O(N^2)
// space = O(1)
ListNode* removeDups(ListNode* head){
        ListNode* cur = head;
        while(cur){
                ListNode* comparePtr = cur;
                while(comparePtr->next){
                        if(comparePtr->next->val == cur->val){
                                ListNode* tmp = comparePtr->next;
                                comparePtr->next = comparePtr->next->next;
                                delete tmp;
                        } else {
                                comparePtr = comparePtr->next;
                        }
                }
                cur = cur->next;
        }
        return head;
}

int main() {

        // vector<int> vals{1,2,2,2,2,3,3,3,3,3,5,5,5,5,5,5,5,3,3,2,2,2,2,3,3,3,3,3,3,4,1,1,1,1,1,1,5};
        vector<int> vals{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

        /* hashmap solution */
        ListNode* head = constructLL(vals);
        head = removeDupsHashMap(head);
        printLL(head);

        cout << endl;

        /* no buffer solution */
        ListNode* head2 = constructLL(vals);
        head2 = removeDups(head2);
        printLL(head2);

        return 0;
}