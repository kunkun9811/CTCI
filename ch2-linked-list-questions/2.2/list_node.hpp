#include <vector>

using namespace std;

struct ListNode {
        int val;
        ListNode* next;

        ListNode(): val(0), next(nullptr) {}
        ListNode(int val): val(val), next(nullptr) {}
        ListNode(int val, ListNode* next) : val(val), next(next) {}
};

ListNode* constructLL(vector<int>& vals);
void printLL(ListNode* head);