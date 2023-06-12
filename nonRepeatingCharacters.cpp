// Online C++ compiler to run C++ program online
//https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/
//find length of longest substring with no letters repeating
//abcababc- ans 3(abc)
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s){
    
    unordered_map<char,int> letterFound;// using type char, int instead of string,int because string[i] will give data type character
    int size=s.size(),count=0,max=0;

    for(int k=0;k<size;k++){
        letterFound.clear();
        count=0;
        for (int i=k;i<size;i++){
            if(letterFound[s[i] ]>0) 
                break;
            count++;
            letterFound[s[i] ]++;
        }   
        if(max<count)
            max=count;
    }
    
    return max;
}

int main() {
    // Write C++ code here
    std::cout << "Hello world!"<<endl;
    string inputString={"xabcayd"};
    
    int answer;
    answer=lengthOfLongestSubstring(inputString);
    cout<<answer;
    return 0;
}
