#include<iostream>
#include <string>

using namespace std;

string matching() {
    
    string str = "I study in Chandigarh";
    string pat = "stud";
    string rep = "live";
  
    cout << "The original string is:  " << str << endl;
    cout << "The pattern string is: " << pat << endl;
    cout << "The replace string is: " << rep << endl;

    int i = 0, j = 0;
    string res = "";

    while (i < str.length()) {
        if (str[i] == pat[j]) {
            j++;
            if (j == pat.length()) {
                res += rep;
                j = 0;
            }
        } 
        else {
            if (j != 0) {
                j = 0;
            }
            res += str[i];
            }
        i++;
    }

    if (j != 0) {
        res += rep;
    }
    
    

    return res;
}

int main() {
    cout << "kunal chopra\n22bai71267\n" << endl;
    string newst = matching();
    cout << "The string after replacing all occurrences of PAT with REP is: " << newst << endl;

}
