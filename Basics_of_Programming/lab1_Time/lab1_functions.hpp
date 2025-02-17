#pragma once
#include <fstream>
#include <string>

namespace nf {
	void ReadingFile(std::ifstream& in, int& launch_num);

	void OutputToFile(std::ofstream& out, int launch_num, struct tm* my_date);
}