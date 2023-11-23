#include "Algorithm.h"


int main() {
	string keyword, message;
	cout << "Enter the keyword: ";
	cin >> keyword;
	cout << "Enter the message: ";
	cin >> message;
	cout <<"Ciphered message: "<< cipherEncoding(keyword, message)<<"\n";
	
	vector<int> sequence = sequenceCreate();
	sequenceContinuation(sequence, 3);
	cout << "Last 3 elements: ";
	for (auto it = sequence.end() -3; it !=sequence.end(); ++it) {
		cout << *it << " ";
	}
}