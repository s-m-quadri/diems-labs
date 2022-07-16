/******************************************************************************

///////////////////////////////////////////////////////////////////////////////
 * @file token.h
 * @brief Interface of token related functionalities
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

#ifndef TOKEN_H
#define TOKEN_H
#include "cs50.h"

/**
 * @brief Single token data structure
 */
typedef struct {
  bool is_alpha;
  bool is_numeric;
  string get;
} TOKEN;

/**
 * @brief Token list data structure
 */
typedef struct {
  int quantity;
  TOKEN* tokens;
} TOKEN_LIST_ELEMENT;

/**
 * @brief Token list's data structure reference
 */
#define TOKEN_LIST TOKEN_LIST_ELEMENT*

/**
 * @brief This function will take string (command) as an input, split it into
 * the tokens which includes the information of words in it and the type of
 * character in each words (e.g. numeric, alphabetic) and handover the result.
 * If some error happens returns the NULL.
 * @param input The string which is to be splitted into token list
 * @return TOKEN_LIST (reference) or NULL
 */
TOKEN_LIST get_tokens(string input);

/**
 * @brief This function will take token list's reference as an input and
 * displays the tokens with related information. Just for developer and for
 * testing purpose only.
 * @param list The token list's reference structure which has to be displayed
 */
void display_tokens(TOKEN_LIST list);

/**
 * @brief This function will take the token list's reference as an input and
 * frees the memory allocated by the get_tokens() function. Returns 'true' if
 * done else return 'false'.
 * @return 'true' or 'false'
 */
bool free_tokens(TOKEN_LIST);

#endif