class Solution {
    public:
    bool isvowel(char &ch){
        if(ch=='a'|| ch=='e'||ch=='i'|| ch=='o'||ch=='u')
            return true ;

            return false;
        }
    
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector <int> c(n);
        vector<int>result(m);
         int sum=0;
        for(int i =0; i<n; i++){
            if(isvowel(words[i][0])&& isvowel(words[i].back())){
               
                sum++;

            }
            c[i]=sum;

        }
        for(int i=0; i<m; i++){
            int l=queries[i][0];
            int r=queries[i][1];
            result[i]=c[r] - ((l > 0) ? c[l-1] : 0);// if l=0 then i should be 0

        }
        return result;


    }
};
