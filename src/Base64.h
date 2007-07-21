/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef _BASE64_H_
#define _BASE64_H_
#include <string>
#include "common.h"
using namespace std;

class Base64
{
private:
  static void part_encode(const unsigned char* sub, int32_t subLength,
			  unsigned char* buf);

  static string part_encode(const string& subplain);
  static string part_decode(const string& subCrypted);
  static char getValue(char ch);
public:
  static string encode(const string& plain);
  // caller must deallocate the memory used by result.
  static void encode(const unsigned char* src, int32_t srcLength,
		     unsigned char*& result, int32_t& resultLength);
  static string decode(const string& crypted);
  // caller must deallocate the memory used by result.
  static void decode(const unsigned char* src, int32_t srcLength,
		     unsigned char*& result, int32_t& resultLength);
};

#endif // _BASE64_H_
