class Solution(object):
    def maximumValue(self, strs):
        
        max_value = 0
        
        for s in strs:
            
            if s.isdigit():
                
      # s consists only of digits, so convert it to a number
      # in base 10 and update max_value if necessary
                max_value = max(max_value, int(s))
            else:
                
      # s contains non-digit characters, so store the length
      # of s in max_value instead
                max_value = max(max_value, len(s))
            
        return max_value
        