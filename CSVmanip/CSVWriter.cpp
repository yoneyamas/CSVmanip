#include "CSVWriter.h"
#include <string>
#include <fstream>

namespace ynym {
namespace util {

CSVWriter::CSVWriter(std::string filePath) {
	eof_ = false;

	ofs.exceptions(ofs.failbit | ofs.badbit);
	ofs.open(filePath);
}
void CSVWriter::writeLine(std::vector<std::string> record) {
	char del = ',';

	for (int i = 0; i < record.size(); i++) {
		ofs << '\"' << record[i] << '\"';
		if (i != record.size() - 1) {
			ofs << del;
		}
	}
	ofs << '\n';

	return;

}


}
}