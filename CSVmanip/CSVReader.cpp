#include "CSVReader.h"

namespace ynym {
namespace util {

CSVReader::CSVReader(std::string filePath) {
	eof_ = false;

	ifs.exceptions(ifs.failbit | ifs.badbit);
	ifs.open(filePath);
}

std::string CSVReader::readLine() {
	std::string line;
	std::getline(ifs, line);

	if (ifs.eof()) {
		return line;
	}
	return line;

}
std::vector<std::string> CSVReader::parseLine() {
	std::vector<std::string> res;
	std::string line = readLine();
	std::string word;

	if (ifs.eof()) {
		eof_ = true;
	}

	char delm = ',';
	bool doubleQuote = false;
	int startPos = 0;
	int endPos = 0;

	if (line[0] == '"') {
		doubleQuote = true;
	}

	startPos += doubleQuote;
	while ((endPos = line.find(delm, startPos)) != std::string::npos) {
		res.push_back(line.substr(startPos, endPos - doubleQuote - startPos));
		startPos = endPos + 1 + doubleQuote;
	}
	if (endPos != 0) {		//最後の単語を取り出す（あまりスマートな方法ではない）
		res.push_back(line.substr(startPos, line.size() - startPos - doubleQuote));
	}

	return res;
}

std::vector<float> CSVReader::parseLineFloat() {
	std::vector<std::string> words = parseLine();

	std::vector<float> ret(words.size());
	for (int i = 0; i < words.size(); i++) {
		ret[i] = std::stof(words[i]);
	}

	return ret;

}

bool CSVReader::eof() {
	return eof_;
}


}
}