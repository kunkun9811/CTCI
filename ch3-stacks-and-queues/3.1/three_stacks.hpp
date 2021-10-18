#include "stack_linked_list.hpp"
#include <vector>

using namespace std;

class ThreeStacks {
private:
        vector<StackLL*> m_stacks;

public:
        ThreeStacks(){
                for(int i = 0; i < 3; i++)
                        m_stacks.push_back(new StackLL());
        }
        
        bool isStackIdxInRange(unsigned int stackIdx);
        void pushTo(unsigned int stackIdx, int val);
        void popFrom(unsigned int stackIdx);
        ListNode* topOf(unsigned int stackIdx);
        bool emptyOf(unsigned int stackIdx);
};