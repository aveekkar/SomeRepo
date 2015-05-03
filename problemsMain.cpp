#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <unordered_map>
#include <BSTIterator.hpp>

#include "TreeNode.h"

using namespace std;



vector<vector<int> > pathSum(TreeNode* root, int sum);
void pathSumRecurse(TreeNode* root, int sum, vector<vector<int> >& result, vector<int>& running);
int sumUpVector(vector<int>& input);
vector<string> findRepeatedDnaSequences(string s);
size_t hashFunction(const string& str);
int to_int(char const *s);

int main(int argc, char **argv)
{
	int sum = 22;
	TreeNode root(5);
	TreeNode left(4);
	TreeNode right(8);
	root.left = &left;
	root.right = &right;
	TreeNode leftLeft(11);
	TreeNode rightLeft(13);
	TreeNode rightRight(4);
	left.left = &leftLeft;
	right.left = &rightLeft;
	right.right = &rightRight;
	TreeNode leafOne(7);
	TreeNode leafTwo(2);
	TreeNode leafThree(5);
	TreeNode leafFour(1);
	leftLeft.left = &leafOne;
	leftLeft.right = &leafTwo;
	rightRight.left = &leafThree;
	rightRight.right = &leafFour;
	pathSum(&root, sum);
	
	string dnaSequence = "AAAAAAAAAAA";
	findRepeatedDnaSequences(dnaSequence);
	
	//Iterator for BT
	BSTIterator iter(&root);
	while(iter.hasNext())
	{
		std::cout<<iter.next()<<endl;
	}
	getchar();
	return 0;
}

vector<vector<int> > pathSum(TreeNode* root, int sum)
{
	vector<vector<int> > result;
	vector<int> runningResult;
	pathSumRecurse(root, sum, result, runningResult);
	return result;
}

void pathSumRecurse(TreeNode* root, int sum, vector<vector<int> >& result, vector<int>& running)
{
	if(root == NULL)
	{
		return;
	}
	if(root->left == NULL && root->right == NULL)
	{
		int runningSum = sumUpVector(running) + root->val;
		if(runningSum == sum)
		{
			vector<int> foundPath;
			for(int i = 0; i < running.size(); ++i)
			{
				foundPath.push_back(running[i]);
			}
			foundPath.push_back(root->val);
			result.push_back(foundPath);
		}
	}
	else
	{
		running.push_back(root->val);
		if(root->left != NULL)
		{
			 pathSumRecurse(root->left, sum, result, running);
		}
		if(root->right != NULL)
		{
			pathSumRecurse(root->right, sum, result, running);
		}
		running.pop_back();
	}
}

int sumUpVector(vector<int>& input)
{
	int sum = 0;
	for(vector<int>::const_iterator i = input.begin(); i != input.end(); ++i)
	{
		sum += (*i);
	}
	return sum;
}


vector<string> findRepeatedDnaSequences(string s)
{	
	vector<string> returnList;
	if(s.length() < 10)
	{
		return returnList;
	}
	map<std::size_t, int> cache;
	for(int i = 0; i <= s.length() - 10; ++i)
	{
		string subSequence = s.substr(i, 10);
		size_t hashed = hashFunction(subSequence);
		if(cache.find(hashed) == cache.end())
		{
			cache[hashed] = 1;
		}
		else
		{
			if(cache[hashed] == 1)
			{
				returnList.push_back(subSequence);
			}
			cache[hashed] += 1;
		}
	}
	
	return returnList;
}

size_t hashFunction(const string& str)
{
	map<char, string> charMap;
	charMap['A'] = "0";
	charMap['C'] = "1";
	charMap['T'] = "2";
	charMap['G'] = "3";
	
	stringstream s;
	
	for(int i = 0; i < str.length(); ++i)
	{
		s<<charMap[str[i]];
	}
	
	return to_int(s.str().c_str());
}


int to_int(char const *s)
{
     if ( s == NULL || *s == '\0' )
        return - 1;

     bool negate = (s[0] == '-');
     if ( *s == '+' || *s == '-' ) 
         ++s;

     if ( *s == '\0')
        return -1;

     int result = 0;
     while(*s)
     {
          if ( *s >= '0' && *s <= '9' )
          {
              result = result * 10  - (*s - '0');  //assume negative number
          }
          else
              return -1;
          ++s;
     }
     return negate ? result : -result; //-result is positive!
} 