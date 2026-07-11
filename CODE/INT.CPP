/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"mp.h"
#include "int.h"

template<> int bignum::Error = 0;
template<> bool bignum::Carry = false;
template<> bool bignum::Borrow = false;
template<> bignum bignum::Remainder = bignum();
