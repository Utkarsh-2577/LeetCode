class Solution {
private:
    string buildPalindrome(const string &left, int n, char odd_char, int half){
        string res = left;
        if (n%2 != 0){
            res += odd_char;
        }
        for (int i = half-1; i >= 0; i--){
            res += left[i];
        }
        return res;
    }

public:
    string lexPalindromicPermutation(string s, string target){
        int n = s.size();
        if (target.size() != n){
            return "";
        }

        vector<int> freq(26, 0);
        for (char c : s){
            freq[c-'a']++;
        }

        int odd_cnt = 0;
        char odd_char = 0;
        for (int i = 0; i < 26; i++){
            if (freq[i]%2 != 0){
                odd_cnt++;
                odd_char = i+'a';
            }
            freq[i] /= 2;
        }

        if (odd_cnt > 1){
            return "";
        }

        int half = n/2;
        string best = "";

        vector<int> cur_freq = freq;
        bool can_match_left = true;
        string left_match = "";
        for (int i = 0; i < half; i++){
            int idx = target[i]-'a';
            if (cur_freq[idx] > 0){
                cur_freq[idx]--;
                left_match += target[i];
            }
            else{
                can_match_left = false;
                break;
            }
        }

        if (can_match_left){
            string p = buildPalindrome(left_match, n, odd_char, half);
            if (p > target){
                best = p;
            }
        }

        vector<int> prefix_freq = freq;
        for (int i = 0; i < half; i++){
            int target_char = target[i]-'a';

            for (int c = target_char+1; c < 26; c++){
                if (prefix_freq[c] > 0){
                    string left = target.substr(0, i);
                    left += (char)('a'+c);

                    vector<int> rem_freq = prefix_freq;
                    rem_freq[c]--;

                    for (int j = 0; j < 26; j++){
                        while(rem_freq[j] > 0){
                            left += (char)('a'+j);
                            rem_freq[j]--;
                        }
                    }

                    string p = buildPalindrome(left, n, odd_char, half);
                    if (p > target){
                        if (best.empty() || p < best){
                            best = p;
                        }
                    }
                    break;
                }
            }

            if (prefix_freq[target_char] > 0){
                prefix_freq[target_char]--;
            }
            else{
                break;
            }
        }

        return best;
    }
};