/*
** RUDREAIS, 06/13/18
** lib/
** File description:
** header
*/

#pragma once

/**********************\
*                      *
*       path.c         *
*                      *
\**********************/

/**
 * @param file descriptor
 * @return read line from file descriptor
 * @purpose reading line by line omitting the last character (\n)
 */
char *read_line(int fd);

/**********************\
*                      *
*       path.c         *
*                      *
\**********************/

/**
 * @param void
 * @return char double pointer
 * @purpose return array of string that are all of the maps path
 */
char **getpaths(void);
