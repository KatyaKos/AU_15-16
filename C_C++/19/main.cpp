#include <iostream>
#include <boost/filesystem.hpp>
using std::cout;
using namespace boost::filesystem;

#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define WHITE   "\033[37m"

void spaces(int n) {
	for (int i = 0; i < n; i++) cout << ' ';
}

void print_path(path p, int depth){

	if (is_regular_file(p)){
		spaces(depth * 4);
		if (status(p).permissions() & owner_exe) cout << p.filename().string() << '\n';
		else cout << GREEN << p.filename().string() << WHITE << '\n';
	}else if (is_directory(p)){
		spaces(depth * 4);
		cout << BLUE << p.filename().string() << WHITE << '\n';
		for (directory_iterator x = directory_iterator(p); x != directory_iterator(); x++) print_path(*x, depth + 1); 
	}
}
	
int main(int argc, char* argv[])
{
	if (argc < 2){
		cout << "Usage: tut3 path\n";
		return 1;
	}

	path p (argv[1]);
	if (exists(p)) print_path(p, 0);
	else cout << p.filename().string() << " does not exist\n";

	return 0;
}