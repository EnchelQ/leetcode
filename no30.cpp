/*
Problem Description:Substring with Concatenation of All Words
	You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
Solution:
	orgnize words as a dictionary(map data type),contained a unique word,and how many it occured in words.
	check is a copy of dictionary, when we find a word exit both in words and s, the value of dictionary decrease. When the value of all elements in dictionary are 0,we add the begining position in s to the result.
Question raise: 
	1.the efficiency of find function in generic algorithm and inside th container.
	2.the difference between vector and array in compile process
	3.vector+vector=map
*/
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> result;
	map<string, int> dictionary;
	int len = (*words.begin()).size();
	int lenOfWords = words.size()*len;
	for (string &word : words)
	{
		dictionary[word]++;
	}

	int i = 0;
	int bound_i = s.size() - words.size()*len+1;
	while (i <bound_i)
	{
		string subStr = s.substr(i, len);
		//initial for j and dictionary before enter the second circle.
		map<string, int> check(dictionary);		//check(element in words,the remainder of the element in dictionary).
		int j = 0;
		auto pos = check.find(subStr);
		if (pos != check.end())
		{
			pos->second--;
			j = i + len;
			//consider the situation that words one have one word.
			if ((j - i) == lenOfWords)
			{
				result.push_back(i);
				i++;
				continue;
			}
		}		
		//Question raise 4:the differece between above with
		/*
		if(check.find(subStr)!=check.end())
		{
			check[subStr]--;
			j=i+len;
		}
		*/
		else
		{
			i++;
			continue;
		}
		int bound_j = s.size() - len +1;
		while (j < bound_j)
		{
			string subStr = s.substr(j,len);
			auto pos = check.find(subStr);
			if (pos!=check.end() && pos->second>0)
			{
				(pos->second)--;
				j = j + len;
				if ((j - i) == lenOfWords)
				{
					result.push_back(i);
					break;
				}
			}
			else
				break;
		}
		i++;
	}
	return result;
}
int main()
{
	string s = "mississippi";
	vector<string> words = {"is"};
	vector<int> result;
	result = findSubstring(s, words);
	for (auto i : result)
		cout << i << " ";
}