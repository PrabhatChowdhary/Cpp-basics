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
    
        int size=s.size(),count=0,max=0;

    for(int k=0;k<size;k++){
        vector<bool> visited(256,false);
        count=0;
        for (int i=k;i<size;i++){
            if(visited[s[i] ]) 
                break;
            count++;
            visited[s[i] ]=true;
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
