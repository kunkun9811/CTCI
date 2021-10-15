#include <vector>

using namespace std;

class Tests {
private:
        vector<int> m_data;
public:
        Tests(vector<int> data): m_data(data) {}

        bool testCorrectness(int k, int result){
                int size = m_data.size();
                int kthLastVal = m_data[size-1-k];
                
                return result == k;
        }
};