#include "Loading_data.h"

Loading_data::Loading_data() {
	this->Get_file_name_func();
	this->Get_file_func();
	this->Get_file_ans = "";
	this->Get_ans();
	this->Analyzing_data_func(this->Getter_split_vec());
};

Loading_data::~Loading_data()
{
	std::cout << "データの読み込みが完了しました" << std::endl;
};

void Loading_data::Get_file_name_func() {

	//ファイル名
	std::cout << "ファイル名を入力" << std::endl;
	std::cin >> this->File_split_name;

	//txt があるかどうか
	if (this->File_split_name.find(".txt") == std::string::npos) {
		this->File_split_name += ".txt";
	}

	return;
}

void Loading_data::Get_file_func() {

	std::ifstream Get_file(this->File_split_name, std::ios::in);

	if (!Get_file) {

		std::cerr << "ファイルが開けません" << std::endl;
		exit(-35);

	}

	return;

}

void Loading_data::Get_ans() {

	std::cout << "答えのファイル名を入力" << std::endl;
	std::cin >> this->Get_file_ans;

	//csv があるかどうか
	if (this->Get_file_ans.find(".csv") == std::string::npos) {
		this->Get_file_ans += ".csv";
	}

	return;
}

void Loading_data::Analyzing_data_func(std::vector<std::vector<std::string>>File_of_split) {

	std::ifstream Target_file(this->File_split_name, std::ios::in);
	std::ofstream Write_file(this->Get_file_ans, std::ios::out);

	long long int data_length = std::stol(File_of_split.back()[2]) + std::stol(File_of_split.back()[3]);

	//ヘッダーの設定
	auto header_make = [&]()->void {

		for (long int loop_i = 0; loop_i < File_of_split.size(); loop_i++) {

			Write_file << File_of_split[loop_i][1];

			if (loop_i == ((File_of_split.size()) - 1)) {
				Write_file << std::endl;
			}
			else {
				Write_file << ",";
			}

		}
		return;
		};


	auto data_make = [&]()->void {


		std::string temp_line;

		while (getline(Target_file, temp_line))
		{

			if (temp_line.size() < data_length) {
				std::string temp_length = std::string(data_length - temp_line.size(), ' ');

				temp_line += temp_length;
			}
			else if (temp_line.size() > data_length) {
				std::cerr << "ファイルの文字数が長すぎます" << std::endl;
				exit(97);
			}


			std::vector<std::vector<std::string>>::iterator itr = File_of_split.begin();

			while (itr != File_of_split.end()) {

				std::vector<std::string>::iterator itr_2 = itr->begin();

				long int temp_start = std::stol(*(itr_2 + 2)) - 1;
				long int temp_end = std::stol(*(itr_2 + 3));

				Write_file << temp_line.substr(temp_start, temp_end);

				itr++;

				if (itr == File_of_split.end()) {
					Write_file << std::endl;
				}
				else {
					Write_file << ",";
				}
			}
		}
		return;
		};

	header_make();
	data_make();

	return;
}