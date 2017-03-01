#pragma once

#include <fstream>
#include <string>
#include <exception>
#include <vector>

namespace ynym {
namespace util {

class NotOpenedFile : public std::runtime_error {

};

//CSV�t�@�C���̓ǂݍ��݂��s���D�J���}��؂�݂̂ɑΉ�
class CSVReader {
	std::ifstream ifs;
	bool eof_;

public:
	CSVReader(std::string filePath);
	std::string readLine();

	std::vector<std::string> parseLine();
	std::vector<float> parseLineFloat();
	bool eof();
};


}//utility
}//ynym
