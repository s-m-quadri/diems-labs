/******************************************************************************

///////////////////////////////////////////////////////////////////////////////
 * @file bank.h
 * @brief Implementation of bank related functionalities
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

#include "bank.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cs50.h"

/**
 * @brief This function will create a bank (structure) of given name and return
 * it as a reference (not copy, thus need to be freed after usage). If some
 * error happens during creation, it will return NULL reference.
 * @param name The name of the bank
 * @return BANK (reference, not copy) or 'NULL'
 */
BANK create_bank(string name) {
  // Create: Make space for bank
  BANK new_space = (BANK)calloc(1, sizeof(bank_element));
  if (new_space == NULL) {
    printf("\e[38;5;196mError:\e[0m Out of memory.\n");
    return NULL;
  }
  // Configure: Initialize variables of bank
  new_space->name = name;
  new_space->accounts_quantity = 0;
  new_space->user_login_id = -1;
  new_space->account = NULL;

  // Status: Return the bank's structure reference
  return new_space;
}

/**
 * @brief This function will take the bank as an input and returns the status as
 * 'true' if successfully deleted the bank. Otherwise returns status as 'false'
 * if failed to delete the bank.
 * @param bank The bank's data struture reference
 * @return 'true' or 'false'
 */
bool delete_bank(BANK bank) {
  // Check: Whether the bank exist!
  if (bank == NULL) return false;

  // Clean: Free the space allocated by bank's structure reference
  free(bank->account);
  free(bank);

  // Status: Reached success
  return true;
}

/**
 * @brief This function will log the user into the bank by updating the 'bank'
 * structure reference. Also some check happens here, e.g. wether the given
 * username exist or not, if exist then authorize, if not exist the create the
 * space for new user. Afterwards updating the curent_login_id variable in the
 * 'bank' structure reference everybody get knows about the login status of
 * current user. Returns 'true' if successfully created space (if any) and
 * logged in, otherwise returns 'false'.
 * @param bank The bank's data struture reference
 * @return 'true' or 'false'
 */
bool login(BANK bank) {
  // Check: Wether the bank exist!
  if (bank == NULL) return false;

  // Clean: Clean up the login status
  logout(bank);

  // Get: The username
  string user = get_string(
      "\e[38;5;214m>\e[0m Enter User Name (case sensitive) : \e[38;5;214m");

  // Find: The username from existing accounts in bank
  // IF FOUND:
  for (int i = 0; i < bank->accounts_quantity; i++) {
    if (strcmp(user, bank->account[i].name) == 0) {
      // Get: PIN for authorization
      long long unsigned int PIN =
          get_long_long("\e[38;5;214m>\e[0m Enter PIN: ");

      // Authorize: Get the user access to bank account
      if (PIN == bank->account[i].pin) {
        bank->user_login_id = bank->account[i].id;
        return true;
      }

      // Un-Authorize: PIN don't match, failed to login
      else {
        printf("\e[38;5;196mError:\e[0m Wrong PIN.\n");
        return false;
      }
    }
  }

  // IF NOT FOUND
  // Warn: About creating new space
  printf("\e[38;5;214mWarning:\e[0m Account does't exist!\n");
  printf(
      "\e[38;5;214mInfo:\e[0m Creating new account with User Name "
      "\e[38;5;214m%s\e[0m.\n",
      user);

  // Get: The passwords for new user
  long long unsigned int PIN = get_long_long("\e[38;5;214m>\e[0m Enter PIN: ");
  long long unsigned int C_PIN =
      get_long_long("\e[38;5;214m>\e[0m Re-Enter PIN: ");

  // Check: Do passwords confirmed
  if (PIN != C_PIN) {
    printf("\e[38;5;196mError:\e[0m Passwords don't match.\n");
    return false;
  }

  // Create: Make space for new user
  unsigned int cur_user = bank->accounts_quantity;
  account_element* new_space = (account_element*)realloc(
      bank->account, sizeof(account_element) * (cur_user + 1));
  if (new_space == NULL) {
    printf("\e[38;5;196mError:\e[0m Out of memory.\n");
    return false;
  }
  // Configure: Initialize variables of new user's bank account
  bank->account = new_space;
  bank->account[cur_user].id = cur_user;
  bank->account[cur_user].pin = PIN;
  bank->account[cur_user].name = user;
  bank->account[cur_user].amount = 3210;
  bank->accounts_quantity++;
  bank->user_login_id = cur_user;

  // Status: Reached success
  return true;
}

/**
 * @brief This function will take 'bank' structure reference as an input and log
 * the user out simply by updating the current user login id variable in the
 * structure reference of bank. Returns 'true' if successfully log the user out,
 * otherwise returns the 'false'.
 * @param bank The bank's data struture reference
 * @return 'true' or 'false'
 */
bool logout(BANK bank) {
  if (bank == NULL) return false;
  bank->user_login_id = -1;
  return true;
}

/**
 * @brief This function will deposit the given 'amount' into the logged in
 * user's bank account. Returns 'true' if successfully deposited the given
 * 'amount', otherwise returns 'false'.
 * @param bank The bank's data struture reference
 * @param amount The amount which has to be deposited into the logged in user's
 * bank account
 * @return 'true' or 'false'
 */
bool deposit(BANK bank, long long int amount) {
  // Check: Wether the 'bank' exist!
  if (bank == NULL) return false;

  // Check: Wether the user is logged in
  if (bank->user_login_id == -1) {
    printf("\e[38;5;196mError:\e[0m Login required.\n");
    return false;
  }

  // Check: Wether the amount is positive
  if (amount <= 0) {
    printf("\e[38;5;196mError:\e[0m Amount must be in positive numeric.\n");
    return false;
  }

  // Deposit: Into the logged in user's bank account
  unsigned int cur_user = bank->user_login_id;
  bank->account[cur_user].amount += amount;

  // Status: Reached success
  return true;
}

/**
 * @brief This function will withdraw the given 'amount' from the logged in
 * user's bank account. Returns 'true' if successfully withdrawn the given
 * 'amount' otherwise returns 'false'.
 * @param bank The bank's data struture reference
 * @param amount The amount which has to be withdrawn from the logged in user's
 * bank account
 * @return 'true' or 'false'
 */
bool withdraw(BANK bank, long long int amount) {
  // Check: Wether the 'bank' exist!
  if (bank == NULL) return false;

  // Check: Wether the user logged in
  if (bank->user_login_id == -1) {
    printf("\e[38;5;196mError:\e[0m Login required.\n");
    return false;
  }

  // Check: Wether the amount is positive
  if (amount <= 0) {
    printf("\e[38;5;196mError:\e[0m Amount must be in positive numeric.\n");
    return false;
  }

  // Check: Wether the user has enough amount to withdraw
  unsigned int cur_user = bank->user_login_id;
  if (amount > bank->account[cur_user].amount) {
    printf("\e[38;5;196mError:\e[0m You don't have enough amount.\n");
    return false;
  }

  // Withdraw: From the logged in user's bank account
  bank->account[cur_user].amount -= amount;

  // Status: Reached success
  return true;
}

/**
 * @brief This function will create a 'cash' of the given 'amount' and the
 * logged in user's bank account. Return the 'cash' structure reference (not
 * copy, thus need to be freed after usage) if successfully, otherwise returns
 * 'NULL'.
 * @param bank The bank's data struture reference
 * @param amount The cash amount for withdrawal from the logged in user's bank
 * account
 * @return CASH (reference, not copy) or 'NULL'
 */
CASH create_cash_withdraw(BANK bank, long long int amount) {
  // Check: Wether the 'bank' exist
  if (bank == NULL) return NULL;

  // Check: Wether the user is logged in
  if (bank->user_login_id == -1) {
    printf("\e[38;5;196mError:\e[0m Login required.\n");
    return NULL;
  }

  // Check: Wether the amount is positive
  if (amount <= 0) {
    printf("\e[38;5;196mError:\e[0m Amount must be in positive numeric.\n");
    return NULL;
  }

  // Check: Wether the user has enough amount to withdraw
  unsigned int cur_user = bank->user_login_id;
  if (amount > bank->account[cur_user].amount) {
    printf("\e[38;5;196mError:\e[0m You don't have enough amount.\n");
    return NULL;
  }

  // Create: Make a new space for cash
  CASH cash = (CASH)calloc(1, sizeof(cash_element));

  // Configure: Initialize the cash structure reference's new variables
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

  // Status: Handover the cash
  return cash;
}

/**
 * @brief This function will update the cash structure reference (if any) by
 * minimizing the number of currency notes (aka maximizing the higher
 * denominations), and withdraw just like a simple withdraw happens from logged
 * in user's bank account. Returns 'true' if successfully withdrawn, otherwise
 * returns 'false'.
 * @param bank The bank's data struture reference
 * @param cash The 'cash' which has to be withdrawn from logged in user
 * @return 'true' or 'false'
 */
bool withdraw_cash(BANK bank, CASH cash) {
  // Check: Whether 'bank' exist!
  if (bank == NULL) return false;

  // Check: Whether 'cash' exist!
  if (cash == NULL) return false;

  // Compute Optimal Solution:
  // Both the following statement are similar in logic,
  // a. "Minimum number of currency denominations"
  // b. "Maximum number of notes of higher currency denominations"
  maximize(cash, 2000);
  maximize(cash, 500);
  maximize(cash, 100);
  maximize(cash, 50);
  maximize(cash, 10);
  maximize(cash, 5);
  maximize(cash, 2);
  maximize(cash, 1);

  // Check: Do we have converted 'all the amount' to cash.
  if (cash->remain != 0) return false;

  // Withdraw the given 'amount' from logged in user's bank account.
  unsigned int cur_user = bank->user_login_id;
  bank->account[cur_user].amount -= cash->amount;

  // Status: Success
  return true;
}

/**
 * @brief This function will maximize the given 'denomination' from the given
 * 'cash' structure reference. Returns 'true' if successfully maximized,
 * otherwise returns 'false'.
 * @param cash The 'cash' from which the given 'denomination' is to maximized
 * @param denomination The 'denomination' which has to be maximized
 * @return 'true' or 'false'
 */
bool maximize(CASH cash, int denomination) {
  // Check: Whether 'cash' exist!
  if (cash == NULL) return false;

  // Maximize the given denomination
  switch (denomination) {
    // Denomination: Rs. 1/-
    case 1:
      cash->_Rs1_coins += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;

    // Denomination: Rs. 2/-
    case 2:
      cash->_Rs2_coins += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;

    // Denomination: Rs. 5/-
    case 5:
      cash->_Rs5_coins += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;

    // Denomination: Rs. 10/-
    case 10:
      cash->_Rs10_notes += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;

    // Denomination: Rs. 50/-
    case 50:
      cash->_Rs50_notes += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;

    // Denomination: Rs. 100/-
    case 100:
      cash->_Rs100_notes += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;

    // Denomination: Rs. 500/-
    case 500:
      cash->_Rs500_notes += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;

    // Denomination: Rs. 2000/-
    case 2000:
      cash->_Rs2000_notes += cash->remain / denomination;
      cash->remain = cash->remain % denomination;
      return true;
  }

  // Check: Invalid denomination
  printf(
      "\e[38;5;196mError:\e[0m Denomination \e[38;5;214mRs. %d/-\e[0m "
      "don't exist.\n",
      denomination);
  return false;
}

/**
 * @brief This function will display significant details of 'cash' structure
 * reference with text decoration using escape characters. The function returns
 * nothing.
 * @param cash The 'cash' which has to be displayed
 * @return void (nothing)
 */
void display_cash(CASH cash) {
  // Check: Wether the bank exist
  if (cash == NULL) return;

  // Display: cash information
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

/**
 * @brief This function will display some of the details of the logged in user's
 * bank account with text decoration using escape characters. The function
 * returns nothing.
 * @param bank The 'bank' from which some details of logged in user's bank
 * account has to be displayed
 * @return void (nothing)
 */
void display(BANK bank) {
  // Check: Wether the bank exist
  if (bank == NULL) return;

  // Display: logged in user's account details
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

/**
 * @brief This function is meant to display help manual for the console app.
 * Neither require any input nor returns any thing, just have side effect as
 * text which is decorated using escape codes.
 */
void help() {
  // Display: help manual
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