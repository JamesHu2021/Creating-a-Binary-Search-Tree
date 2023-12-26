#include <algorithm> 
#include <stdio.h> 
#include <string.h> 
#include <string> 


    int anagram(const string s1, const string s2) {
        string TmpS2 = s2;
        for (int i = 0; i < s1.size(); i++) {
            string::iterator it = find(TmpS2.begin(), TmpS2.end(), s1[i]);
            if (it != TmpS2.end())
                TmpS2.erase(it);
            else
                return false;
        }
        return TmpS2.size() == 0;
    }
    
    int main(int argc, char *argv[]) {
        if (argc < 3) {
            cout << "Usage: " << argv[0] << " <string1> <string2>" << endl;
            return 1;
        }
        
        cout << anagram(argv[1], argv[2]) << endl;
        return 0;
    }
