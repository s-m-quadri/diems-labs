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
#include <time.h>

#include "cs50.h"

BANK create_bank(string name) {
  BANK new_space = (BANK)calloc(1, sizeof(bank_element));
  if (new_space == NULL) {
    printf("\e[38;5;196mError:\e[0m Out of memory.\n");
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
      "\e[38;5;214m>\e[0m Enter User Name (case sensitive) : \e[38;5;214m");
  for (int i = 0; i < bank->accounts_quantity; i++) {
    if (strcmp(user, bank->account[i].name) == 0) {
      long long unsigned int PIN =
          get_long_long("\e[38;5;214m>\e[0m Enter PIN: ");
      if (PIN == bank->account[i].pin) {
        bank->user_login_id = bank->account[i].id;
        return true;
      } else {
        printf("\e[38;5;196mError:\e[0m Wrong PIN.\n");
        return false;
      }
    }
  }

  // Create new space
  printf("\e[38;5;214mWarning:\e[0m Account does't exist!\n");
  printf(
      "\e[38;5;214mInfo:\e[0m Creating new account with User Name "
      "\e[38;5;214m%s\e[0m.\n",
      user);
  long long unsigned int PIN = get_long_long("\e[38;5;214m>\e[0m Enter PIN: ");
  long long unsigned int C_PIN =
      get_long_long("\e[38;5;214m>\e[0m Re-Enter PIN: ");
  if (PIN == C_PIN) {
    unsigned int cur_user = bank->accounts_quantity;
    account_element* new_space = (account_element*)realloc(
        bank->account, sizeof(account_element) * (cur_user + 1));
    if (new_space == NULL) {
      printf("\e[38;5;196mError:\e[0m Out of memory.\n");
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
    printf("\e[38;5;196mError:\e[0m Passwords don't match.\n");
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
    printf("\e[38;5;196mError:\e[0m Login required.\n");
    return false;
  }
  if (amount <= 0) {
    printf("\e[38;5;196mError:\e[0m Amount must be in positive numeric.\n");
    return false;
  }
  unsigned int cur_user = bank->user_login_id;
  bank->account[cur_user].amount += amount;
  return true;
}

bool withdraw(BANK bank, long long int amount) {
  if (bank == NULL) return false;
  if (bank->user_login_id == -1) {
    printf("\e[38;5;196mError:\e[0m Login required.\n");
    return false;
  }
  if (amount <= 0) {
    printf("\e[38;5;196mError:\e[0m Amount must be in positive numeric.\n");
    return false;
  }
  unsigned int cur_user = bank->user_login_id;
  if (amount > bank->account[cur_user].amount) {
    printf("\e[38;5;196mError:\e[0m You don't have enough amount.\n");
    return false;
  }
  bank->account[cur_user].amount -= amount;
  return true;
}

CASH create_cash_withdraw(BANK bank, long long int amount) {
  if (bank == NULL) return NULL;
  if (bank->user_login_id == -1) {
    printf("\e[38;5;196mError:\e[0m Login required.\n");
    return NULL;
  }
  if (amount <= 0) {
    printf("\e[38;5;196mError:\e[0m Amount must be in positive numeric.\n");
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
          "\e[38;5;196mError:\e[0m Denomination \e[38;5;214mRs. %d/-\e[0m "
          "don't exist.\n",
          denomination);
      return false;
  }
}

void display_cash(CASH cash) {
  if (cash == NULL) return;
  printf(
      "\e[38;5;214m>\e[0m You have got or withdrawn the cash of \n"
      "  total amount Rs. %llu/- having,\n"
      "  \e[38;5;214m%4d\e[0m number of Coin(s) of \e[38;5;214mRs. 1/-\e[0m\n"
      "  \e[38;5;214m%4d\e[0m number of Coin(s) of \e[38;5;214mRs. 2/-\e[0m\n"
      "  \e[38;5;214m%4d\e[0m number of Coin(s) of \e[38;5;214mRs. 5/-\e[0m\n"
      "  \e[38;5;214m%4d\e[0m number of Note(s) of \e[38;5;214mRs. 10/-\e[0m\n"
      "  \e[38;5;214m%4d\e[0m number of Note(s) of \e[38;5;214mRs. 50/-\e[0m\n"
      "  \e[38;5;214m%4d\e[0m number of Note(s) of \e[38;5;214mRs. 100/-\e[0m\n"
      "  \e[38;5;214m%4d\e[0m number of Note(s) of \e[38;5;214mRs. 500/-\e[0m\n"
      "  \e[38;5;214m%4d\e[0m number of Note(s) of \e[38;5;214mRs. "
      "2000/-\e[0m\n",
      cash->amount, cash->_Rs1_coins, cash->_Rs2_coins, cash->_Rs5_coins,
      cash->_Rs10_notes, cash->_Rs50_notes, cash->_Rs100_notes,
      cash->_Rs500_notes, cash->_Rs2000_notes);
}

void display(BANK bank) {
  if (bank == NULL) return;
  printf(
      "\e[38;5;214m>\e[0m The Bank Name is \e[38;5;214m%s\e[0m, which is\n"
      "  currently under \e[38;5;214m%s's\e[0m control.\n",
      bank->name,
      (bank->user_login_id != -1) ? bank->account[bank->user_login_id].name
                                  : "nobody");
  if (bank->user_login_id != -1)
    printf(
        "\e[38;5;214m>\e[0m Account with \e[38;5;214mID %02u\e[0m is owned "
        "by,\n"
        "  the user \e[38;5;214m%s\e[0m who have \e[38;5;214mRs. %llu /-\e[0m\n"
        "  in his/her account\n",
        bank->user_login_id, bank->account[bank->user_login_id].name,
        bank->account[bank->user_login_id].amount);
}

void help() {
  printf(
      "\n"
      "\e[38;5;214m>\e[0m Command \e[38;5;214m$: login\e[0m\n"
      "             to proceed for login\n"
      "\e[38;5;214m>\e[0m Command \e[38;5;214m$: deposit (amount)\e[0m\n"
      "     e.g. $: deposit 300\n"
      "             will deposit 300 into the logged in account\n"
      "\e[38;5;214m>\e[0m Command \e[38;5;214m$: withdraw (amount)\e[0m\n"
      "     e.g. $: withdraw 300\n"
      "             will withdraw 300 from the logged in account\n"
      "\e[38;5;214m>\e[0m Command \e[38;5;214m$: withdraw cash (amount) "
      "(note-denom...) "
      "done\e[0m\n"
      "     e.g. $: withdraw cash 300 100 50 done\n"
      "             will withdraw 300 from the logged in account\n"
      "             in form of cash and will maximize the notes\n"
      "             of denomination 100 then will maximize the\n"
      "             notes of denomination 50. Afterwards, will calculate\n"
      "             the optimal (here, minimum) number of notes to\n"
      "             complete the withdrawn amount and give it to user.\n"
      "\e[38;5;214m>\e[0m Command \e[38;5;214m$: show\e[0m\n"
      "             to show the status of the logged in account\n"
      "\e[38;5;214m>\e[0m Command \e[38;5;214m$: logout\e[0m\n"
      "             to proceed for logout\e[0m\n"
      "\e[38;5;214m>\e[0m Command \e[38;5;214m$: exit\e[0m\n"
      "             to terminate the console\n"
      "\n");
}