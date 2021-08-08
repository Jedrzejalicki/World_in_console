#pragma once
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Commentator
{
public:
	vector<string> text;
	string lookToString(char x);
	void addToText(string x);
	void commentRound();
};

