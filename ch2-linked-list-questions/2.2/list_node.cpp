#include "list_node.hpp"
#include <stdio.h>

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