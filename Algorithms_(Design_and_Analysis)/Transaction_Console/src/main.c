/******************************************************************************

///////////////////////////////////////////////////////////////////////////////
//     -> Project "Transaction Console"                                      //
//     -> Main Section                                                       //
//     -> Last updated on July 2022                                          //
//     -> Compilation   $: gcc cs50.c bank.c token.c main.c                  //
//     -> Memory Check  $: valgrind ./a.out                                  //
//     -> Time Check    $: time ./a.out                                      //
//     -> Simple Run    $: ./a.out                                           //
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

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///                              Main Section                               ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bank.h"
#include "cs50.h"
#include "token.h"

bool recognize_and_perform(BANK my_bank, TOKEN_LIST list);
void GUI_icon();
void GUI_head();
TOKEN_LIST get_clean_input(BANK my_bank);

int main() {
  /////////////////////////////////////////////////////////////////////////////
  // 1. Setup the Space and GUI
  /////////////////////////////////////////////////////////////////////////////
  GUI_icon();
  BANK my_bank = create_bank(get_string("\tEnter Bank name: \e[38;5;32m"));
  GUI_head();

  /////////////////////////////////////////////////////////////////////////////
  // 2. Setup the Environment for operations
  //    A. Get the input from the user
  //    B. Scan and perform appropriate operation
  //       * Build the environment
  //       * Get the input as a string
  //       * Split the string and recognize the nature
  //       * Match with the available operation and link the data
  //         otherwise simply ignore it.
  //       * Pass the data to the respected function
  //       * Track the return status and prompt
  //    C. Clean up the input memory
  /////////////////////////////////////////////////////////////////////////////
  bool loop = true;
  while (loop) {
    TOKEN_LIST input = get_clean_input(my_bank);
    loop = recognize_and_perform(my_bank, input);
  }

  /////////////////////////////////////////////////////////////////////////////
  // 3. Clean up remainder and done!
  /////////////////////////////////////////////////////////////////////////////
  delete_bank(my_bank);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///                       Implementation Section                            ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

bool recognize_and_perform(BANK my_bank, TOKEN_LIST list) {
  enum {
    FREE,
    HOLD_BY_DEPOSIT,
    HOLD_BY_WITHDRAW,
    HOLD_BY_WITHDRAW_CASH,
    HOLD_BY_WITHDRAW_CASH_MAXIMIZE
  };
  int environment = FREE;
  int scanned_token = 0;
  CASH cash = NULL;
  bool return_status = true;
  while (scanned_token <= list->quantity) {
    /////////////////////////////////////////////////////////////////////////
    // At end, inform correction for previous incomplete commands
    /////////////////////////////////////////////////////////////////////////
    if (scanned_token == list->quantity) {
      if (environment != FREE)
        printf("\e[38;5;196mFailure:\e[0m Incomplete operation and command.\n");
      if (environment == HOLD_BY_DEPOSIT)
        printf("Usage \e[38;5;214m$: deposit (amount)\e[0m\n");
      if (environment == HOLD_BY_WITHDRAW)
        printf("Usage \e[38;5;214m$: withdraw (amount)\e[0m\n");
      if (environment == HOLD_BY_WITHDRAW_CASH ||
          environment == HOLD_BY_WITHDRAW_CASH_MAXIMIZE)
        printf(
            "Usage \e[38;5;214m$: withdraw cash (amount) (note-denom...) "
            "done\e[0m\n");
      break;
    }

    /////////////////////////////////////////////////////////////////////////
    // Command $: exit
    /////////////////////////////////////////////////////////////////////////
    if (strcmp(list->tokens[scanned_token].get, "exit") == 0 &&
        environment == FREE) {
      return_status = false;
      break;
    }

    /////////////////////////////////////////////////////////////////////////
    // Command $: exit
    /////////////////////////////////////////////////////////////////////////
    if (strcmp(list->tokens[scanned_token].get, "help") == 0 &&
        environment == FREE) {
      help();
      scanned_token++;
      continue;
    }

    /////////////////////////////////////////////////////////////////////////
    // Command $: login
    /////////////////////////////////////////////////////////////////////////
    if (strcmp(list->tokens[scanned_token].get, "login") == 0 &&
        environment == FREE) {
      if (login(my_bank) == true)
        printf("\e[38;5;40mSuccess:\e[0m You have logged into the account!\n");
      else
        printf("\e[38;5;196mFailure:\e[0m Not logged in! Try again.\n");
      scanned_token++;
      continue;
    }

    /////////////////////////////////////////////////////////////////////////
    // Command $: logout
    /////////////////////////////////////////////////////////////////////////
    if (strcmp(list->tokens[scanned_token].get, "logout") == 0 &&
        environment == FREE) {
      if (logout(my_bank) == true)
        printf(
            "\e[38;5;40mSuccess:\e[0m You have logged out of the account!\n");
      else
        printf("\e[38;5;196mFailure:\e[0m Not logged out! Try again.\n");
      scanned_token++;
      continue;
    }

    /////////////////////////////////////////////////////////////////////////
    // Command $: deposit (amount)
    /////////////////////////////////////////////////////////////////////////
    if (strcmp(list->tokens[scanned_token].get, "deposit") == 0 &&
        environment == FREE) {
      environment = HOLD_BY_DEPOSIT;
      scanned_token++;
      continue;
    }
    if (environment == HOLD_BY_DEPOSIT) {
      if (list->tokens[scanned_token].is_numeric == true) {
        if (deposit(my_bank, atoll(list->tokens[scanned_token].get)) == true)
          printf(
              "\e[38;5;40mSuccess:\e[0m You have deposited into the "
              "account!\n");
        else
          printf(
              "\e[38;5;196mFailure:\e[0m Something went wrong! Try again.\n");
        environment = FREE;
      }
      scanned_token++;
      continue;
    }

    /////////////////////////////////////////////////////////////////////////
    // Command $: withdraw (amount)
    /////////////////////////////////////////////////////////////////////////
    if (strcmp(list->tokens[scanned_token].get, "withdraw") == 0 &&
        environment == FREE) {
      environment = HOLD_BY_WITHDRAW;

      // Continue
      scanned_token++;
      continue;
    }

    if (environment == HOLD_BY_WITHDRAW) {
      // If numeric
      if (list->tokens[scanned_token].is_numeric == true) {
        if (withdraw(my_bank, atoll(list->tokens[scanned_token].get)) == true)
          printf(
              "\e[38;5;40mSuccess:\e[0m You have withdrawn from the "
              "account!\n");
        else
          printf(
              "\e[38;5;196mFailure:\e[0m Something went wrong! Try again.\n");
        environment = FREE;
      }

      // If alphabetic
      if (list->tokens[scanned_token].is_alpha == true) {
        if (strcmp(list->tokens[scanned_token].get, "cash") == 0) {
          environment = HOLD_BY_WITHDRAW_CASH;
        }
      }

      // Continue
      scanned_token++;
      continue;
    }

    /////////////////////////////////////////////////////////////////////////
    // Command $: withdraw cash (amount) (note-denom...) done
    /////////////////////////////////////////////////////////////////////////
    if (environment == HOLD_BY_WITHDRAW_CASH) {
      // If numeric
      if (list->tokens[scanned_token].is_numeric == true) {
        cash = create_cash_withdraw(my_bank,
                                    atoll(list->tokens[scanned_token].get));
        environment = HOLD_BY_WITHDRAW_CASH_MAXIMIZE;
      }

      // Continue
      scanned_token++;
      continue;
    }

    if (environment == HOLD_BY_WITHDRAW_CASH_MAXIMIZE) {
      // If numeric
      if (list->tokens[scanned_token].is_numeric == true) {
        if (maximize(cash, atoi(list->tokens[scanned_token].get)) == true)
          printf("\e[38;5;40mSuccess:\e[0m maximized Rs. %d/- notes!\n",
                 atoi(list->tokens[scanned_token].get));
      }

      // If alphabetic
      if (list->tokens[scanned_token].is_alpha == true) {
        if (strcmp(list->tokens[scanned_token].get, "done") == 0) {
          if (withdraw_cash(my_bank, cash) == true) {
            printf(
                "\e[38;5;40mSuccess:\e[0m You have withdrawn from the "
                "account!\n");
            display_cash(cash);
          } else
            printf(
                "\e[38;5;196mFailure:\e[0m Something went wrong! Try "
                "again.\n");

          environment = FREE;
        }
      }

      // Continue
      scanned_token++;
      continue;
    }

    /////////////////////////////////////////////////////////////////////////
    // Command $: show
    /////////////////////////////////////////////////////////////////////////
    if (strcmp(list->tokens[scanned_token].get, "show") == 0 &&
        environment == FREE) {
      display(my_bank);
      scanned_token++;
      continue;
    }

    /////////////////////////////////////////////////////////////////////////
    // Command $: (any, not listed above))
    // Just ignore them!
    /////////////////////////////////////////////////////////////////////////
    scanned_token++;
  }

  // Clean up remainder and return the status
  if (cash != NULL) {
    free(cash);
    cash = NULL;
  }
  if (list != NULL) {
    free_tokens(list);
    list = NULL;
  }
  return return_status;
}

TOKEN_LIST get_clean_input(BANK my_bank) {
  if (my_bank->user_login_id == -1)
    return get_tokens(
        get_string("\e[38;5;32mGuest@%s $: \e[0m", my_bank->name));
  else
    return get_tokens(get_string("\e[38;5;32m%s@%s $: \e[0m",
                                 my_bank->account[my_bank->user_login_id].name,
                                 my_bank->name));
}

void GUI_icon() {
  printf("\n\n\n\e[38;5;32m");
  printf("                                                  \n");
  printf("                       **                         \n");
  printf("                    ** ** **                      \n");
  printf("                 ***        ***                   \n");
  printf("              ***              ***                \n");
  printf("           ***                    ***             \n");
  printf("        ***                          ***          \n");
  printf("     *** ** ************************ ** ***       \n");
  printf("                                                  \n");
  printf("        ****    ****         ****   ****          \n");
  printf("         **      **           **     **           \n");
  printf("         **      **           **     **           \n");
  printf("         **      **           **     **           \n");
  printf("         **      **           **     **           \n");
  printf("         **      **           **     **           \n");
  printf("        ****    ****         ****   ****          \n");
  printf("                                                  \n");
  printf("       **********************************         \n");
  printf("     **************************************       \n");
  printf("                                                  \n");
  printf("\n\e[0m");
}

void GUI_head() {
  printf("\n\e[38;5;32m");
  printf(" //////////////////////////////////////////////// \n");
  printf(
      " //\e[0m     Welcome to the Transaction Console     \e[38;5;32m// \n");
  printf(" //////////////////////////////////////////////// \n");
  printf("\n\e[0m");
}