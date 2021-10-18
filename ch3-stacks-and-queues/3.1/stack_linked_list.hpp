#include "list_node.hpp"

/* NOTE: this linked list is pointing reversed */
// so last/top of the stack linked list will point to its previous/the node right below it
// meaning the very first list node will point to nullptr
class StackLL {
private:
        ListNode* m_tail;
public:
        StackLL(): m_tail(nullptr) {}
        void push(ListNode* item);
        bool pop();
        ListNode* top();
        bool empty();
};