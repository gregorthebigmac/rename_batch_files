#include <dirent.h>
#include <algorithm>
#include "command/command.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;
command cmd;

int main(int argc, char *argv[]) {
	vector<string> file_list;
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			file_list.push_back(dir->d_name);
			cout << "Adding " << dir->d_name << " to list..." << endl;
		}
		closedir(d);
	}
	std::sort(file_list.begin(), file_list.end());
	cout << "printing file list:" << endl;
	for (int i = 2; i < file_list.size(); i++) { // starting at 2 because 0 and 1 are just "." and ".."
		cout << file_list[i] << endl;
	}
	return 0;
}