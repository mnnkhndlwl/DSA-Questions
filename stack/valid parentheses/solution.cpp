class Solution {
public:
    bool isValid(string expression) {
        stack<char> s;
    
    for(int i=0;i<expression.length();i++){
        
        //if opening bracket then push
        char ch = expression[i];
        if(ch == '{' || ch == '[' || ch=='('){
            s.push(ch);
        }
        else{
            //if closing bracket then pop and check is stack empty
            if(!s.empty()){
                char top = s.top();
            	if( (ch == '}' && top == '{') || (ch==']' && top=='[') 
                   || (ch==')' && top == '(') ){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
    }
};