class Solution {
public:
    int maxScore(string s) {
        int maxScore = 0;

        // Iterate through all valid split points
        for (int i = 1; i < s.size(); i++) {
            int leftZeros = 0, rightOnes = 0;

            // Count '0's in the left substring
            for (int j = 0; j < i; j++) {
                if (s[j] == '0') {
                    leftZeros++;
                }
            }

            // Count '1's in the right substring
            for (int j = i; j < s.size(); j++) {
                if (s[j] == '1') {
                    rightOnes++;
                }
            }

            // Calculate score and update maxScore
            maxScore = std::max(maxScore, leftZeros + rightOnes);
        }

        return maxScore;
    }
};
/*
class Solution {
public:
    int maxScore(string s) {
        int max=0;
        int l=0;
        int r=0;
       
        for(int i =0 ; i<s.size(); i++ )
        {
            if(s[i]=='0'){
                l++;
            
         }
          
             
            for(int j =i+1; j<s.size(); j++){
           
                if(s[j]=='1'){
                    r++;   
                }
            }
            
         
            if(max<l+r){
            max=l+r;
            }
            r=0;
        }
            for(int i =0 ; i<s.size(); i++){
                if(s[i]=='1'){
                    return max;
                }
            }
        return max-1;
        
    }
};*/
