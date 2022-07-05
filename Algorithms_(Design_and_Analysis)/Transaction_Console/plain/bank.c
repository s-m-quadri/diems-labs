/******************************************************************************

///////////////////////////////////////////////////////////////////////////////
//     -> Library "Bank"                                                     //
//     -> Implementations Section                                            //
//     -> Last updated on July 2022                                          //
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

#include "bank.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cs50.h"

BANK create_bank(string name) {
  BANK new_space = (BANK)calloc(1, sizeof(bank_element));
  if (new_space == NULL) {
    printf("Error: Out of memory.\n");
    return NULL;
  }
  new_space->name = name;
  new_space->accounts_quantity = 0;
  new_space->user_login_id = -1;
  new_space->account = NULL;
  return new_space;
}

bool delete_bank(BANK bank) {
  if (bank == NULL) return false;
  free(bank->account);
  free(bank);
  return true;
}

bool login(BANK bank) {
  if (bank == NULL) return false;
  // Clean up login status
  logout(bank);

  // Authorize from existing data
  string user = get_string(
      "> Enter User Name (case sensitive) : ");
  for (int i = 0; i < bank->accounts_quantity; i++) {
    if (strcmp(user, bank->account[i].name) == 0) {
      long long unsigned int PIN =
          get_long_long("> Enter PIN: ");
      if (PIN == bank->account[i].pin) {
        bank->user_login_id = bank->account[i].id;
        return true;
      } else {
        printf("Error: Wrong PIN.\n");
        return false;
      }
    }
  }

  // Create new space
  printf("Warning: Account does't exist!\n");
  printf(
      "Info: Creating new account with User Name "
      "%s.\n",
      user);
  long long unsigned int PIN = get_long_long("> Enter PIN: ");
  long long unsigned int C_PIN =
      get_long_long("> Re-Enter PIN: ");
  if (PIN == C_PIN) {
    unsigned int cur_user = bank->accounts_quantity;
    account_element* new_space = (account_element*)realloc(
        bank->account, sizeof(account_element) * (cur_user + 1));
    if (new_space == NULL) {
      printf("Error: Out of memory.\n");
      return false;
    }
    bank->account = new_space;
    bank->account[cur_user].id = cur_user;
    bank->account[cur_user].pin = PIN;
    bank->account[cur_user].name = user;
    bank->account[cur_user].amount = 3210;
    bank->accounts_quantity++;
    bank->user_login_id = cur_user;
    return true;
  } else {
    printf("Error: Passwords don't match.\n");
    return false;
  }
}

bool logout(BANK bank) {
  if (bank == NULL) return false;
  bank->user_login_id = -1;
  return true;
}

bool deposit(BANK bank, long long int amount) {
  if (bank == NULL) return false;
  if (bank->user_login_id == -1) {
    printf("Error: Login required.\n");
    return false;
  }
  if (amount <= 0) {
    printf("Error: Amount must be in positive numeric.\n");
    return false;
  }
  unsigned int cur_user = bank->user_login_id;
  bank->account[cur_user].amount += amount;
  return true;
}

bool withdraw(BANK bank, long long int amount) {
  if (bank == NULL) return false;
  if (bank->user_login_id == -1) {
    printf("Error: Login required.\n");
    return false;
  }
  if (amount <= 0) {
    printf("Error: Amount must be in positive numeric.\n");
    return false;
  }
  unsigned int cur_user = bank->user_login_id;
  if (amount > bank->account[cur_user].amount) {
    printf("Error: You don't have enough amount.\n");
    return false;
  }
  bank->account[cur_user].amount -= amount;
  return true;
}

CASH create_cash_withdraw(BANK bank, long long int amount) {
  if (bank == NULL) return NULL;
  if (bank->user_login_id == -1) {
    printf("Error: Login required.\n");
    return NULL;
  }
  if (amount <= 0) {
    printf("Error: Amount must be in positive numeric.\n");
    return NULL;
  }
  unsigned int cur_user = bank->user_login_id;
  if (amount > bank->account[cur_user].amount) return NULL;

  CASH cash = (CASH)calloc(1, sizeof(cash_element));
  cash->amount = amount;
  cash->remain = cash->amount;
  cash->_Rs1_coins = 0;
  cash->_Rs2_coins = 0;
  cash->_Rs5_coins = 0;
  cash->_Rs10_notes = 0;
  cash->_Rs50_notes = 0;
  cash->_Rs100_notes = 0;
  cash->_Rs500_notes = 0;
  cash->_Rs2000_notes = 0;
  return cash;
}

bool withdraw_cash(BANK bank, CASH cash) {
  if (bank == NULL) return false;
  if (cash == NULL) return false;

  // Optimal Solution
  maximize(cash, 2000);
  maximize(cash, 500);
  maximize(cash, 100);
  maximize(cash, 50);
  maximize(cash, 10);
  maximize(cash, 5);
  maximize(cash, 2);
  maximize(cash, 1);
  if (cash->remain != 0) return false;
  unsigned int cur_user = bank->user_login_id;
  bank->account[cur_user].amount -= cash->amount;
  return true;
}

bool maximize(CASH cash, int denomination) {
  if (cash == NULL) return false;
  switch (denomination) {
    case 1:
      cash->_Rs1_coins += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;
    case 2:
      cash->_Rs2_coins += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;
    case 5:
      cash->_Rs5_coins += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;
    case 10:
      cash->_Rs10_notes += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;
    case 50:
      cash->_Rs50_notes += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;
    case 100:
      cash->_Rs100_notes += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;
    case 500:
      cash->_Rs500_notes += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;
    case 2000:
      cash->_Rs2000_notes += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;

    default:
      printf(
          "Error: Denomination Rs. %d/- "
          "don't exist.\n",
          denomination);
      return false;
  }
}

void display_cash(CASH cash) {
  if (cash == NULL) return;
  printf(
      "> You have got or withdrawn the cash of \n"
      "  total amount Rs. %llu/- having,\n"
      "  %4d number of Coin(s) of Rs. 1/-\n"
      "  %4d number of Coin(s) of Rs. 2/-\n"
      "  %4d number of Coin(s) of Rs. 5/-\n"
      "  %4d number of Note(s) of Rs. 10/-\n"
      "  %4d number of Note(s) of Rs. 50/-\n"
      "  %4d number of Note(s) of Rs. 100/-\n"
      "  %4d number of Note(s) of Rs. 500/-\n"
      "  %4d number of Note(s) of Rs. "
      "2000/-\n",
      cash->amount, cash->_Rs1_coins, cash->_Rs2_coins, cash->_Rs5_coins,
      cash->_Rs10_notes, cash->_Rs50_notes, cash->_Rs100_notes,
      cash->_Rs500_notes, cash->_Rs2000_notes);
}

void display(BANK bank) {
  if (bank == NULL) return;
  printf(
      "> The Bank Name is %s, which is\n"
      "  currently under %s's control.\n",
      bank->name,
      (bank->user_login_id != -1) ? bank->account[bank->user_login_id].name
                                  : "nobody");
  if (bank->user_login_id != -1)
    printf(
        "> Account with ID %02u is owned "
        "by,\n"
        "  the user %s who have Rs. %llu /-\n"
        "  in his/her account\n",
        bank->user_login_id, bank->account[bank->user_login_id].name,
        bank->account[bank->user_login_id].amount);
}

void help() {
  printf(
      "\n"
      "> Command $: login\n"
      "             to proceed for login\n"
      "> Command $: deposit (amount)\n"
      "     e.g. $: deposit 300\n"
      "             will deposit 300 into the logged in account\n"
      "> Command $: withdraw (amount)\n"
      "     e.g. $: withdraw 300\n"
      "             will withdraw 300 from the logged in account\n"
      "> Command $: withdraw cash (amount) "
      "(note-denom...) "
      "done\n"
      "     e.g. $: withdraw cash 300 100 50 done\n"
      "             will withdraw 300 from the logged in account\n"
      "             in form of cash and will maximize the notes\n"
      "             of denomination 100 then will maximize the\n"
      "             notes of denomination 50. Afterwards, will calculate\n"
      "             the optimal (here, minimum) number of notes to\n"
      "             complete the withdrawn amount and give it to user.\n"
      "> Command $: show\n"
      "             to show the status of the logged in account\n"
      "> Command $: logout\n"
      "             to proceed for logout\n"
      "> Command $: exit\n"
      "             to terminate the console\n"
      "\n");
}