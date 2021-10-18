#include "three_stacks.hpp"

bool ThreeStacks::isStackIdxInRange(unsigned int stackIdx){
        if(0 <= stackIdx && stackIdx < 3){
                return true;
        }
        cout << "ERROR: Invalid StackIdx" << endl;
        return false;
}

void ThreeStacks::pushTo(unsigned int stackIdx, int val){
        if(isStackIdxInRange(stackIdx)){
                ListNode* newNode = new ListNode(val);
                m_stacks[stackIdx]->push(newNode);
        }
}

void ThreeStacks::popFrom(unsigned int stackIdx){
        if(isStackIdxInRange(stackIdx)){
                if(m_stacks[stackIdx]->pop())
                        printf("Successfully popped from stack [%i]\n", stackIdx);
                else
                        printf("Stack [%i] is empty, nothing was popped\n", stackIdx);
        }
}

ListNode* ThreeStacks::topOf(unsigned int stackIdx){
        if(isStackIdxInRange(stackIdx)){
                ListNode* top = m_stacks[stackIdx]->top();
                if(top == nullptr){
                        cout << "Stack [" << stackIdx << "] is empty, no top is found" << endl;
                        return nullptr;
                }
                return top;
        }
        return nullptr;
}

bool ThreeStacks::emptyOf(unsigned int stackIdx){
        if(isStackIdxInRange(stackIdx)){
                return m_stacks[stackIdx]->empty();
        }
        // NOTE: invalid index will always be true
        return true;
}