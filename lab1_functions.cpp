#include "lab1_functions.hpp"

namespace nf {
	void ReadingFile(std::ifstream& in, int& launch_num) {
		std::string trash;
		while (!in.eof()) {
			in >> launch_num;
			std::getline(in, trash);
		}
		in.close();
	}

	void OutputToFile(std::ofstream& out, int launch_num, struct tm* my_date) {
		out << launch_num + 1 << "-" << my_date->tm_year + 1900 << "-" << my_date->tm_mon + 1 << "-" << my_date->tm_mday << "-" << my_date->tm_hour << "-" << my_date->tm_min << "-" << my_date->tm_sec << std::endl;
		out.close();
	}
}