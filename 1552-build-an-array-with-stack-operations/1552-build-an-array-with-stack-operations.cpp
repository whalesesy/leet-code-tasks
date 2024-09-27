class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector <string> res;
     for(int i=0;i<target.size();i++) {
        int diff =target[i]-(i==0?0:target[i-1]);
        for(int j=0;j<diff-1;j++) res.push_back("Push");
        for(int j=0;j<diff-1;j++) res.push_back("Pop");
            res.push_back("Push");
        }
    return res;
    }
};