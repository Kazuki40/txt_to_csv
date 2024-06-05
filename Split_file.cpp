#include "Split_file.h"

Split_file::Split_file()
{
	this->File_split_name = "";
	this->Get_file_name_func();
	this->Get_file_func();

};

Split_file::~Split_file()
{
	std::cout << "データの読み込みが完了しました" << std::endl;
};

std::vector<std::string>Split_file::split(std::string str, char del) {
	long long int first = 0;
	long long int last = str.find_first_of(del);

	std::vector<std::string> result;

	while (first < str.size()) {
		std::string subStr(str, first, last - first);

		result.push_back(subStr);

		first = last + 1;
		last = str.find_first_of(del, first);

		if (last == std::string::npos) {
			last = str.size();
		}
	}

	return result;
}


void Split_file::Get_file_name_func() {

	std::cout << "分割用のファイル名\n ID ヘッダー名前　開始　長さ" << std::endl;
	std::cin >> this->File_split_name;

	//csv があるかどうか
	if (this->File_split_name.find(".csv") == std::string::npos) {

		this->File_split_name += ".csv";
	}
	return;
}

void Split_file::Get_file_func() {

	std::ifstream Get_file(this->File_split_name, std::ios::in);

	if (!Get_file) {

		std::cerr << "ファイルが開けません:" << this->File_split_name << std::endl;
		exit(-35);

	}


	auto Get_data_func = [&]()->void {

		std::vector<std::string> Temp_vec;
		std::string Temp_line;
		long int temp_loop = 0;

		while (getline(Get_file, Temp_line)) {


			if (Temp_line.find("\"") != std::string::npos) {

				Temp_line.erase(std::remove(Temp_line.begin(), Temp_line.end(), '\"'), Temp_line.end());

			}


			Temp_vec = this->split(Temp_line, ',');

			if (temp_loop != 0) {

				this->Split_data.push_back(Temp_vec);

			}

			temp_loop++;

		}
		return;
		};

	Get_data_func();

	return;
}

std::vector<std::vector<std::string>> Split_file::Getter_split_vec() {

	return this->Split_data;

}