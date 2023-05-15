#include <vector>

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
       
        int dxor = 0;
        for (int num : derived) {
            dxor ^= num;
        }
        return dxor==0;
    }
};
