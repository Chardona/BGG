#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::map;
using std::vector;


string cipherEncoding(const string& key , const string& message);
vector<int> sequenceCreate();
vector<int> sequenceContinuation(vector<int>& sequence, int n);



#endif