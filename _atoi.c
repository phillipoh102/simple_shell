#include "shell.h"

/*
 * This program defines four functions:
 *
 *   - interactive()
 *   - is_delim()
 *   - _isalpha()
 *   - _atoi()
 */

/**
 * interactive() - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info) {
  /*
   * This function checks if the shell is in interactive mode.
   *
   * An interactive shell is one that is connected to a terminal.
   *
   * The function returns 1 if the shell is interactive, and 0 otherwise.
   */

  return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim) {
  /*
   * This function checks if the character c is a delimiter.
   *
   * A delimiter is a character that separates words.
   *
   * The function returns 1 if c is a delimiter, and 0 otherwise.
   */

  while (*delim) {
    if (*delim++ == c) {
      return (1);
    }
  }
  return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c) {
  /*
   * This function checks if the character c is an alphabetic character.
   *
   * An alphabetic character is a character that is a letter.
   *
   * The function returns 1 if c is an alphabetic character, and 0 otherwise.
   */

  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    return (1);
  } else {
    return (0);
  }
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s) {
  /*
   * This function converts the string s to an integer.
   *
   * The function returns 0 if there are no numbers in the string, and the converted number otherwise.
   */

  int i, sign = 1, flag = 0, output;
  unsigned int result = 0;

  for (i = 0; s[i] != '\0' && flag != 2; i++) {
    if (s[i] == '-') {
      sign *= -1;
    }

    if (s[i] >= '0' && s[i] <= '9') {
      flag = 1;
      result *= 10;
      result += (s[i] - '0');
    } else if (flag == 1) {
      flag = 2;
    }
  }

  if (sign == -1) {
    output = -result;
  } else {
    output = result;
  }

  return (output);
}

