#include <dirent.h>
#include "command/command.hpp"

using std::cout;
using std::endl;

command cmd;

int main(int argc, char *argv[]) {
	DIR *d;
	struct dirent *dir;
	d = opendir(".");
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			cout << dir->d_name << endl;
		}
		closedir(d);
	}
	return 0;
}