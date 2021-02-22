#pragma once
#ifndef DATA_H
#define DATA_H
#include<iostream>
#include <map>
namespace DATA {
	
	using namespace System::Data::SQLite;
	using namespace System;
	using std::string;
	

	class DataB {
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
		DataB(const char* val = "") : value(val) { this->doHash(); };
		DataB(const string& val = "") : value(val) { this->doHash(); };
		DataB(const DataB& copy) : value(copy.value) { this->doHash(); };
		const string& getHashKey()const { return hash; };
		const Value& getValue() const { return value; };
		void setValue(const Value& val) { value = val; };
	};

	std::string& convert_String_to_string(String^ input, std::string& output);
	String^ convert_string_to_String(const std::string& input, String^ output);
	std::string convert_String_to_string(String^ input);
	String^ convert_string_to_String(const std::string& input);

	
}
#endif // !DATA_H


