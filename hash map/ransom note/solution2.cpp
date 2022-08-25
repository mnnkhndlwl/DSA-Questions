class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //Declaring an array of size 26 with all elements equal to 0
	int count[26] = {0};
	//Traversing magazine and storing count of each character in count array
    for(int i=0;i<magazine.size();i++)
			//magazine[i] will be a character for eg. 'b'
			//ASCII value of 'b' is 98 and 'a' is 97, Hence 98 - 97 = 1
			//Therefore count[1] will get incremented
            count[magazine[i] - 'a']++;
    
    for(int i=0;i<ransomNote.size();i++)
		//Checks if count of ransomNote[i] is positive or not
		//if yes then decrease count else return false
		if(count[ransomNote[i] - 'a']-- <= 0)
			return false;
        
    return true;
    }
};