#include "ex02-library.h"
#include <iostream>

//Exercise 2 (a) Implement this function
string reverse(string s, int n){
	//put your code here
	if(n < 0){
		return "";
	}
	char c = s[n];
	return c + reverse(s,n-1);
}

//Exercise 2 (b) Implement this function
bool isPalindrome(string s, int n1, int n2){
	//put your code here
	if(n1 >= n2){
		return true;
	}
	if(s[n1] == s[n2]){
		return isPalindrome(s,n1+1,n2-1);
	}
	return false;
}

//Exercise 2 (c) Implement this function
int distancePalindrome(string s, int n1, int n2){
	//put your code here
	if(isPalindrome(s,n1,n2)){
		return 0;
	} 
	if(s[n1] == s[n2]){
		return distancePalindrome(s,n1+1,n2-1);
	}
	if(s[n1] != s[n2]){
		return 1 + distancePalindrome(s,n1+1,n2-1);
	}
	return 0;
}