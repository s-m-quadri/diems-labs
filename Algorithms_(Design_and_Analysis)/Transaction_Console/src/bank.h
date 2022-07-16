/******************************************************************************

///////////////////////////////////////////////////////////////////////////////
 * @file bank.h
 * @brief Interface of bank related functionalities
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

#ifndef BANK_H
#define BANK_H

#include <stdbool.h>

#include "bank.h"
#include "cs50.h"

/**
 * @brief Structure of the user's bank account
 */
typedef struct {
  unsigned int id;
  long long unsigned int pin;
  string name;
  long long int amount;
} account_element;

/**
 * @brief Structure of the bank
 */
typedef struct {
  string name;
  unsigned int accounts_quantity;
  int user_login_id;
  account_element* account;
} bank_element;

/**
 * @brief Structure of the cash
 */
typedef struct {
  long long int amount;
  long long int remain;
  int _Rs1_coins;
  int _Rs2_coins;
  int _Rs5_coins;
  int _Rs10_notes;
  int _Rs50_notes;
  int _Rs100_notes;
  int _Rs500_notes;
  int _Rs2000_notes;
} cash_element;

/**
 * @brief Bank's Data structure Reference
 */
#define BANK bank_element*

/**
 * @brief Cash's Data structure Reference
 */
#define CASH cash_element*

/**
 * @brief This function will create a bank (structure) of given name and return
 * it as a reference (not copy, thus need to be freed after usage). If some
 * error happens during creation, it will return NULL reference.
 * @param name The name of the bank
 * @return BANK (reference, not copy) or 'NULL'
 */
BANK create_bank(string name);

/**
 * @brief This function will take the bank as an input and returns the status as
 * 'true' if successfully deleted the bank. Otherwise returns status as 'false'
 * if failed to delete the bank.
 * @param bank The bank's data struture reference
 * @return 'true' or 'false'
 */
bool delete_bank(BANK bank);

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
bool login(BANK bank);

/**
 * @brief This function will take 'bank' structure reference as an input and log
 * the user out simply by updating the current user login id variable in the
 * structure reference of bank. Returns 'true' if successfully log the user out,
 * otherwise returns the 'false'.
 * @param bank The bank's data struture reference
 * @return 'true' or 'false'
 */
bool logout(BANK bank);

/**
 * @brief This function will deposit the given 'amount' into the logged in
 * user's bank account. Returns 'true' if successfully deposited the given
 * 'amount', otherwise returns 'false'.
 * @param bank The bank's data struture reference
 * @param amount The amount which has to be deposited into the logged in user's
 * bank account
 * @return 'true' or 'false'
 */
bool deposit(BANK bank, long long int amount);

/**
 * @brief This function will withdraw the given 'amount' from the logged in
 * user's bank account. Returns 'true' if successfully withdrawn the given
 * 'amount' otherwise returns 'false'.
 * @param bank The bank's data struture reference
 * @param amount The amount which has to be withdrawn from the logged in user's
 * bank account
 * @return 'true' or 'false'
 */
bool withdraw(BANK bank, long long int amount);

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
CASH create_cash_withdraw(BANK bank, long long int amount);

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
bool withdraw_cash(BANK bank, CASH cash);

/**
 * @brief This function will maximize the given 'denomination' from the given
 * 'cash' structure reference. Returns 'true' if successfully maximized,
 * otherwise returns 'false'.
 * @param cash The 'cash' from which the given 'denomination' is to maximized
 * @param denomination The 'denomination' which has to be maximized
 * @return 'true' or 'false'
 */
bool maximize(CASH cash, int denomination);

/**
 * @brief This function will display significant details of 'cash' structure
 * reference with text decoration using escape characters. The function returns
 * nothing.
 * @param cash The 'cash' which has to be displayed
 * @return void (nothing)
 */
void display_cash(CASH cash);

/**
 * @brief This function will display some of the details of the logged in user's
 * bank account with text decoration using escape characters. The function
 * returns nothing.
 * @param bank The 'bank' from which some details of logged in user's bank
 * account has to be displayed
 * @return void (nothing)
 */
void display(BANK bank);

/**
 * @brief This function is meant to display help manual for the console app.
 * Neither require any input nor returns any thing, just have side effect as
 * text which is decorated using escape codes.
 */
void help();

#endif