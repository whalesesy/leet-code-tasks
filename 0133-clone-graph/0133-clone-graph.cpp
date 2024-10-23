/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        unordered_map<Node*,int>m;
        stack<Node*>s;
        s.push(node);
        Node*ptr=NULL,*p=NULL;
        while(!s.empty())
        {
            ptr=s.top();
            s.pop();
            if(ptr==NULL)
            {
                break;
            }
            if(m[ptr]==0)
            {
                mp[ptr]=new Node(ptr->val);
            }
            m[ptr]=1;
            int d=ptr->val;
            vector<Node*>v(ptr->neighbors);
            for(int i=0;i<v.size();i++)
            {
                p=v[i];
                if(m[p]==0)
                {
                    mp[p]=new Node(p->val);
                }
                (mp[ptr]->neighbors).push_back(mp[p]);
                if(m[p]!=0)
                {
                    continue;
                }
                m[p]=1;
                s.push(p);
            }
        }
        return mp[node];
    }
};