#pragma once

/**
 * @param format : same format as printf(3) family
 * @param va_arg : argument list for format
 * @return Output string.
 *
 * my_snprintf() is a high-level implementation of snprintf(3).
 * It create output string with malloc(3).
 */

char *my_snprintf(const char *format, ...);

/**
 * @param dest : pointer to first string
 * @param src : pointer to second string
 * @return A pointer to the new string.
 *
 * my_strcat() function appends the src string and the dest string
 * into a new string create using malloc(3).
 */

char *my_strcat(char *dest, char *src);

/**
 * @param tab : A string array
 * @return A pointer to duplicated string array.
 *
 * my_tabdup() function return a pointer to a new string array
 * which is a duplicate of the string array tab.
 */

char **my_tabdup(char **tab);

/**
 * @param line : string to be parsed
 * @param delim : delimiter with which line will be parsed
 * @return A array of tokens (NULL terminated).
 *
 * my_str_to_word_array() function extract tokens from line by delim.
 * The token array is created by malloc(3).
 */

char **my_str_to_word_array(char *line, char delim);
