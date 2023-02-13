#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define LOCAL_KINETIC_DIRECTORY "~/.kinetic"
#define LOCAL_ACTIONS_DIRECTORY "~/.kinetic/actions"
#define MAX_PATH 260

typedef struct {
    char const* command_name;
    char const* command;
    char const* description;
} action;

typedef struct {
    action* actions;
    size_t action_count;
} actions;

actions g_actions;
char const* g_kinetic_directory;

int get_actions(char const* actions_directory, actions* actions);

void print_help();

char* get_kinetic_directory_location(void)
{
    char kinetic_directory[MAX_PATH];
    char* kinetic_environment_variable = NULL;
    if ((kinetic_environment_variable = getenv("Kinetic")) != NULL) {
        snprintf(kinetic_directory, MAX_PATH, "%s", kinetic_environment_variable);
        return strdup(kinetic_directory);
    }
    size_t home_directory_max_length = MAX_PATH - strlen(".kinetic/");
#ifdef _WIN32
    snprintf(kinetic_directory, home_directory_max_length, "%s%s", getenv("HOMEDRIVE"), getenv("HOMEPATH"));
#else
    snprintf(kinetic_directory, home_directory_max_length, "%s", getenv("HOME"));
#endif
    strcat(kinetic_directory, "/.kinetic");
    return strdup(kinetic_directory);
}

int main(int argc, char* argv[])
{
    g_kinetic_directory = get_kinetic_directory_location();

    char* actions_location = strdup(g_kinetic_directory);
    strcat(actions_location, "/actions");
    get_actions(actions_location, &g_actions);

    if (argc < 2) {
        fprintf(stderr, "Too little arguments\n");
        print_help();
        return 1;
    }
    return 0;
}

void print_help()
{
    printf("Available actions:\n");
    for (int i = 0; i < g_actions.action_count; ++i) {
        // printf("%-20s", g_actions.actions[i].command_name);
    }
}

int get_actions(char const* actions_directory, actions* actions)
{
    struct stat directory_info;
    if (stat(actions_directory, &directory_info) != 0) {
        fprintf(stderr, "Could not find actions directory at: %s\n", actions_directory);
        return 1;
    }

    if (!S_ISDIR(directory_info.st_mode)) {
        fprintf(stderr, "entry is not a directory at: %s\n", actions_directory);
        return 1;
    }

    DIR* directory = opendir(actions_directory);
    actions->action_count = 0;
    if (directory != NULL) {
        struct dirent* entry;
        long first_entry = telldir(directory);
        while ((entry = readdir(directory)) != NULL) {
            struct stat entry_info;
            stat(entry->d_name, &entry_info);
            if (S_ISREG(entry_info.st_mode)) {
                printf("%4s: %s\n", "FILE", entry->d_name);
            }
            actions->action_count++;
        }

        seekdir(directory, first_entry);
        actions->actions = calloc(actions->action_count, sizeof(action));

        for (int i = 0; i < actions->action_count; entry = readdir(directory), i++) {
            struct stat entry_info;
            stat(entry->d_name, &entry_info);
            if (S_ISREG(entry_info.st_mode)) {
                actions->actions[i].command = entry->d_name;
            }
        }
    }

    return 0;
}
