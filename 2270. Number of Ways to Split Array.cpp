class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>sum(nums.size());
        int count=0;
        long long a=0;// prefix sum array 
        for(int i =0 ; i<nums.size(); i++){
            a=nums[i]+a;
            sum[i]=a;
        }
        //add them and sub 
        for(int l=0; l<nums.size()-1;l++){
           long long left= sum[l];
           long long right=sum[nums.size()-1]-sum[l];
           
           if(left>=right){
            count++;
           }
        }
        return count;
        
    }
};
/*       int count=0;
        for (int i =0 ; i<nums.size()-1; i++){
            int a=0;
            for(int j=0 ; j<i+1; j++){
                    a=nums[j]+a;
                 //   cout<<a<<endl;
                    
            }
            int b=0;
              for(int j =i+1 ; j<nums.size(); j++){
                    b=nums[j]+b;
                 //   cout<<b;
            }
            if(a>=b){
                count++;
            }
        }
        return count;
*/
