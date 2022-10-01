int idx = 0; // idx points to start of the vector and incremented at each function call.

void rev(int n, vector<char>& s){
    if(idx == s.size()/2) return; // Recursion till half of the vector to swap.
    swap(s[idx++], s[n]);
    rev(--n, s);
}

void reverseString(vector<char>& s) {
    if(s.size() == 1) return;
    else rev(s.size()-1, s);  //Passing the last index as parameter to swap.
}