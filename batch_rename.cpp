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
	bool done = false;
	while (!done) {
		cout << "Are these the files you want to perform the batch command upon? [y/n]" << endl;
		string u_answer;
		std::getline(std::cin, u_answer);
		if (u_answer[0] == 'y' || u_answer[0] == 'Y')
			done = true;
		else
			return 0;
	}
	vector<string> terminal_feedback, error_list;
	vector<string> command_queue;
	/*
		TODO: Ask use what command(s) they want to execute on each file
		Give the user the option to include the file by typing "file_name"
		e.g. "what command(s) would you like to execute on each file? use
		"file_name" to indicate you want the name of the file inserted here."
		$ cp
		"add another? [y/n]"
		$ y
		"what command(s) would you like to execute on each file? use "file_name"
		to indicate you want the name of the file inserted here."
		$ file_name
		"add another? [y/n]"
		$ y
		"what command(s) would you like to execute on each file? use "file_name"
		to indicate you want the name of the file inserted here."
		$ 
	*/
	cout << "This is a test. I'm displaying the commands as they would be output to the terminal:" << endl;
	for (int i = 2; i < file_list.size(); i++) {
		// TODO: combine commands and files and push_back command_queue
	}
	return 0;
}