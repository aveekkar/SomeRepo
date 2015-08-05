#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <unordered_map>
#include <BSTIterator.hpp>
#include "boost/numeric/ublas/matrix.hpp"
#include <math.h>

#include "TreeNode.h"

using namespace std;



vector<vector<int> > pathSum(TreeNode* root, int sum);
void pathSumRecurse(TreeNode* root, int sum, vector<vector<int> >& result, vector<int>& running);
int sumUpVector(vector<int>& input);
vector<string> findRepeatedDnaSequences(string s);
size_t hashFunction(const string& str);
int to_int(char const *s);
void printMatrix(const boost::numeric::ublas::matrix<int>& inpMatrix);
int maximumGap(const vector<int>& nums);
bool searchMatrix(vector<vector<int>>& matrix, int target);
template<typename T>
int binarySearchVector(const vector<T>& vec, int start, int end, T key);
template<typename T>
int binarySearchColumn(const vector<vector<T> >& matrix, int startRow, int endRow, int column, T key);

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
    
    boost::numeric::ublas::matrix<int> matrix(10, 10, 234);
    printMatrix(matrix);
	
    //maxGap
    vector<int> maxGapNums;
    maxGapNums.push_back(100);
    maxGapNums.push_back(3);
    maxGapNums.push_back(2);
    maxGapNums.push_back(1);
    /*maxGapNums.push_back(26155);
    maxGapNums.push_back(20757);
    maxGapNums.push_back(3478);
    maxGapNums.push_back(22602);*/
    
    cout<<"found max gap: "<<maximumGap(maxGapNums)<<endl;
    
    //searchMatrix
    //Test binarySearchVector
    vector<int> searchVector;
    vector<int> searchVector1;
    searchVector.push_back(5);
    searchVector1.push_back(6);
    int key = 6;
    cout<<"looking for key: "<<key<<" found at: "<<binarySearchVector<int>(searchVector, 0, searchVector.size() - 1, key)<<endl;
    vector<vector<int> > matrixToSearch;
    matrixToSearch.push_back(searchVector);
    matrixToSearch.push_back(searchVector1);
    cout<<"does key "<<key<<" exist in matrix?"<<endl;
    cout<<"Ans: "<<searchMatrix(matrixToSearch, key)<<endl;
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


void printMatrix(const boost::numeric::ublas::matrix<int>& inpMatrix)
{
    for(int i = 0; i < inpMatrix.size1(); ++i)
    {
        cout<<"=========";
    }
    cout<<"-"<<endl;
    for(int i = 0; i < inpMatrix.size1(); ++i)
    {
        cout<<"|";
        for(int j = 0; j < inpMatrix.size2(); ++j)
        {
            int val = inpMatrix(i, j);
            string valStr = std::to_string(val);
            int length = valStr.length();
            
            int k = 0;
            for(; k < (8 - length)/2; ++k)
            {
                cout<<" ";
            }
            cout<<valStr;
            for(int x = 0; x < (8 - length - k); ++x)
            {
                cout<<" ";
            }
            cout<<"|";
        }
        cout<<""<<endl;
        for(int i = 0; i < inpMatrix.size1(); ++i)
        {
            cout<<"=========";
        }
        cout<<""<<endl;
    }
}

int maximumGap(const vector<int>& nums)
{
    if(nums.size() < 2)
    {
        return 0;
    }
    
    if(nums.size() == 2)
    {
        return abs(nums[0] - nums[1]);
    }
    
    int maxElement = *max_element(nums.begin(), nums.end());
    int minElement = *min_element(nums.begin(), nums.end());
    
    double bucketRange = ((double)maxElement - minElement)/(nums.size() - 1);
    
    vector<vector<int> > buckets(nums.size() - 1, vector<int>());
    
    for(vector<int>::const_iterator i = nums.begin(); i != nums.end(); ++i)
    {
        if(*i == maxElement || *i == minElement)
        {
            continue;
        }
        int bucketIndex = (int)floor(((*i) - minElement)/bucketRange);
        buckets[bucketIndex].push_back((*i));
    }
    
    for(vector<vector<int> >::iterator i = buckets.begin(); i != buckets.end(); )
    {
        if(i->size() == 0)
        {
            buckets.erase(i);
            continue;
        }
        
        ++i;
    }
    
    if(buckets.size() == 0)
    {
        return maxElement - minElement;
    }
    int diffMin = *min_element(buckets[0].begin(), buckets[0].end()) - minElement;
    int diffMax = maxElement - *max_element(buckets.rbegin()->begin(), buckets.rbegin()->end());
    int maxGap = max(diffMax, diffMin);
        
    for(vector<vector<int> >::iterator i = buckets.begin(); i != buckets.end() - 1; ++i)
    {
       int diff = *max_element(i->begin(), i->end()) - *min_element((i + 1)->begin(), (i + 1)->end());
       maxGap = diff > maxGap ? diff : maxGap; 
    }
    
    
    
    return maxGap;
}


bool searchMatrix(vector<vector<int> >& matrix, int target)
{
    if(matrix.size() == 0)
    {
        return false;
    }
    int i = 0;
    int j = matrix[0].size() - 1;
    
    while(j >= 0 && i < matrix.size())
    {
        if(matrix[i][j] == target)
        {
            return true;
        }
        else if(matrix[i][j] > target)
        {
            if(binarySearchVector<int>(matrix[i], 0, j - 1, target) != -1)
            {
                return true;
            }
            ++i;
            --j;
            continue;
        }
        else
        {
            if(binarySearchColumn<int>(matrix, i + 1, matrix.size() - 1, j, target) != -1)
            {
                return true;
            }
            ++i;
            --j;
            continue;
        }
    }
    
    return false;
    
}



template<typename T>
int binarySearchVector(const vector<T>& vec, int start, int end, T key)
{
    if(start > end)
    {
       return -1; 
    }
    int mid = (start + end) / 2;
    if(vec[mid] == key)
    {
        return mid;
    }
    else if(vec[mid] > key)
    {
        return binarySearchVector(vec, start, mid - 1, key);
    }
    else
    {
        return binarySearchVector(vec, mid + 1, end, key);
    }
    
}

template<typename T>
int binarySearchColumn(const vector<vector<T> >& matrix, int startRow, int endRow, int column, T key)
{
    int mid = (startRow + endRow) / 2;
    if(startRow > endRow)
    {
        return -1;
    }
    
    if(matrix[mid][column] == key)
    {
        return mid;
    }
    else if(matrix[mid][column] > key)
    {
        return binarySearchColumn(matrix, startRow, mid - 1, column, key);
    }
    else
    {
        return binarySearchColumn(matrix, mid + 1, endRow, column, key);
    }
}