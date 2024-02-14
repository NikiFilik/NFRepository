#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "lab1_functions.hpp"

int main(){
	
	time_t my_time = time(NULL);
	struct tm *my_date = localtime(&my_time);
	
	std::ifstream in("LaunchTime.txt");
	int launch_num = 0;

	nf::ReadingFile(in, launch_num);
	
	std::ofstream out("LaunchTime.txt", std::ios::app);
	nf::OutputToFile(out, launch_num, my_date);
	
	return 0;
}
