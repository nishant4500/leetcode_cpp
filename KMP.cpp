class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> matchingWords;

        for (int i = 0; i < words.size(); i++) {
            vector<int> lps = computeLPSArray(words[i]);
            // Compare the current word with all other words.
            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;  // Skip comparing the word with itself.

                // Check if the current word is a substring of another word.
                if (isSubstringOf(words[i], words[j], lps)) {
                    matchingWords.push_back(words[i]);
                    break;  // No need to check further for this word.
                }
            }
        }

        return matchingWords;
    }

private:
    // Function to compute the LPS (Longest Prefix Suffix) array for the
    // substring `sub`.
    vector<int> computeLPSArray(string &sub) {
        vector<int> lps(sub.size(), 0);  // Initialize the LPS array with 0.
        int currentIndex = 1;            // Start from the second character.
        int len =
            0;  // Length of the current longest prefix which is also a suffix.

        while (currentIndex < sub.size()) {
            if (sub[currentIndex] == sub[len]) {
                len++;  // If the current characters match, extend the prefix.
                lps[currentIndex] = len;  // Store the length of the prefix.
                currentIndex++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];  // Backtrack using LPS array to find a
                                         // shorter match.
                } else {
                    currentIndex++;
                }
            }
        }
        return lps;
    }

    // Function to check if `sub` is a substring of `main` using the KMP
    // algorithm.
    bool isSubstringOf(string &sub, string &main, vector<int> &lps) {
        int i = 0;  // Pointer for `main`.
        int j = 0;  // Pointer for `sub`.

        while (i < main.size()) {
            if (main[i] == sub[j]) {
                i++;
                j++;
                if (j == sub.size()) return true;  // Found a match.
            } else {
                if (j > 0) {
                    // Use the LPS to skip unnecessary comparisons.
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;  // No match found.
    }
};

// class Solution {
// public:
//     vector<string> stringMatching(vector<string>& words) {
//         vector<string>result;
//         int n = words.size();
//         for (int i =0 ; i<n; i++){
//             for(int j=0; j<n;j++){
//                 if(i==j) continue;

//                 //npos
//                 if(words[j].find(words[i])!= string:: npos){
//                     result.push_back(words[i]);
//                     break;
//                 }
//             }
//         }
//         return result;

        
//     }
// };
