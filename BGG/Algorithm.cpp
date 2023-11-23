#include "Algorithm.h"

string cipherEncoding(const string& keyword,const string& message) 
{   
	map <char, string> m;
	string cipheredMessaged;
	vector<string> v_digraph;
	vector<string> v_letter;
	//getting all the digraphs from the message
	for (int i = 0; i <= message.length(); i += 3) {
		string digraph = message.substr(i, 2);
		v_digraph.push_back(digraph);
	}
	//gettin all the following digraphs letters
	for (int i = 2; i <= message.length(); i += 3) {
		string letter = message.substr(i, 1);
		v_letter.push_back(letter);
	}
	int it = 0;
	//label
	phrase:
	for (auto key : keyword) {
		if (it % 2 == 0) {
			if (!v_digraph.empty()) {
				string firstElement = v_digraph.front();
				v_digraph.erase(v_digraph.begin());
				m[key] += firstElement;
			}
		}
		else {
			if (!v_letter.empty()) {
				string firstElement = v_letter.front();
				v_letter.erase(v_letter.begin());
				m[key] += firstElement;
			}
		}
		++it;
	}
	if (!v_digraph.empty() || !v_letter.empty()) {
		goto phrase;
	}

	for (auto el : m) {
		cipheredMessaged += el.second;
	}
	
	return cipheredMessaged;
}

vector<int> sequenceCreate()
{
	vector<int> sequence;
	string line;
	int number;
	//remove extra '\n' symbol to prevent program from crashing
	if (cin) {
		cin.get();
	}
	cout << "Now let's go to the sequence calculation. Enter your sequence: ";
	getline(cin, line);
	std::istringstream iss(line);
	while (iss >> number) {
		sequence.push_back(number);
	}
	return sequence;
}

vector<int> sequenceContinuation(vector<int>& sequence, int n)
{
	//getting d1
	vector<int> v_difference1;
	for (int i = 0; i < sequence.size() - 1; ++i) {
		int dif1 = sequence[i + 1] - sequence[i];
		v_difference1.push_back(dif1);
	}
	//check for "simple" sequence, like "2,3,4,5,6" etc 
	if (v_difference1[0] == v_difference1[1]) {
		for (int i = 0; i < n; ++i) {
			sequence.push_back(sequence.back() + v_difference1[0]);
		}
		return sequence;
	}

	//getting d2
	vector<int> v_difference2;
	for (int i = 0; i < v_difference1.size() - 1; ++i) {
		int dif2 = v_difference1[i + 1] - v_difference1[i];
		v_difference2.push_back(dif2);
	}
	for (int i = 0; i < n; ++i) {
		sequence.push_back(sequence.back() + v_difference1.back() + v_difference2.back());
		v_difference1.push_back(v_difference1.back() + v_difference2.back());
	}
	return sequence;
}


