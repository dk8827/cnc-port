#include <SDL.h>
#include <SDL_system.h>

#include <limits.h>
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

static void select_resource_root(void)
{
    static char const *config_path = "assets/cnc/gdi/INSTALL/CONQUER.INI";
    SDL_Log("C&C Android: selecting resource root");
    if (path_exists(config_path)) {
        SDL_Log("C&C Android: using current working directory");
        return;
    }

    char const *internal_path = SDL_AndroidGetInternalStoragePath();
    if (!internal_path || !internal_path[0]) {
        return;
    }

    std::string resource_root = std::string(internal_path) + "/cnc-root";
    if (chdir(resource_root.c_str()) != 0) {
        SDL_Log("C&C Android: unable to enter %s", resource_root.c_str());
        return;
    }
    if (!path_exists(config_path)) {
        SDL_Log("C&C Android: config missing under %s", resource_root.c_str());
        chdir(internal_path);
    } else {
        SDL_Log("C&C Android: using %s", resource_root.c_str());
    }
}

extern "C" int SDL_main(int argc, char **argv)
{
    SDL_Log("C&C Android: SDL_main entered");
    select_resource_root();

    std::string command_line;
    for (int index = 1; index < argc; ++index) {
        if (!command_line.empty()) {
            command_line += ' ';
        }
        command_line += argv[index];
    }

    SDL_Log("C&C Android: entering WinMain");
    int result = WinMain((HINSTANCE)0, (HINSTANCE)0, command_line.empty() ? (char *)"" : (char *)command_line.c_str(), SW_RESTORE);
    SDL_Log("C&C Android: WinMain returned %d", result);
    return result;
}
