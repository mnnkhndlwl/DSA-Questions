class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        vector <TreeNode*> st;                       //Stack Declaration
        for(int i=0; i<s.size(); ){
            int level=0, val=0;                      //Variables for level and number
            while(s[i] == '-')
                level++, i++;                        //Calculating Level
            while(i < s.size() && s[i] != '-'){      //Storing number in val
                val*=10;
                val+=s[i]-'0';                       //Converting char to int
                i++;
            }
            TreeNode* node = new TreeNode(val);                   //Creating new node
            while(st.size()>level) st.pop_back();                 //Finding right level to Insert
            if(!st.empty()){
                if(!st.back()->left) st.back()->left=node;        //Checking left child first
                else st.back()->right=node;                       //Creating right child if left child already present
            }
            st.push_back(node);                                   //Pushing new node to stack
        }
        return st[0];                                             //Returning head
    }
};