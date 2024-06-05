#pragma once
#include<iostream>
#include<string>
#include<istream>
#include<ostream>
#include<fstream>
#include<sstream>
#include<vector>

class Split_file
{
private:

	void Get_file_name_func();
	void Get_file_func();
	std::vector<std::vector<std::string>> Split_data;

protected:
	std::vector<std::string>split(std::string, char);


public:

	std::string File_split_name;
	Split_file();
	~Split_file();
	std::vector<std::vector<std::string>> Getter_split_vec();

};

