#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "lab1_functions.hpp"

int main(){
	
	time_t mytime = time(NULL);
	struct tm *mydate = localtime(&mytime);
	
	std::ifstream in("LaunchTime.txt");
	int LaunchNum = 0;
	std::string trash;
	while(!in.eof()){
		in >> LaunchNum;
		std::getline(in, trash);
	}
	in.close();
	
	std::ofstream out("LaunchTime.txt", std::ios::app);
	out << LaunchNum + 1 << "-" << mydate->tm_year + 1900 << "-" << mydate->tm_mon + 1 << "-" << mydate->tm_mday << "-" << mydate->tm_hour << "-" << mydate->tm_min << "-" << mydate->tm_sec << std::endl;
	out.close();
	
	return 0;
}
