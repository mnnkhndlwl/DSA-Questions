class Solution {
public:
    int addDigits(int num) {
    while(num>=10)
        {
            string value = to_string(num);
            int next_num = 0;
            for(int i=0; i<value.size(); i++)
            {
                next_num += (value[i] - '0');
            }
            num = next_num;
        }
        return num;
    }
};