 class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m= str1.size(); // len of str1
 int n=str2.size();  // len of str2
 int t[m+1][n+1];    // tabulation for both strings (DP)
    
//initialising col 1 and row 1 (base case)
    for (int i=0; i<m+1; i++)
        t[i][0]=0;
    for (int j=0; j<n+1; j++)
        t[0][j]=0;
//recursive code converted into bottom-up
     for (int i=1; i<m+1; i++){
          for (int j=1; j<n+1; j++){
              if (str1[i-1]==str2[j-1])
              {t[i][j]=1+t[i-1][j-1];}
              else 
                  t[i][j]=max(t[i][j-1],t[i-1][j]);     
          }
     }
   cout<< t[m][n]<< endl;
    
 // now matrix is done for the count of LCS to print SCS we have to write the code for
 // printing LCS and some changes in it, below is the LCS print code with modiications mentioned
   
    int i = m; int j = n; string s ="";    // initialising
    
    while ( i>0 && j>0){
        if (str1[i-1]== str2[j-1]){
            s.push_back(str1[i-1]);
            i--;
            j--;
          }
        else
        {
            if(t[i-1][j]>t[i][j-1]){
              s.push_back(str1[i-1]);
                i--;
            }
            else {
               s.push_back(str2[j-1]);
                j--;
            }
        }
     }
	 // if either of string becomes empty before the other we still have to print remaing chars of that string
    while (i>0){
        s.push_back(str1[i-1]);
        i--;
    }
    while (j>0){
        s.push_back(str2[j-1]);
        j--;
    }
// reverse LCS/SCS as storing is from t[m][n]

    reverse(s.begin(),s.end());
    return s;
    }
};