class Solution {
public:
    int compress(vector<char>& chars) {

        int index=0 ;
        char cur=chars[0];
        int c=1;
        for(int i =1; i<chars.size(); i++){
                if(chars[i]==cur){
                   
                    c++;
                }
                else{
                   chars[index]= cur;

                   index++;
                   if(c>1){
                        string countstring= to_string(c);
                        for(char &c : countstring ){
                            chars[index] = c;
                            index++;
                        }
                   }
                  cur=chars[i];
                  c=1;
                }
        }
        chars[index]= cur;

            index++;
                   if(c>1){
                        string countstring= to_string(c);
                        for(char &c : countstring ){
                            chars[index++] = c;
                           // index++;
                        }
                   }

        return index;
    }
};
