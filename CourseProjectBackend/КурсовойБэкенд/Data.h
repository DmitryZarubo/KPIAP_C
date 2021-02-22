#pragma once
#ifndef DATA_H
#define DATA_H
#include<iostream>
#include <map>
namespace DATA {
	using std::string;
	class Data {
	public:
		using Value = string;
	private:
		enum { HashLength = 8 };

		string hash;
		Value value;

		int getExistCodes(int in);
		int getControlSum(string str);
		string doHash(size_t hashLen=HashLength);

	public:
		Data(const char* val = "") : value(val) { this->doHash(); };
		Data(const Data& copy) : value(copy.value) { this->doHash(); };
		Data(const string& val = "") : value(val) { this->doHash(); };
		const string& getHashKey()const { return hash; };
		const Value& getValue() const { return value; };
		void setValue(const Value& val) { value = val; };
	};

	
}
#endif // !DATA_H


