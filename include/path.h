#pragma once

#define DIRECTORY "maps"	// the directory to search

/**
 * @param nothing
 * @return root directory's path where your directory has been found
 * @purpose find a directory within another
 */
char *getroot(void);

/**
 * @param directory to search AND append
 * @return full path (root + directory found)
 * @purpose 
 */
char *getpath(const char *directory);
