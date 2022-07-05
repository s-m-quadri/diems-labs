/******************************************************************************

///////////////////////////////////////////////////////////////////////////////
//     -> Library "Bank"                                                     //
//     -> Interface Section                                                  //
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

#ifndef BANK_H
#define BANK_H

#include <stdbool.h>

#include "bank.h"
#include "cs50.h"

typedef struct {
  unsigned int id;
  long long unsigned int pin;
  string name;
  long long int amount;
} account_element;

typedef struct {
  string name;
  unsigned int accounts_quantity;
  int user_login_id;
  account_element* account;
} bank_element;

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

typedef bank_element* BANK;
typedef cash_element* CASH;

BANK create_bank(string name);
bool delete_bank(BANK bank);
bool login(BANK bank);
bool logout(BANK bank);
bool deposit(BANK bank, long long int amount);
bool withdraw(BANK bank, long long int amount);
CASH create_cash_withdraw(BANK bank, long long int amount);
bool withdraw_cash(BANK bank, CASH cash);
bool maximize(CASH cash, int denomination);
void display_cash(CASH cash);
void display(BANK bank);
void help();

#endif