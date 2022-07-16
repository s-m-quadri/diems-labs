/******************************************************************************

///////////////////////////////////////////////////////////////////////////////
 * @file token.h
 * @brief Implementation of token related functionalities
 * @author Syed Minnatullah - Quadri
 * @copyright Copyright (c) 2022, Syed Minnatullah - Quadri Under BSD 3-Clause
 * License
 * @date Last updated on July 2022
///////////////////////////////////////////////////////////////////////////////

BSD 3-Clause License

Copyright (c) 2022, Syed Minnatullah - Quadri
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

#include "token.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief This function will take string (command) as an input, split it into
 * the tokens which includes the information of words in it and the type of
 * character in each words (e.g. numeric, alphabetic) and handover the result.
 * If some error happens returns the NULL.
 * @param input The string which is to be splitted into token list
 * @return TOKEN_LIST (reference) or NULL
 */
TOKEN_LIST get_tokens(string input) {
  // Make space for list and setup
  TOKEN_LIST list = (TOKEN_LIST)malloc(sizeof(TOKEN_LIST_ELEMENT));
  list->quantity = 0;
  list->tokens = NULL;

  unsigned int scanned = 0, buffer = 0;
  while (true) {
    // 1. Iterate through whole input string
    if (input[scanned] == '\0') {
      // Stop if reached to the end
      break;
    } else if (scanned != 0) {
      // Skip the space/special character after single token scan
      scanned++;
    }
    buffer = 0;
    string token = NULL;
    bool is_numeric = true, is_alpha = true;

    // 2. Get the TOKEN
    while (true) {
      // a. Make the space for TOKEN
      if (token == NULL) {
        token = (string)malloc(sizeof(char));
      } else {
        string temp = (string)realloc(token, sizeof(char) * (buffer + 1));
        token = temp;
      }

      // b. Get the TOKEN
      if (isalnum(input[scanned + buffer]) != false) {
        if (isalpha(input[scanned + buffer]) == false) is_alpha = false;
        if (isdigit(input[scanned + buffer]) == false) is_numeric = false;
        token[buffer] = tolower(input[scanned + buffer]);
        buffer++;
        continue;
      }

      // c. Complete the TOKEN string
      token[buffer] = '\0';
      break;
    }

    // 2a. Make the space for TOKEN in the TOKEN_LIST
    if (list->tokens == NULL) {
      list->tokens = (TOKEN*)malloc(sizeof(TOKEN));
    } else {
      TOKEN* temp =
          (TOKEN*)realloc(list->tokens, sizeof(TOKEN) * (list->quantity + 1));
      list->tokens = temp;
    }
    // 2b. Put the TOKEN into the TOKEN_LIST
    list->tokens[list->quantity].is_alpha =
        (is_alpha == true && is_numeric == true) ? (false) : (is_alpha);
    list->tokens[list->quantity].is_numeric =
        (is_alpha == true && is_numeric == true) ? (false) : (is_numeric);

    string temp = (string)malloc(sizeof(char) * (buffer + 1));
    list->tokens[list->quantity].get = temp;
    strcpy(list->tokens[list->quantity].get, token);
    list->quantity++;
    free(token);
    scanned += buffer;
  }
  return list;
}

/**
 * @brief This function will take token list's reference as an input and
 * displays the tokens with related information. Just for developer and for
 * testing purpose only.
 * @param list The token list's reference structure which has to be displayed
 */
void display_tokens(TOKEN_LIST list) {
  for (int i = 0; i < list->quantity; i++) {
    printf("Token #%02d: %s, isnumber:%d isalpha:%d\n", i + 1,
           list->tokens[i].get, list->tokens[i].is_numeric,
           list->tokens[i].is_alpha);
  }
}

/**
 * @brief This function will take the token list's reference as an input and
 * frees the memory allocated by the get_tokens() function. Returns 'true' if
 * done else return 'false'.
 * @return 'true' or 'false'
 */
bool free_tokens(TOKEN_LIST list) {
  for (int i = 0; i < list->quantity; i++) {
    free(list->tokens[i].get);
  }
  free(list->tokens);
  free(list);
  return true;
}