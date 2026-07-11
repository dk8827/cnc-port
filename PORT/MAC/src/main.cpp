#include <limits.h>
#include <mach-o/dyld.h>
#include <string>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <windows.h>

int PASCAL WinMain(HINSTANCE instance, HINSTANCE previous, char *command_line, int command_show);

static bool path_exists(char const *path)
{
	struct stat info;
	return path && stat(path, &info) == 0;
}

static std::string parent_path(std::string path)
{
	while (path.size() > 1 && path[path.size() - 1] == '/') {
		path.erase(path.size() - 1);
	}
	std::string::size_type slash = path.find_last_of('/');
	if (slash == std::string::npos) {
		return ".";
	}
	if (slash == 0) {
		return "/";
	}
	return path.substr(0, slash);
}

static void use_resource_root(char const *root)
{
	static char const *config_path = "assets/cnc/gdi/INSTALL/CONQUER.INI";
	if (!root || chdir(root) != 0) {
		return;
	}
	if (!path_exists(config_path)) {
		return;
	}
}

static void select_resource_root(void)
{
	static char const *config_path = "assets/cnc/gdi/INSTALL/CONQUER.INI";
	if (path_exists(config_path)) {
		return;
	}

	char executable_path[PATH_MAX];
	uint32_t executable_path_size = sizeof(executable_path);
	if (_NSGetExecutablePath(executable_path, &executable_path_size) != 0) {
		return;
	}

	std::string executable_dir = parent_path(executable_path);
	std::string build_parent = parent_path(executable_dir);

	use_resource_root(executable_dir.c_str());
	if (path_exists(config_path)) {
		return;
	}
	use_resource_root(build_parent.c_str());
}

int main(int argc, char **argv)
{
	select_resource_root();

	std::string command_line;
	for (int index = 1; index < argc; ++index) {
		if (!command_line.empty()) {
			command_line += ' ';
		}
		command_line += argv[index];
	}
	return WinMain((HINSTANCE)0, (HINSTANCE)0, command_line.empty() ? (char *)"" : (char *)command_line.c_str(), SW_RESTORE);
}
