#include "ex03-library.h"
#include <iostream>

//Do not modify
WordsList::WordsList(){
	allWords.push_back("121");
	wordsToPalindromeDistance["121"]=0;
	allWords.push_back("122");
	wordsToPalindromeDistance["122"]=1;
}

//Exercise 3 (a) implement this method
void WordsList::print(){
	//put your code here
	int n = 0;
	for(auto it : allWords){
		n++;
	}
	cout << n << " words: ";
	for(auto it : allWords){
		cout << it << " " << wordsToPalindromeDistance[it] << " ";
	}
}

//Exercise 3 (b) implement this method
int WordsList::distancePalindrome(string s){
	//put your code here
	int distance = 0;
	int lenght = s.size();
	if(lenght%2 == 0){
		// if the value si even
		for(int i = 0; i < lenght/2; i++){
			if(s[i] != s[lenght-i-1]){
				distance++;
			}
		}
	} else {
		// if the value is odd
		for(int i = 0; i < (lenght-1)/2; i++){
			if(s[i] != s[lenght-i-1]){
				distance++;
			}
		}
	}
	return distance;
}

//Exercise 3 (c) implement this method
void WordsList::addWord(string word){
	//put your code here
	allWords.push_back(word);
	int d = distancePalindrome(word);
	wordsToPalindromeDistance[word] = d;
}

//Exercise 3 (d) implement this method
int WordsList::palindromeWords(){
	//put your code here
	int n = 0;
	for(auto it : allWords){
		if(distancePalindrome(it) == 0){
			n++;
		}
	}
	return n;
}