#include "stack_linked_list.hpp"

void StackLL::push(ListNode* item){
        item->next = m_tail;
        m_tail = item;
}

bool StackLL::pop(){
        if(m_tail == nullptr){
                cout << "Stack is empty" << endl;
                return false;
        }
        ListNode* newTail = m_tail->next;
        delete m_tail;
        m_tail = newTail;
        return true;
}

ListNode* StackLL::top(){
        return m_tail;
}

bool StackLL::empty(){
        if(m_tail) return false;
        return true;
}