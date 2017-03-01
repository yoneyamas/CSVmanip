#pragma once

#include <fstream>
#include <string>
#include <exception>
#include <vector>

namespace ynym {
namespace util {

class CantOpenFile : public std::runtime_error {

};

//CSV�t�@�C���̓ǂݍ��݂��s���D�J���}��؂�݂̂ɑΉ�
class CSVWriter {
	std::ofstream ofs;
	bool eof_;
public:
	CSVWriter(std::string filePath);
	void writeLine(std::vector<std::string> record);

	bool eof();
};

}
}