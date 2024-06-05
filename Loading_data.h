#pragma once
#include<vector>
#include<string>
#include "Split_file.h"



class Loading_data :
	public Split_file
{
private:
	void Get_file_name_func();
	void Get_file_func();
	void Get_ans();
	std::string Get_file_ans;

public:
	Loading_data();
	~Loading_data();
	void Analyzing_data_func(std::vector<std::vector<std::string>>);

};

