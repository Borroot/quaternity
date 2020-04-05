#ifndef OPTS_H
# define OPTS_H

#include "settings.h"

using namespace std;

Settings options(int argc, char **argv);
void usage(char **argv);
bool valid(Settings &settings);

#endif
