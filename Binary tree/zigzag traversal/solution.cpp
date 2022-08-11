//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* node)
   {
    // Code here
     queue<Node*> q;
     if(node == NULL){
       vector<int> vc;
       return vc;
   }
     vector<vector<int>> vc;
     q.push(node);
     bool left_right=true;
     while(!q.empty()){
         int size=q.size();
         vector<int> vc1(size);
         for(int i=0;i<size;i++){
         Node* temp=q.front(); 
         int j=left_right ? i:(size-i-1);
         vc1[j]=temp->data;
         q.pop();
         if(temp->left){
             q.push(temp->left);
         }
         if(temp->right){
             q.push(temp->right);
         }
       }
       left_right=!left_right;
         vc.push_back(vc1);
     }
     vector<int> ans;
     for(int i=0;i<vc.size();i++){
         for(int j=0;j<vc[i].size();j++){
             ans.push_back(vc[i][j]);
         }
     }
     return ans;
   }