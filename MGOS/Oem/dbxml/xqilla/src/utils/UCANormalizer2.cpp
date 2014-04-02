/*
 * Copyright (c) 2001-2008
 *     DecisionSoft Limited. All rights reserved.
 * Copyright (c) 2004-2008
 *     Oracle. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * $Id$
 */

#include "../config/xqilla_config.h"
#include <xqilla/utils/UCANormalizer.hpp>

#define NO_COMPOSITION 0xFFFFFFFF

struct ComposeValue
{
  unsigned int ch1;
  unsigned int ch2;
  unsigned int dest;
};
static unsigned int composeTableSize = 917;
static ComposeValue composeTable[] = {
{ 0x0003C, 0x00338, 0x0226E }, { 0x0003D, 0x00338, 0x02260 }, { 0x0003E, 0x00338, 0x0226F }, { 0x00041, 0x00300, 0x000C0 }, { 0x00041, 0x00301, 0x000C1 },
{ 0x00041, 0x00302, 0x000C2 }, { 0x00041, 0x00303, 0x000C3 }, { 0x00041, 0x00304, 0x00100 }, { 0x00041, 0x00306, 0x00102 }, { 0x00041, 0x00307, 0x00226 },
{ 0x00041, 0x00308, 0x000C4 }, { 0x00041, 0x00309, 0x01EA2 }, { 0x00041, 0x0030A, 0x000C5 }, { 0x00041, 0x0030C, 0x001CD }, { 0x00041, 0x0030F, 0x00200 },
{ 0x00041, 0x00311, 0x00202 }, { 0x00041, 0x00323, 0x01EA0 }, { 0x00041, 0x00325, 0x01E00 }, { 0x00041, 0x00328, 0x00104 }, { 0x00042, 0x00307, 0x01E02 },
{ 0x00042, 0x00323, 0x01E04 }, { 0x00042, 0x00331, 0x01E06 }, { 0x00043, 0x00301, 0x00106 }, { 0x00043, 0x00302, 0x00108 }, { 0x00043, 0x00307, 0x0010A },
{ 0x00043, 0x0030C, 0x0010C }, { 0x00043, 0x00327, 0x000C7 }, { 0x00044, 0x00307, 0x01E0A }, { 0x00044, 0x0030C, 0x0010E }, { 0x00044, 0x00323, 0x01E0C },
{ 0x00044, 0x00327, 0x01E10 }, { 0x00044, 0x0032D, 0x01E12 }, { 0x00044, 0x00331, 0x01E0E }, { 0x00045, 0x00300, 0x000C8 }, { 0x00045, 0x00301, 0x000C9 },
{ 0x00045, 0x00302, 0x000CA }, { 0x00045, 0x00303, 0x01EBC }, { 0x00045, 0x00304, 0x00112 }, { 0x00045, 0x00306, 0x00114 }, { 0x00045, 0x00307, 0x00116 },
{ 0x00045, 0x00308, 0x000CB }, { 0x00045, 0x00309, 0x01EBA }, { 0x00045, 0x0030C, 0x0011A }, { 0x00045, 0x0030F, 0x00204 }, { 0x00045, 0x00311, 0x00206 },
{ 0x00045, 0x00323, 0x01EB8 }, { 0x00045, 0x00327, 0x00228 }, { 0x00045, 0x00328, 0x00118 }, { 0x00045, 0x0032D, 0x01E18 }, { 0x00045, 0x00330, 0x01E1A },
{ 0x00046, 0x00307, 0x01E1E }, { 0x00047, 0x00301, 0x001F4 }, { 0x00047, 0x00302, 0x0011C }, { 0x00047, 0x00304, 0x01E20 }, { 0x00047, 0x00306, 0x0011E },
{ 0x00047, 0x00307, 0x00120 }, { 0x00047, 0x0030C, 0x001E6 }, { 0x00047, 0x00327, 0x00122 }, { 0x00048, 0x00302, 0x00124 }, { 0x00048, 0x00307, 0x01E22 },
{ 0x00048, 0x00308, 0x01E26 }, { 0x00048, 0x0030C, 0x0021E }, { 0x00048, 0x00323, 0x01E24 }, { 0x00048, 0x00327, 0x01E28 }, { 0x00048, 0x0032E, 0x01E2A },
{ 0x00049, 0x00300, 0x000CC }, { 0x00049, 0x00301, 0x000CD }, { 0x00049, 0x00302, 0x000CE }, { 0x00049, 0x00303, 0x00128 }, { 0x00049, 0x00304, 0x0012A },
{ 0x00049, 0x00306, 0x0012C }, { 0x00049, 0x00307, 0x00130 }, { 0x00049, 0x00308, 0x000CF }, { 0x00049, 0x00309, 0x01EC8 }, { 0x00049, 0x0030C, 0x001CF },
{ 0x00049, 0x0030F, 0x00208 }, { 0x00049, 0x00311, 0x0020A }, { 0x00049, 0x00323, 0x01ECA }, { 0x00049, 0x00328, 0x0012E }, { 0x00049, 0x00330, 0x01E2C },
{ 0x0004A, 0x00302, 0x00134 }, { 0x0004B, 0x00301, 0x01E30 }, { 0x0004B, 0x0030C, 0x001E8 }, { 0x0004B, 0x00323, 0x01E32 }, { 0x0004B, 0x00327, 0x00136 },
{ 0x0004B, 0x00331, 0x01E34 }, { 0x0004C, 0x00301, 0x00139 }, { 0x0004C, 0x0030C, 0x0013D }, { 0x0004C, 0x00323, 0x01E36 }, { 0x0004C, 0x00327, 0x0013B },
{ 0x0004C, 0x0032D, 0x01E3C }, { 0x0004C, 0x00331, 0x01E3A }, { 0x0004D, 0x00301, 0x01E3E }, { 0x0004D, 0x00307, 0x01E40 }, { 0x0004D, 0x00323, 0x01E42 },
{ 0x0004E, 0x00300, 0x001F8 }, { 0x0004E, 0x00301, 0x00143 }, { 0x0004E, 0x00303, 0x000D1 }, { 0x0004E, 0x00307, 0x01E44 }, { 0x0004E, 0x0030C, 0x00147 },
{ 0x0004E, 0x00323, 0x01E46 }, { 0x0004E, 0x00327, 0x00145 }, { 0x0004E, 0x0032D, 0x01E4A }, { 0x0004E, 0x00331, 0x01E48 }, { 0x0004F, 0x00300, 0x000D2 },
{ 0x0004F, 0x00301, 0x000D3 }, { 0x0004F, 0x00302, 0x000D4 }, { 0x0004F, 0x00303, 0x000D5 }, { 0x0004F, 0x00304, 0x0014C }, { 0x0004F, 0x00306, 0x0014E },
{ 0x0004F, 0x00307, 0x0022E }, { 0x0004F, 0x00308, 0x000D6 }, { 0x0004F, 0x00309, 0x01ECE }, { 0x0004F, 0x0030B, 0x00150 }, { 0x0004F, 0x0030C, 0x001D1 },
{ 0x0004F, 0x0030F, 0x0020C }, { 0x0004F, 0x00311, 0x0020E }, { 0x0004F, 0x0031B, 0x001A0 }, { 0x0004F, 0x00323, 0x01ECC }, { 0x0004F, 0x00328, 0x001EA },
{ 0x00050, 0x00301, 0x01E54 }, { 0x00050, 0x00307, 0x01E56 }, { 0x00052, 0x00301, 0x00154 }, { 0x00052, 0x00307, 0x01E58 }, { 0x00052, 0x0030C, 0x00158 },
{ 0x00052, 0x0030F, 0x00210 }, { 0x00052, 0x00311, 0x00212 }, { 0x00052, 0x00323, 0x01E5A }, { 0x00052, 0x00327, 0x00156 }, { 0x00052, 0x00331, 0x01E5E },
{ 0x00053, 0x00301, 0x0015A }, { 0x00053, 0x00302, 0x0015C }, { 0x00053, 0x00307, 0x01E60 }, { 0x00053, 0x0030C, 0x00160 }, { 0x00053, 0x00323, 0x01E62 },
{ 0x00053, 0x00326, 0x00218 }, { 0x00053, 0x00327, 0x0015E }, { 0x00054, 0x00307, 0x01E6A }, { 0x00054, 0x0030C, 0x00164 }, { 0x00054, 0x00323, 0x01E6C },
{ 0x00054, 0x00326, 0x0021A }, { 0x00054, 0x00327, 0x00162 }, { 0x00054, 0x0032D, 0x01E70 }, { 0x00054, 0x00331, 0x01E6E }, { 0x00055, 0x00300, 0x000D9 },
{ 0x00055, 0x00301, 0x000DA }, { 0x00055, 0x00302, 0x000DB }, { 0x00055, 0x00303, 0x00168 }, { 0x00055, 0x00304, 0x0016A }, { 0x00055, 0x00306, 0x0016C },
{ 0x00055, 0x00308, 0x000DC }, { 0x00055, 0x00309, 0x01EE6 }, { 0x00055, 0x0030A, 0x0016E }, { 0x00055, 0x0030B, 0x00170 }, { 0x00055, 0x0030C, 0x001D3 },
{ 0x00055, 0x0030F, 0x00214 }, { 0x00055, 0x00311, 0x00216 }, { 0x00055, 0x0031B, 0x001AF }, { 0x00055, 0x00323, 0x01EE4 }, { 0x00055, 0x00324, 0x01E72 },
{ 0x00055, 0x00328, 0x00172 }, { 0x00055, 0x0032D, 0x01E76 }, { 0x00055, 0x00330, 0x01E74 }, { 0x00056, 0x00303, 0x01E7C }, { 0x00056, 0x00323, 0x01E7E },
{ 0x00057, 0x00300, 0x01E80 }, { 0x00057, 0x00301, 0x01E82 }, { 0x00057, 0x00302, 0x00174 }, { 0x00057, 0x00307, 0x01E86 }, { 0x00057, 0x00308, 0x01E84 },
{ 0x00057, 0x00323, 0x01E88 }, { 0x00058, 0x00307, 0x01E8A }, { 0x00058, 0x00308, 0x01E8C }, { 0x00059, 0x00300, 0x01EF2 }, { 0x00059, 0x00301, 0x000DD },
{ 0x00059, 0x00302, 0x00176 }, { 0x00059, 0x00303, 0x01EF8 }, { 0x00059, 0x00304, 0x00232 }, { 0x00059, 0x00307, 0x01E8E }, { 0x00059, 0x00308, 0x00178 },
{ 0x00059, 0x00309, 0x01EF6 }, { 0x00059, 0x00323, 0x01EF4 }, { 0x0005A, 0x00301, 0x00179 }, { 0x0005A, 0x00302, 0x01E90 }, { 0x0005A, 0x00307, 0x0017B },
{ 0x0005A, 0x0030C, 0x0017D }, { 0x0005A, 0x00323, 0x01E92 }, { 0x0005A, 0x00331, 0x01E94 }, { 0x00061, 0x00300, 0x000E0 }, { 0x00061, 0x00301, 0x000E1 },
{ 0x00061, 0x00302, 0x000E2 }, { 0x00061, 0x00303, 0x000E3 }, { 0x00061, 0x00304, 0x00101 }, { 0x00061, 0x00306, 0x00103 }, { 0x00061, 0x00307, 0x00227 },
{ 0x00061, 0x00308, 0x000E4 }, { 0x00061, 0x00309, 0x01EA3 }, { 0x00061, 0x0030A, 0x000E5 }, { 0x00061, 0x0030C, 0x001CE }, { 0x00061, 0x0030F, 0x00201 },
{ 0x00061, 0x00311, 0x00203 }, { 0x00061, 0x00323, 0x01EA1 }, { 0x00061, 0x00325, 0x01E01 }, { 0x00061, 0x00328, 0x00105 }, { 0x00062, 0x00307, 0x01E03 },
{ 0x00062, 0x00323, 0x01E05 }, { 0x00062, 0x00331, 0x01E07 }, { 0x00063, 0x00301, 0x00107 }, { 0x00063, 0x00302, 0x00109 }, { 0x00063, 0x00307, 0x0010B },
{ 0x00063, 0x0030C, 0x0010D }, { 0x00063, 0x00327, 0x000E7 }, { 0x00064, 0x00307, 0x01E0B }, { 0x00064, 0x0030C, 0x0010F }, { 0x00064, 0x00323, 0x01E0D },
{ 0x00064, 0x00327, 0x01E11 }, { 0x00064, 0x0032D, 0x01E13 }, { 0x00064, 0x00331, 0x01E0F }, { 0x00065, 0x00300, 0x000E8 }, { 0x00065, 0x00301, 0x000E9 },
{ 0x00065, 0x00302, 0x000EA }, { 0x00065, 0x00303, 0x01EBD }, { 0x00065, 0x00304, 0x00113 }, { 0x00065, 0x00306, 0x00115 }, { 0x00065, 0x00307, 0x00117 },
{ 0x00065, 0x00308, 0x000EB }, { 0x00065, 0x00309, 0x01EBB }, { 0x00065, 0x0030C, 0x0011B }, { 0x00065, 0x0030F, 0x00205 }, { 0x00065, 0x00311, 0x00207 },
{ 0x00065, 0x00323, 0x01EB9 }, { 0x00065, 0x00327, 0x00229 }, { 0x00065, 0x00328, 0x00119 }, { 0x00065, 0x0032D, 0x01E19 }, { 0x00065, 0x00330, 0x01E1B },
{ 0x00066, 0x00307, 0x01E1F }, { 0x00067, 0x00301, 0x001F5 }, { 0x00067, 0x00302, 0x0011D }, { 0x00067, 0x00304, 0x01E21 }, { 0x00067, 0x00306, 0x0011F },
{ 0x00067, 0x00307, 0x00121 }, { 0x00067, 0x0030C, 0x001E7 }, { 0x00067, 0x00327, 0x00123 }, { 0x00068, 0x00302, 0x00125 }, { 0x00068, 0x00307, 0x01E23 },
{ 0x00068, 0x00308, 0x01E27 }, { 0x00068, 0x0030C, 0x0021F }, { 0x00068, 0x00323, 0x01E25 }, { 0x00068, 0x00327, 0x01E29 }, { 0x00068, 0x0032E, 0x01E2B },
{ 0x00068, 0x00331, 0x01E96 }, { 0x00069, 0x00300, 0x000EC }, { 0x00069, 0x00301, 0x000ED }, { 0x00069, 0x00302, 0x000EE }, { 0x00069, 0x00303, 0x00129 },
{ 0x00069, 0x00304, 0x0012B }, { 0x00069, 0x00306, 0x0012D }, { 0x00069, 0x00308, 0x000EF }, { 0x00069, 0x00309, 0x01EC9 }, { 0x00069, 0x0030C, 0x001D0 },
{ 0x00069, 0x0030F, 0x00209 }, { 0x00069, 0x00311, 0x0020B }, { 0x00069, 0x00323, 0x01ECB }, { 0x00069, 0x00328, 0x0012F }, { 0x00069, 0x00330, 0x01E2D },
{ 0x0006A, 0x00302, 0x00135 }, { 0x0006A, 0x0030C, 0x001F0 }, { 0x0006B, 0x00301, 0x01E31 }, { 0x0006B, 0x0030C, 0x001E9 }, { 0x0006B, 0x00323, 0x01E33 },
{ 0x0006B, 0x00327, 0x00137 }, { 0x0006B, 0x00331, 0x01E35 }, { 0x0006C, 0x00301, 0x0013A }, { 0x0006C, 0x0030C, 0x0013E }, { 0x0006C, 0x00323, 0x01E37 },
{ 0x0006C, 0x00327, 0x0013C }, { 0x0006C, 0x0032D, 0x01E3D }, { 0x0006C, 0x00331, 0x01E3B }, { 0x0006D, 0x00301, 0x01E3F }, { 0x0006D, 0x00307, 0x01E41 },
{ 0x0006D, 0x00323, 0x01E43 }, { 0x0006E, 0x00300, 0x001F9 }, { 0x0006E, 0x00301, 0x00144 }, { 0x0006E, 0x00303, 0x000F1 }, { 0x0006E, 0x00307, 0x01E45 },
{ 0x0006E, 0x0030C, 0x00148 }, { 0x0006E, 0x00323, 0x01E47 }, { 0x0006E, 0x00327, 0x00146 }, { 0x0006E, 0x0032D, 0x01E4B }, { 0x0006E, 0x00331, 0x01E49 },
{ 0x0006F, 0x00300, 0x000F2 }, { 0x0006F, 0x00301, 0x000F3 }, { 0x0006F, 0x00302, 0x000F4 }, { 0x0006F, 0x00303, 0x000F5 }, { 0x0006F, 0x00304, 0x0014D },
{ 0x0006F, 0x00306, 0x0014F }, { 0x0006F, 0x00307, 0x0022F }, { 0x0006F, 0x00308, 0x000F6 }, { 0x0006F, 0x00309, 0x01ECF }, { 0x0006F, 0x0030B, 0x00151 },
{ 0x0006F, 0x0030C, 0x001D2 }, { 0x0006F, 0x0030F, 0x0020D }, { 0x0006F, 0x00311, 0x0020F }, { 0x0006F, 0x0031B, 0x001A1 }, { 0x0006F, 0x00323, 0x01ECD },
{ 0x0006F, 0x00328, 0x001EB }, { 0x00070, 0x00301, 0x01E55 }, { 0x00070, 0x00307, 0x01E57 }, { 0x00072, 0x00301, 0x00155 }, { 0x00072, 0x00307, 0x01E59 },
{ 0x00072, 0x0030C, 0x00159 }, { 0x00072, 0x0030F, 0x00211 }, { 0x00072, 0x00311, 0x00213 }, { 0x00072, 0x00323, 0x01E5B }, { 0x00072, 0x00327, 0x00157 },
{ 0x00072, 0x00331, 0x01E5F }, { 0x00073, 0x00301, 0x0015B }, { 0x00073, 0x00302, 0x0015D }, { 0x00073, 0x00307, 0x01E61 }, { 0x00073, 0x0030C, 0x00161 },
{ 0x00073, 0x00323, 0x01E63 }, { 0x00073, 0x00326, 0x00219 }, { 0x00073, 0x00327, 0x0015F }, { 0x00074, 0x00307, 0x01E6B }, { 0x00074, 0x00308, 0x01E97 },
{ 0x00074, 0x0030C, 0x00165 }, { 0x00074, 0x00323, 0x01E6D }, { 0x00074, 0x00326, 0x0021B }, { 0x00074, 0x00327, 0x00163 }, { 0x00074, 0x0032D, 0x01E71 },
{ 0x00074, 0x00331, 0x01E6F }, { 0x00075, 0x00300, 0x000F9 }, { 0x00075, 0x00301, 0x000FA }, { 0x00075, 0x00302, 0x000FB }, { 0x00075, 0x00303, 0x00169 },
{ 0x00075, 0x00304, 0x0016B }, { 0x00075, 0x00306, 0x0016D }, { 0x00075, 0x00308, 0x000FC }, { 0x00075, 0x00309, 0x01EE7 }, { 0x00075, 0x0030A, 0x0016F },
{ 0x00075, 0x0030B, 0x00171 }, { 0x00075, 0x0030C, 0x001D4 }, { 0x00075, 0x0030F, 0x00215 }, { 0x00075, 0x00311, 0x00217 }, { 0x00075, 0x0031B, 0x001B0 },
{ 0x00075, 0x00323, 0x01EE5 }, { 0x00075, 0x00324, 0x01E73 }, { 0x00075, 0x00328, 0x00173 }, { 0x00075, 0x0032D, 0x01E77 }, { 0x00075, 0x00330, 0x01E75 },
{ 0x00076, 0x00303, 0x01E7D }, { 0x00076, 0x00323, 0x01E7F }, { 0x00077, 0x00300, 0x01E81 }, { 0x00077, 0x00301, 0x01E83 }, { 0x00077, 0x00302, 0x00175 },
{ 0x00077, 0x00307, 0x01E87 }, { 0x00077, 0x00308, 0x01E85 }, { 0x00077, 0x0030A, 0x01E98 }, { 0x00077, 0x00323, 0x01E89 }, { 0x00078, 0x00307, 0x01E8B },
{ 0x00078, 0x00308, 0x01E8D }, { 0x00079, 0x00300, 0x01EF3 }, { 0x00079, 0x00301, 0x000FD }, { 0x00079, 0x00302, 0x00177 }, { 0x00079, 0x00303, 0x01EF9 },
{ 0x00079, 0x00304, 0x00233 }, { 0x00079, 0x00307, 0x01E8F }, { 0x00079, 0x00308, 0x000FF }, { 0x00079, 0x00309, 0x01EF7 }, { 0x00079, 0x0030A, 0x01E99 },
{ 0x00079, 0x00323, 0x01EF5 }, { 0x0007A, 0x00301, 0x0017A }, { 0x0007A, 0x00302, 0x01E91 }, { 0x0007A, 0x00307, 0x0017C }, { 0x0007A, 0x0030C, 0x0017E },
{ 0x0007A, 0x00323, 0x01E93 }, { 0x0007A, 0x00331, 0x01E95 }, { 0x000A8, 0x00300, 0x01FED }, { 0x000A8, 0x00301, 0x00385 }, { 0x000A8, 0x00342, 0x01FC1 },
{ 0x000C2, 0x00300, 0x01EA6 }, { 0x000C2, 0x00301, 0x01EA4 }, { 0x000C2, 0x00303, 0x01EAA }, { 0x000C2, 0x00309, 0x01EA8 }, { 0x000C4, 0x00304, 0x001DE },
{ 0x000C5, 0x00301, 0x001FA }, { 0x000C6, 0x00301, 0x001FC }, { 0x000C6, 0x00304, 0x001E2 }, { 0x000C7, 0x00301, 0x01E08 }, { 0x000CA, 0x00300, 0x01EC0 },
{ 0x000CA, 0x00301, 0x01EBE }, { 0x000CA, 0x00303, 0x01EC4 }, { 0x000CA, 0x00309, 0x01EC2 }, { 0x000CF, 0x00301, 0x01E2E }, { 0x000D4, 0x00300, 0x01ED2 },
{ 0x000D4, 0x00301, 0x01ED0 }, { 0x000D4, 0x00303, 0x01ED6 }, { 0x000D4, 0x00309, 0x01ED4 }, { 0x000D5, 0x00301, 0x01E4C }, { 0x000D5, 0x00304, 0x0022C },
{ 0x000D5, 0x00308, 0x01E4E }, { 0x000D6, 0x00304, 0x0022A }, { 0x000D8, 0x00301, 0x001FE }, { 0x000DC, 0x00300, 0x001DB }, { 0x000DC, 0x00301, 0x001D7 },
{ 0x000DC, 0x00304, 0x001D5 }, { 0x000DC, 0x0030C, 0x001D9 }, { 0x000E2, 0x00300, 0x01EA7 }, { 0x000E2, 0x00301, 0x01EA5 }, { 0x000E2, 0x00303, 0x01EAB },
{ 0x000E2, 0x00309, 0x01EA9 }, { 0x000E4, 0x00304, 0x001DF }, { 0x000E5, 0x00301, 0x001FB }, { 0x000E6, 0x00301, 0x001FD }, { 0x000E6, 0x00304, 0x001E3 },
{ 0x000E7, 0x00301, 0x01E09 }, { 0x000EA, 0x00300, 0x01EC1 }, { 0x000EA, 0x00301, 0x01EBF }, { 0x000EA, 0x00303, 0x01EC5 }, { 0x000EA, 0x00309, 0x01EC3 },
{ 0x000EF, 0x00301, 0x01E2F }, { 0x000F4, 0x00300, 0x01ED3 }, { 0x000F4, 0x00301, 0x01ED1 }, { 0x000F4, 0x00303, 0x01ED7 }, { 0x000F4, 0x00309, 0x01ED5 },
{ 0x000F5, 0x00301, 0x01E4D }, { 0x000F5, 0x00304, 0x0022D }, { 0x000F5, 0x00308, 0x01E4F }, { 0x000F6, 0x00304, 0x0022B }, { 0x000F8, 0x00301, 0x001FF },
{ 0x000FC, 0x00300, 0x001DC }, { 0x000FC, 0x00301, 0x001D8 }, { 0x000FC, 0x00304, 0x001D6 }, { 0x000FC, 0x0030C, 0x001DA }, { 0x00102, 0x00300, 0x01EB0 },
{ 0x00102, 0x00301, 0x01EAE }, { 0x00102, 0x00303, 0x01EB4 }, { 0x00102, 0x00309, 0x01EB2 }, { 0x00103, 0x00300, 0x01EB1 }, { 0x00103, 0x00301, 0x01EAF },
{ 0x00103, 0x00303, 0x01EB5 }, { 0x00103, 0x00309, 0x01EB3 }, { 0x00112, 0x00300, 0x01E14 }, { 0x00112, 0x00301, 0x01E16 }, { 0x00113, 0x00300, 0x01E15 },
{ 0x00113, 0x00301, 0x01E17 }, { 0x0014C, 0x00300, 0x01E50 }, { 0x0014C, 0x00301, 0x01E52 }, { 0x0014D, 0x00300, 0x01E51 }, { 0x0014D, 0x00301, 0x01E53 },
{ 0x0015A, 0x00307, 0x01E64 }, { 0x0015B, 0x00307, 0x01E65 }, { 0x00160, 0x00307, 0x01E66 }, { 0x00161, 0x00307, 0x01E67 }, { 0x00168, 0x00301, 0x01E78 },
{ 0x00169, 0x00301, 0x01E79 }, { 0x0016A, 0x00308, 0x01E7A }, { 0x0016B, 0x00308, 0x01E7B }, { 0x0017F, 0x00307, 0x01E9B }, { 0x001A0, 0x00300, 0x01EDC },
{ 0x001A0, 0x00301, 0x01EDA }, { 0x001A0, 0x00303, 0x01EE0 }, { 0x001A0, 0x00309, 0x01EDE }, { 0x001A0, 0x00323, 0x01EE2 }, { 0x001A1, 0x00300, 0x01EDD },
{ 0x001A1, 0x00301, 0x01EDB }, { 0x001A1, 0x00303, 0x01EE1 }, { 0x001A1, 0x00309, 0x01EDF }, { 0x001A1, 0x00323, 0x01EE3 }, { 0x001AF, 0x00300, 0x01EEA },
{ 0x001AF, 0x00301, 0x01EE8 }, { 0x001AF, 0x00303, 0x01EEE }, { 0x001AF, 0x00309, 0x01EEC }, { 0x001AF, 0x00323, 0x01EF0 }, { 0x001B0, 0x00300, 0x01EEB },
{ 0x001B0, 0x00301, 0x01EE9 }, { 0x001B0, 0x00303, 0x01EEF }, { 0x001B0, 0x00309, 0x01EED }, { 0x001B0, 0x00323, 0x01EF1 }, { 0x001B7, 0x0030C, 0x001EE },
{ 0x001EA, 0x00304, 0x001EC }, { 0x001EB, 0x00304, 0x001ED }, { 0x00226, 0x00304, 0x001E0 }, { 0x00227, 0x00304, 0x001E1 }, { 0x00228, 0x00306, 0x01E1C },
{ 0x00229, 0x00306, 0x01E1D }, { 0x0022E, 0x00304, 0x00230 }, { 0x0022F, 0x00304, 0x00231 }, { 0x00292, 0x0030C, 0x001EF }, { 0x00391, 0x00300, 0x01FBA },
{ 0x00391, 0x00301, 0x00386 }, { 0x00391, 0x00304, 0x01FB9 }, { 0x00391, 0x00306, 0x01FB8 }, { 0x00391, 0x00313, 0x01F08 }, { 0x00391, 0x00314, 0x01F09 },
{ 0x00391, 0x00345, 0x01FBC }, { 0x00395, 0x00300, 0x01FC8 }, { 0x00395, 0x00301, 0x00388 }, { 0x00395, 0x00313, 0x01F18 }, { 0x00395, 0x00314, 0x01F19 },
{ 0x00397, 0x00300, 0x01FCA }, { 0x00397, 0x00301, 0x00389 }, { 0x00397, 0x00313, 0x01F28 }, { 0x00397, 0x00314, 0x01F29 }, { 0x00397, 0x00345, 0x01FCC },
{ 0x00399, 0x00300, 0x01FDA }, { 0x00399, 0x00301, 0x0038A }, { 0x00399, 0x00304, 0x01FD9 }, { 0x00399, 0x00306, 0x01FD8 }, { 0x00399, 0x00308, 0x003AA },
{ 0x00399, 0x00313, 0x01F38 }, { 0x00399, 0x00314, 0x01F39 }, { 0x0039F, 0x00300, 0x01FF8 }, { 0x0039F, 0x00301, 0x0038C }, { 0x0039F, 0x00313, 0x01F48 },
{ 0x0039F, 0x00314, 0x01F49 }, { 0x003A1, 0x00314, 0x01FEC }, { 0x003A5, 0x00300, 0x01FEA }, { 0x003A5, 0x00301, 0x0038E }, { 0x003A5, 0x00304, 0x01FE9 },
{ 0x003A5, 0x00306, 0x01FE8 }, { 0x003A5, 0x00308, 0x003AB }, { 0x003A5, 0x00314, 0x01F59 }, { 0x003A9, 0x00300, 0x01FFA }, { 0x003A9, 0x00301, 0x0038F },
{ 0x003A9, 0x00313, 0x01F68 }, { 0x003A9, 0x00314, 0x01F69 }, { 0x003A9, 0x00345, 0x01FFC }, { 0x003AC, 0x00345, 0x01FB4 }, { 0x003AE, 0x00345, 0x01FC4 },
{ 0x003B1, 0x00300, 0x01F70 }, { 0x003B1, 0x00301, 0x003AC }, { 0x003B1, 0x00304, 0x01FB1 }, { 0x003B1, 0x00306, 0x01FB0 }, { 0x003B1, 0x00313, 0x01F00 },
{ 0x003B1, 0x00314, 0x01F01 }, { 0x003B1, 0x00342, 0x01FB6 }, { 0x003B1, 0x00345, 0x01FB3 }, { 0x003B5, 0x00300, 0x01F72 }, { 0x003B5, 0x00301, 0x003AD },
{ 0x003B5, 0x00313, 0x01F10 }, { 0x003B5, 0x00314, 0x01F11 }, { 0x003B7, 0x00300, 0x01F74 }, { 0x003B7, 0x00301, 0x003AE }, { 0x003B7, 0x00313, 0x01F20 },
{ 0x003B7, 0x00314, 0x01F21 }, { 0x003B7, 0x00342, 0x01FC6 }, { 0x003B7, 0x00345, 0x01FC3 }, { 0x003B9, 0x00300, 0x01F76 }, { 0x003B9, 0x00301, 0x003AF },
{ 0x003B9, 0x00304, 0x01FD1 }, { 0x003B9, 0x00306, 0x01FD0 }, { 0x003B9, 0x00308, 0x003CA }, { 0x003B9, 0x00313, 0x01F30 }, { 0x003B9, 0x00314, 0x01F31 },
{ 0x003B9, 0x00342, 0x01FD6 }, { 0x003BF, 0x00300, 0x01F78 }, { 0x003BF, 0x00301, 0x003CC }, { 0x003BF, 0x00313, 0x01F40 }, { 0x003BF, 0x00314, 0x01F41 },
{ 0x003C1, 0x00313, 0x01FE4 }, { 0x003C1, 0x00314, 0x01FE5 }, { 0x003C5, 0x00300, 0x01F7A }, { 0x003C5, 0x00301, 0x003CD }, { 0x003C5, 0x00304, 0x01FE1 },
{ 0x003C5, 0x00306, 0x01FE0 }, { 0x003C5, 0x00308, 0x003CB }, { 0x003C5, 0x00313, 0x01F50 }, { 0x003C5, 0x00314, 0x01F51 }, { 0x003C5, 0x00342, 0x01FE6 },
{ 0x003C9, 0x00300, 0x01F7C }, { 0x003C9, 0x00301, 0x003CE }, { 0x003C9, 0x00313, 0x01F60 }, { 0x003C9, 0x00314, 0x01F61 }, { 0x003C9, 0x00342, 0x01FF6 },
{ 0x003C9, 0x00345, 0x01FF3 }, { 0x003CA, 0x00300, 0x01FD2 }, { 0x003CA, 0x00301, 0x00390 }, { 0x003CA, 0x00342, 0x01FD7 }, { 0x003CB, 0x00300, 0x01FE2 },
{ 0x003CB, 0x00301, 0x003B0 }, { 0x003CB, 0x00342, 0x01FE7 }, { 0x003CE, 0x00345, 0x01FF4 }, { 0x003D2, 0x00301, 0x003D3 }, { 0x003D2, 0x00308, 0x003D4 },
{ 0x00406, 0x00308, 0x00407 }, { 0x00410, 0x00306, 0x004D0 }, { 0x00410, 0x00308, 0x004D2 }, { 0x00413, 0x00301, 0x00403 }, { 0x00415, 0x00300, 0x00400 },
{ 0x00415, 0x00306, 0x004D6 }, { 0x00415, 0x00308, 0x00401 }, { 0x00416, 0x00306, 0x004C1 }, { 0x00416, 0x00308, 0x004DC }, { 0x00417, 0x00308, 0x004DE },
{ 0x00418, 0x00300, 0x0040D }, { 0x00418, 0x00304, 0x004E2 }, { 0x00418, 0x00306, 0x00419 }, { 0x00418, 0x00308, 0x004E4 }, { 0x0041A, 0x00301, 0x0040C },
{ 0x0041E, 0x00308, 0x004E6 }, { 0x00423, 0x00304, 0x004EE }, { 0x00423, 0x00306, 0x0040E }, { 0x00423, 0x00308, 0x004F0 }, { 0x00423, 0x0030B, 0x004F2 },
{ 0x00427, 0x00308, 0x004F4 }, { 0x0042B, 0x00308, 0x004F8 }, { 0x0042D, 0x00308, 0x004EC }, { 0x00430, 0x00306, 0x004D1 }, { 0x00430, 0x00308, 0x004D3 },
{ 0x00433, 0x00301, 0x00453 }, { 0x00435, 0x00300, 0x00450 }, { 0x00435, 0x00306, 0x004D7 }, { 0x00435, 0x00308, 0x00451 }, { 0x00436, 0x00306, 0x004C2 },
{ 0x00436, 0x00308, 0x004DD }, { 0x00437, 0x00308, 0x004DF }, { 0x00438, 0x00300, 0x0045D }, { 0x00438, 0x00304, 0x004E3 }, { 0x00438, 0x00306, 0x00439 },
{ 0x00438, 0x00308, 0x004E5 }, { 0x0043A, 0x00301, 0x0045C }, { 0x0043E, 0x00308, 0x004E7 }, { 0x00443, 0x00304, 0x004EF }, { 0x00443, 0x00306, 0x0045E },
{ 0x00443, 0x00308, 0x004F1 }, { 0x00443, 0x0030B, 0x004F3 }, { 0x00447, 0x00308, 0x004F5 }, { 0x0044B, 0x00308, 0x004F9 }, { 0x0044D, 0x00308, 0x004ED },
{ 0x00456, 0x00308, 0x00457 }, { 0x00474, 0x0030F, 0x00476 }, { 0x00475, 0x0030F, 0x00477 }, { 0x004D8, 0x00308, 0x004DA }, { 0x004D9, 0x00308, 0x004DB },
{ 0x004E8, 0x00308, 0x004EA }, { 0x004E9, 0x00308, 0x004EB }, { 0x00627, 0x00653, 0x00622 }, { 0x00627, 0x00654, 0x00623 }, { 0x00627, 0x00655, 0x00625 },
{ 0x00648, 0x00654, 0x00624 }, { 0x0064A, 0x00654, 0x00626 }, { 0x006C1, 0x00654, 0x006C2 }, { 0x006D2, 0x00654, 0x006D3 }, { 0x006D5, 0x00654, 0x006C0 },
{ 0x00928, 0x0093C, 0x00929 }, { 0x00930, 0x0093C, 0x00931 }, { 0x00933, 0x0093C, 0x00934 }, { 0x009C7, 0x009BE, 0x009CB }, { 0x009C7, 0x009D7, 0x009CC },
{ 0x00B47, 0x00B3E, 0x00B4B }, { 0x00B47, 0x00B56, 0x00B48 }, { 0x00B47, 0x00B57, 0x00B4C }, { 0x00B92, 0x00BD7, 0x00B94 }, { 0x00BC6, 0x00BBE, 0x00BCA },
{ 0x00BC6, 0x00BD7, 0x00BCC }, { 0x00BC7, 0x00BBE, 0x00BCB }, { 0x00C46, 0x00C56, 0x00C48 }, { 0x00CBF, 0x00CD5, 0x00CC0 }, { 0x00CC6, 0x00CC2, 0x00CCA },
{ 0x00CC6, 0x00CD5, 0x00CC7 }, { 0x00CC6, 0x00CD6, 0x00CC8 }, { 0x00CCA, 0x00CD5, 0x00CCB }, { 0x00D46, 0x00D3E, 0x00D4A }, { 0x00D46, 0x00D57, 0x00D4C },
{ 0x00D47, 0x00D3E, 0x00D4B }, { 0x00DD9, 0x00DCA, 0x00DDA }, { 0x00DD9, 0x00DCF, 0x00DDC }, { 0x00DD9, 0x00DDF, 0x00DDE }, { 0x00DDC, 0x00DCA, 0x00DDD },
{ 0x01025, 0x0102E, 0x01026 }, { 0x01E36, 0x00304, 0x01E38 }, { 0x01E37, 0x00304, 0x01E39 }, { 0x01E5A, 0x00304, 0x01E5C }, { 0x01E5B, 0x00304, 0x01E5D },
{ 0x01E62, 0x00307, 0x01E68 }, { 0x01E63, 0x00307, 0x01E69 }, { 0x01EA0, 0x00302, 0x01EAC }, { 0x01EA0, 0x00306, 0x01EB6 }, { 0x01EA1, 0x00302, 0x01EAD },
{ 0x01EA1, 0x00306, 0x01EB7 }, { 0x01EB8, 0x00302, 0x01EC6 }, { 0x01EB9, 0x00302, 0x01EC7 }, { 0x01ECC, 0x00302, 0x01ED8 }, { 0x01ECD, 0x00302, 0x01ED9 },
{ 0x01F00, 0x00300, 0x01F02 }, { 0x01F00, 0x00301, 0x01F04 }, { 0x01F00, 0x00342, 0x01F06 }, { 0x01F00, 0x00345, 0x01F80 }, { 0x01F01, 0x00300, 0x01F03 },
{ 0x01F01, 0x00301, 0x01F05 }, { 0x01F01, 0x00342, 0x01F07 }, { 0x01F01, 0x00345, 0x01F81 }, { 0x01F02, 0x00345, 0x01F82 }, { 0x01F03, 0x00345, 0x01F83 },
{ 0x01F04, 0x00345, 0x01F84 }, { 0x01F05, 0x00345, 0x01F85 }, { 0x01F06, 0x00345, 0x01F86 }, { 0x01F07, 0x00345, 0x01F87 }, { 0x01F08, 0x00300, 0x01F0A },
{ 0x01F08, 0x00301, 0x01F0C }, { 0x01F08, 0x00342, 0x01F0E }, { 0x01F08, 0x00345, 0x01F88 }, { 0x01F09, 0x00300, 0x01F0B }, { 0x01F09, 0x00301, 0x01F0D },
{ 0x01F09, 0x00342, 0x01F0F }, { 0x01F09, 0x00345, 0x01F89 }, { 0x01F0A, 0x00345, 0x01F8A }, { 0x01F0B, 0x00345, 0x01F8B }, { 0x01F0C, 0x00345, 0x01F8C },
{ 0x01F0D, 0x00345, 0x01F8D }, { 0x01F0E, 0x00345, 0x01F8E }, { 0x01F0F, 0x00345, 0x01F8F }, { 0x01F10, 0x00300, 0x01F12 }, { 0x01F10, 0x00301, 0x01F14 },
{ 0x01F11, 0x00300, 0x01F13 }, { 0x01F11, 0x00301, 0x01F15 }, { 0x01F18, 0x00300, 0x01F1A }, { 0x01F18, 0x00301, 0x01F1C }, { 0x01F19, 0x00300, 0x01F1B },
{ 0x01F19, 0x00301, 0x01F1D }, { 0x01F20, 0x00300, 0x01F22 }, { 0x01F20, 0x00301, 0x01F24 }, { 0x01F20, 0x00342, 0x01F26 }, { 0x01F20, 0x00345, 0x01F90 },
{ 0x01F21, 0x00300, 0x01F23 }, { 0x01F21, 0x00301, 0x01F25 }, { 0x01F21, 0x00342, 0x01F27 }, { 0x01F21, 0x00345, 0x01F91 }, { 0x01F22, 0x00345, 0x01F92 },
{ 0x01F23, 0x00345, 0x01F93 }, { 0x01F24, 0x00345, 0x01F94 }, { 0x01F25, 0x00345, 0x01F95 }, { 0x01F26, 0x00345, 0x01F96 }, { 0x01F27, 0x00345, 0x01F97 },
{ 0x01F28, 0x00300, 0x01F2A }, { 0x01F28, 0x00301, 0x01F2C }, { 0x01F28, 0x00342, 0x01F2E }, { 0x01F28, 0x00345, 0x01F98 }, { 0x01F29, 0x00300, 0x01F2B },
{ 0x01F29, 0x00301, 0x01F2D }, { 0x01F29, 0x00342, 0x01F2F }, { 0x01F29, 0x00345, 0x01F99 }, { 0x01F2A, 0x00345, 0x01F9A }, { 0x01F2B, 0x00345, 0x01F9B },
{ 0x01F2C, 0x00345, 0x01F9C }, { 0x01F2D, 0x00345, 0x01F9D }, { 0x01F2E, 0x00345, 0x01F9E }, { 0x01F2F, 0x00345, 0x01F9F }, { 0x01F30, 0x00300, 0x01F32 },
{ 0x01F30, 0x00301, 0x01F34 }, { 0x01F30, 0x00342, 0x01F36 }, { 0x01F31, 0x00300, 0x01F33 }, { 0x01F31, 0x00301, 0x01F35 }, { 0x01F31, 0x00342, 0x01F37 },
{ 0x01F38, 0x00300, 0x01F3A }, { 0x01F38, 0x00301, 0x01F3C }, { 0x01F38, 0x00342, 0x01F3E }, { 0x01F39, 0x00300, 0x01F3B }, { 0x01F39, 0x00301, 0x01F3D },
{ 0x01F39, 0x00342, 0x01F3F }, { 0x01F40, 0x00300, 0x01F42 }, { 0x01F40, 0x00301, 0x01F44 }, { 0x01F41, 0x00300, 0x01F43 }, { 0x01F41, 0x00301, 0x01F45 },
{ 0x01F48, 0x00300, 0x01F4A }, { 0x01F48, 0x00301, 0x01F4C }, { 0x01F49, 0x00300, 0x01F4B }, { 0x01F49, 0x00301, 0x01F4D }, { 0x01F50, 0x00300, 0x01F52 },
{ 0x01F50, 0x00301, 0x01F54 }, { 0x01F50, 0x00342, 0x01F56 }, { 0x01F51, 0x00300, 0x01F53 }, { 0x01F51, 0x00301, 0x01F55 }, { 0x01F51, 0x00342, 0x01F57 },
{ 0x01F59, 0x00300, 0x01F5B }, { 0x01F59, 0x00301, 0x01F5D }, { 0x01F59, 0x00342, 0x01F5F }, { 0x01F60, 0x00300, 0x01F62 }, { 0x01F60, 0x00301, 0x01F64 },
{ 0x01F60, 0x00342, 0x01F66 }, { 0x01F60, 0x00345, 0x01FA0 }, { 0x01F61, 0x00300, 0x01F63 }, { 0x01F61, 0x00301, 0x01F65 }, { 0x01F61, 0x00342, 0x01F67 },
{ 0x01F61, 0x00345, 0x01FA1 }, { 0x01F62, 0x00345, 0x01FA2 }, { 0x01F63, 0x00345, 0x01FA3 }, { 0x01F64, 0x00345, 0x01FA4 }, { 0x01F65, 0x00345, 0x01FA5 },
{ 0x01F66, 0x00345, 0x01FA6 }, { 0x01F67, 0x00345, 0x01FA7 }, { 0x01F68, 0x00300, 0x01F6A }, { 0x01F68, 0x00301, 0x01F6C }, { 0x01F68, 0x00342, 0x01F6E },
{ 0x01F68, 0x00345, 0x01FA8 }, { 0x01F69, 0x00300, 0x01F6B }, { 0x01F69, 0x00301, 0x01F6D }, { 0x01F69, 0x00342, 0x01F6F }, { 0x01F69, 0x00345, 0x01FA9 },
{ 0x01F6A, 0x00345, 0x01FAA }, { 0x01F6B, 0x00345, 0x01FAB }, { 0x01F6C, 0x00345, 0x01FAC }, { 0x01F6D, 0x00345, 0x01FAD }, { 0x01F6E, 0x00345, 0x01FAE },
{ 0x01F6F, 0x00345, 0x01FAF }, { 0x01F70, 0x00345, 0x01FB2 }, { 0x01F74, 0x00345, 0x01FC2 }, { 0x01F7C, 0x00345, 0x01FF2 }, { 0x01FB6, 0x00345, 0x01FB7 },
{ 0x01FBF, 0x00300, 0x01FCD }, { 0x01FBF, 0x00301, 0x01FCE }, { 0x01FBF, 0x00342, 0x01FCF }, { 0x01FC6, 0x00345, 0x01FC7 }, { 0x01FF6, 0x00345, 0x01FF7 },
{ 0x01FFE, 0x00300, 0x01FDD }, { 0x01FFE, 0x00301, 0x01FDE }, { 0x01FFE, 0x00342, 0x01FDF }, { 0x02190, 0x00338, 0x0219A }, { 0x02192, 0x00338, 0x0219B },
{ 0x02194, 0x00338, 0x021AE }, { 0x021D0, 0x00338, 0x021CD }, { 0x021D2, 0x00338, 0x021CF }, { 0x021D4, 0x00338, 0x021CE }, { 0x02203, 0x00338, 0x02204 },
{ 0x02208, 0x00338, 0x02209 }, { 0x0220B, 0x00338, 0x0220C }, { 0x02223, 0x00338, 0x02224 }, { 0x02225, 0x00338, 0x02226 }, { 0x0223C, 0x00338, 0x02241 },
{ 0x02243, 0x00338, 0x02244 }, { 0x02245, 0x00338, 0x02247 }, { 0x02248, 0x00338, 0x02249 }, { 0x0224D, 0x00338, 0x0226D }, { 0x02261, 0x00338, 0x02262 },
{ 0x02264, 0x00338, 0x02270 }, { 0x02265, 0x00338, 0x02271 }, { 0x02272, 0x00338, 0x02274 }, { 0x02273, 0x00338, 0x02275 }, { 0x02276, 0x00338, 0x02278 },
{ 0x02277, 0x00338, 0x02279 }, { 0x0227A, 0x00338, 0x02280 }, { 0x0227B, 0x00338, 0x02281 }, { 0x0227C, 0x00338, 0x022E0 }, { 0x0227D, 0x00338, 0x022E1 },
{ 0x02282, 0x00338, 0x02284 }, { 0x02283, 0x00338, 0x02285 }, { 0x02286, 0x00338, 0x02288 }, { 0x02287, 0x00338, 0x02289 }, { 0x02291, 0x00338, 0x022E2 },
{ 0x02292, 0x00338, 0x022E3 }, { 0x022A2, 0x00338, 0x022AC }, { 0x022A8, 0x00338, 0x022AD }, { 0x022A9, 0x00338, 0x022AE }, { 0x022AB, 0x00338, 0x022AF },
{ 0x022B2, 0x00338, 0x022EA }, { 0x022B3, 0x00338, 0x022EB }, { 0x022B4, 0x00338, 0x022EC }, { 0x022B5, 0x00338, 0x022ED }, { 0x03046, 0x03099, 0x03094 },
{ 0x0304B, 0x03099, 0x0304C }, { 0x0304D, 0x03099, 0x0304E }, { 0x0304F, 0x03099, 0x03050 }, { 0x03051, 0x03099, 0x03052 }, { 0x03053, 0x03099, 0x03054 },
{ 0x03055, 0x03099, 0x03056 }, { 0x03057, 0x03099, 0x03058 }, { 0x03059, 0x03099, 0x0305A }, { 0x0305B, 0x03099, 0x0305C }, { 0x0305D, 0x03099, 0x0305E },
{ 0x0305F, 0x03099, 0x03060 }, { 0x03061, 0x03099, 0x03062 }, { 0x03064, 0x03099, 0x03065 }, { 0x03066, 0x03099, 0x03067 }, { 0x03068, 0x03099, 0x03069 },
{ 0x0306F, 0x03099, 0x03070 }, { 0x0306F, 0x0309A, 0x03071 }, { 0x03072, 0x03099, 0x03073 }, { 0x03072, 0x0309A, 0x03074 }, { 0x03075, 0x03099, 0x03076 },
{ 0x03075, 0x0309A, 0x03077 }, { 0x03078, 0x03099, 0x03079 }, { 0x03078, 0x0309A, 0x0307A }, { 0x0307B, 0x03099, 0x0307C }, { 0x0307B, 0x0309A, 0x0307D },
{ 0x0309D, 0x03099, 0x0309E }, { 0x030A6, 0x03099, 0x030F4 }, { 0x030AB, 0x03099, 0x030AC }, { 0x030AD, 0x03099, 0x030AE }, { 0x030AF, 0x03099, 0x030B0 },
{ 0x030B1, 0x03099, 0x030B2 }, { 0x030B3, 0x03099, 0x030B4 }, { 0x030B5, 0x03099, 0x030B6 }, { 0x030B7, 0x03099, 0x030B8 }, { 0x030B9, 0x03099, 0x030BA },
{ 0x030BB, 0x03099, 0x030BC }, { 0x030BD, 0x03099, 0x030BE }, { 0x030BF, 0x03099, 0x030C0 }, { 0x030C1, 0x03099, 0x030C2 }, { 0x030C4, 0x03099, 0x030C5 },
{ 0x030C6, 0x03099, 0x030C7 }, { 0x030C8, 0x03099, 0x030C9 }, { 0x030CF, 0x03099, 0x030D0 }, { 0x030CF, 0x0309A, 0x030D1 }, { 0x030D2, 0x03099, 0x030D3 },
{ 0x030D2, 0x0309A, 0x030D4 }, { 0x030D5, 0x03099, 0x030D6 }, { 0x030D5, 0x0309A, 0x030D7 }, { 0x030D8, 0x03099, 0x030D9 }, { 0x030D8, 0x0309A, 0x030DA },
{ 0x030DB, 0x03099, 0x030DC }, { 0x030DB, 0x0309A, 0x030DD }, { 0x030EF, 0x03099, 0x030F7 }, { 0x030F0, 0x03099, 0x030F8 }, { 0x030F1, 0x03099, 0x030F9 },
{ 0x030F2, 0x03099, 0x030FA }, { 0x030FD, 0x03099, 0x030FE }
};

unsigned int NormalizeTransform::getComposition(unsigned int first, unsigned int second)
{
  // Binary search in the g_composeTable table
  unsigned int min = 0;
  unsigned int max = composeTableSize;
  unsigned int middle;
  int cmp;

  while(min < max) {
    middle = (max + min) >> 1;

    cmp = composeTable[middle].ch1 - first;
    if(cmp == 0)
      cmp = composeTable[middle].ch2 - second;

    if(cmp > 0) max = middle;
    else if(cmp < 0) {
      min = middle + 1;
    }
    else {
      return composeTable[middle].dest;
    }
  }

  return NO_COMPOSITION;
}

struct CanonicalCombiningClassValue
{
  unsigned int ch;
  unsigned int clas;
};
unsigned int canonicalCombiningClassTableSize = 384;
CanonicalCombiningClassValue canonicalCombiningClassTable[384] = {
{ 0x00300, 0xE6 }, { 0x00301, 0xE6 }, { 0x00302, 0xE6 }, { 0x00303, 0xE6 }, { 0x00304, 0xE6 }, { 0x00305, 0xE6 }, { 0x00306, 0xE6 }, { 0x00307, 0xE6 },
{ 0x00308, 0xE6 }, { 0x00309, 0xE6 }, { 0x0030A, 0xE6 }, { 0x0030B, 0xE6 }, { 0x0030C, 0xE6 }, { 0x0030D, 0xE6 }, { 0x0030E, 0xE6 }, { 0x0030F, 0xE6 },
{ 0x00310, 0xE6 }, { 0x00311, 0xE6 }, { 0x00312, 0xE6 }, { 0x00313, 0xE6 }, { 0x00314, 0xE6 }, { 0x00315, 0xE8 }, { 0x00316, 0xDC }, { 0x00317, 0xDC },
{ 0x00318, 0xDC }, { 0x00319, 0xDC }, { 0x0031A, 0xE8 }, { 0x0031B, 0xD8 }, { 0x0031C, 0xDC }, { 0x0031D, 0xDC }, { 0x0031E, 0xDC }, { 0x0031F, 0xDC },
{ 0x00320, 0xDC }, { 0x00321, 0xCA }, { 0x00322, 0xCA }, { 0x00323, 0xDC }, { 0x00324, 0xDC }, { 0x00325, 0xDC }, { 0x00326, 0xDC }, { 0x00327, 0xCA },
{ 0x00328, 0xCA }, { 0x00329, 0xDC }, { 0x0032A, 0xDC }, { 0x0032B, 0xDC }, { 0x0032C, 0xDC }, { 0x0032D, 0xDC }, { 0x0032E, 0xDC }, { 0x0032F, 0xDC },
{ 0x00330, 0xDC }, { 0x00331, 0xDC }, { 0x00332, 0xDC }, { 0x00333, 0xDC }, { 0x00334, 0x01 }, { 0x00335, 0x01 }, { 0x00336, 0x01 }, { 0x00337, 0x01 },
{ 0x00338, 0x01 }, { 0x00339, 0xDC }, { 0x0033A, 0xDC }, { 0x0033B, 0xDC }, { 0x0033C, 0xDC }, { 0x0033D, 0xE6 }, { 0x0033E, 0xE6 }, { 0x0033F, 0xE6 },
{ 0x00340, 0xE6 }, { 0x00341, 0xE6 }, { 0x00342, 0xE6 }, { 0x00343, 0xE6 }, { 0x00344, 0xE6 }, { 0x00345, 0xF0 }, { 0x00346, 0xE6 }, { 0x00347, 0xDC },
{ 0x00348, 0xDC }, { 0x00349, 0xDC }, { 0x0034A, 0xE6 }, { 0x0034B, 0xE6 }, { 0x0034C, 0xE6 }, { 0x0034D, 0xDC }, { 0x0034E, 0xDC }, { 0x00350, 0xE6 },
{ 0x00351, 0xE6 }, { 0x00352, 0xE6 }, { 0x00353, 0xDC }, { 0x00354, 0xDC }, { 0x00355, 0xDC }, { 0x00356, 0xDC }, { 0x00357, 0xE6 }, { 0x00358, 0xE8 },
{ 0x00359, 0xDC }, { 0x0035A, 0xDC }, { 0x0035B, 0xE6 }, { 0x0035C, 0xE9 }, { 0x0035D, 0xEA }, { 0x0035E, 0xEA }, { 0x0035F, 0xE9 }, { 0x00360, 0xEA },
{ 0x00361, 0xEA }, { 0x00362, 0xE9 }, { 0x00363, 0xE6 }, { 0x00364, 0xE6 }, { 0x00365, 0xE6 }, { 0x00366, 0xE6 }, { 0x00367, 0xE6 }, { 0x00368, 0xE6 },
{ 0x00369, 0xE6 }, { 0x0036A, 0xE6 }, { 0x0036B, 0xE6 }, { 0x0036C, 0xE6 }, { 0x0036D, 0xE6 }, { 0x0036E, 0xE6 }, { 0x0036F, 0xE6 }, { 0x00483, 0xE6 },
{ 0x00484, 0xE6 }, { 0x00485, 0xE6 }, { 0x00486, 0xE6 }, { 0x00591, 0xDC }, { 0x00592, 0xE6 }, { 0x00593, 0xE6 }, { 0x00594, 0xE6 }, { 0x00595, 0xE6 },
{ 0x00596, 0xDC }, { 0x00597, 0xE6 }, { 0x00598, 0xE6 }, { 0x00599, 0xE6 }, { 0x0059A, 0xDE }, { 0x0059B, 0xDC }, { 0x0059C, 0xE6 }, { 0x0059D, 0xE6 },
{ 0x0059E, 0xE6 }, { 0x0059F, 0xE6 }, { 0x005A0, 0xE6 }, { 0x005A1, 0xE6 }, { 0x005A2, 0xDC }, { 0x005A3, 0xDC }, { 0x005A4, 0xDC }, { 0x005A5, 0xDC },
{ 0x005A6, 0xDC }, { 0x005A7, 0xDC }, { 0x005A8, 0xE6 }, { 0x005A9, 0xE6 }, { 0x005AA, 0xDC }, { 0x005AB, 0xE6 }, { 0x005AC, 0xE6 }, { 0x005AD, 0xDE },
{ 0x005AE, 0xE4 }, { 0x005AF, 0xE6 }, { 0x005B0, 0x0A }, { 0x005B1, 0x0B }, { 0x005B2, 0x0C }, { 0x005B3, 0x0D }, { 0x005B4, 0x0E }, { 0x005B5, 0x0F },
{ 0x005B6, 0x10 }, { 0x005B7, 0x11 }, { 0x005B8, 0x12 }, { 0x005B9, 0x13 }, { 0x005BB, 0x14 }, { 0x005BC, 0x15 }, { 0x005BD, 0x16 }, { 0x005BF, 0x17 },
{ 0x005C1, 0x18 }, { 0x005C2, 0x19 }, { 0x005C4, 0xE6 }, { 0x005C5, 0xDC }, { 0x005C7, 0x12 }, { 0x00610, 0xE6 }, { 0x00611, 0xE6 }, { 0x00612, 0xE6 },
{ 0x00613, 0xE6 }, { 0x00614, 0xE6 }, { 0x00615, 0xE6 }, { 0x0064B, 0x1B }, { 0x0064C, 0x1C }, { 0x0064D, 0x1D }, { 0x0064E, 0x1E }, { 0x0064F, 0x1F },
{ 0x00650, 0x20 }, { 0x00651, 0x21 }, { 0x00652, 0x22 }, { 0x00653, 0xE6 }, { 0x00654, 0xE6 }, { 0x00655, 0xDC }, { 0x00656, 0xDC }, { 0x00657, 0xE6 },
{ 0x00658, 0xE6 }, { 0x00659, 0xE6 }, { 0x0065A, 0xE6 }, { 0x0065B, 0xE6 }, { 0x0065C, 0xDC }, { 0x0065D, 0xE6 }, { 0x0065E, 0xE6 }, { 0x00670, 0x23 },
{ 0x006D6, 0xE6 }, { 0x006D7, 0xE6 }, { 0x006D8, 0xE6 }, { 0x006D9, 0xE6 }, { 0x006DA, 0xE6 }, { 0x006DB, 0xE6 }, { 0x006DC, 0xE6 }, { 0x006DF, 0xE6 },
{ 0x006E0, 0xE6 }, { 0x006E1, 0xE6 }, { 0x006E2, 0xE6 }, { 0x006E3, 0xDC }, { 0x006E4, 0xE6 }, { 0x006E7, 0xE6 }, { 0x006E8, 0xE6 }, { 0x006EA, 0xDC },
{ 0x006EB, 0xE6 }, { 0x006EC, 0xE6 }, { 0x006ED, 0xDC }, { 0x00711, 0x24 }, { 0x00730, 0xE6 }, { 0x00731, 0xDC }, { 0x00732, 0xE6 }, { 0x00733, 0xE6 },
{ 0x00734, 0xDC }, { 0x00735, 0xE6 }, { 0x00736, 0xE6 }, { 0x00737, 0xDC }, { 0x00738, 0xDC }, { 0x00739, 0xDC }, { 0x0073A, 0xE6 }, { 0x0073B, 0xDC },
{ 0x0073C, 0xDC }, { 0x0073D, 0xE6 }, { 0x0073E, 0xDC }, { 0x0073F, 0xE6 }, { 0x00740, 0xE6 }, { 0x00741, 0xE6 }, { 0x00742, 0xDC }, { 0x00743, 0xE6 },
{ 0x00744, 0xDC }, { 0x00745, 0xE6 }, { 0x00746, 0xDC }, { 0x00747, 0xE6 }, { 0x00748, 0xDC }, { 0x00749, 0xE6 }, { 0x0074A, 0xE6 }, { 0x0093C, 0x07 },
{ 0x0094D, 0x09 }, { 0x00951, 0xE6 }, { 0x00952, 0xDC }, { 0x00953, 0xE6 }, { 0x00954, 0xE6 }, { 0x009BC, 0x07 }, { 0x009CD, 0x09 }, { 0x00A3C, 0x07 },
{ 0x00A4D, 0x09 }, { 0x00ABC, 0x07 }, { 0x00ACD, 0x09 }, { 0x00B3C, 0x07 }, { 0x00B4D, 0x09 }, { 0x00BCD, 0x09 }, { 0x00C4D, 0x09 }, { 0x00C55, 0x54 },
{ 0x00C56, 0x5B }, { 0x00CBC, 0x07 }, { 0x00CCD, 0x09 }, { 0x00D4D, 0x09 }, { 0x00DCA, 0x09 }, { 0x00E38, 0x67 }, { 0x00E39, 0x67 }, { 0x00E3A, 0x09 },
{ 0x00E48, 0x6B }, { 0x00E49, 0x6B }, { 0x00E4A, 0x6B }, { 0x00E4B, 0x6B }, { 0x00EB8, 0x76 }, { 0x00EB9, 0x76 }, { 0x00EC8, 0x7A }, { 0x00EC9, 0x7A },
{ 0x00ECA, 0x7A }, { 0x00ECB, 0x7A }, { 0x00F18, 0xDC }, { 0x00F19, 0xDC }, { 0x00F35, 0xDC }, { 0x00F37, 0xDC }, { 0x00F39, 0xD8 }, { 0x00F71, 0x81 },
{ 0x00F72, 0x82 }, { 0x00F74, 0x84 }, { 0x00F7A, 0x82 }, { 0x00F7B, 0x82 }, { 0x00F7C, 0x82 }, { 0x00F7D, 0x82 }, { 0x00F80, 0x82 }, { 0x00F82, 0xE6 },
{ 0x00F83, 0xE6 }, { 0x00F84, 0x09 }, { 0x00F86, 0xE6 }, { 0x00F87, 0xE6 }, { 0x00FC6, 0xDC }, { 0x01037, 0x07 }, { 0x01039, 0x09 }, { 0x0135F, 0xE6 },
{ 0x01714, 0x09 }, { 0x01734, 0x09 }, { 0x017D2, 0x09 }, { 0x017DD, 0xE6 }, { 0x018A9, 0xE4 }, { 0x01939, 0xDE }, { 0x0193A, 0xE6 }, { 0x0193B, 0xDC },
{ 0x01A17, 0xE6 }, { 0x01A18, 0xDC }, { 0x01DC0, 0xE6 }, { 0x01DC1, 0xE6 }, { 0x01DC2, 0xDC }, { 0x01DC3, 0xE6 }, { 0x020D0, 0xE6 }, { 0x020D1, 0xE6 },
{ 0x020D2, 0x01 }, { 0x020D3, 0x01 }, { 0x020D4, 0xE6 }, { 0x020D5, 0xE6 }, { 0x020D6, 0xE6 }, { 0x020D7, 0xE6 }, { 0x020D8, 0x01 }, { 0x020D9, 0x01 },
{ 0x020DA, 0x01 }, { 0x020DB, 0xE6 }, { 0x020DC, 0xE6 }, { 0x020E1, 0xE6 }, { 0x020E5, 0x01 }, { 0x020E6, 0x01 }, { 0x020E7, 0xE6 }, { 0x020E8, 0xDC },
{ 0x020E9, 0xE6 }, { 0x020EA, 0x01 }, { 0x020EB, 0x01 }, { 0x0302A, 0xDA }, { 0x0302B, 0xE4 }, { 0x0302C, 0xE8 }, { 0x0302D, 0xDE }, { 0x0302E, 0xE0 },
{ 0x0302F, 0xE0 }, { 0x03099, 0x08 }, { 0x0309A, 0x08 }, { 0x0A806, 0x09 }, { 0x0FB1E, 0x1A }, { 0x0FE20, 0xE6 }, { 0x0FE21, 0xE6 }, { 0x0FE22, 0xE6 },
{ 0x0FE23, 0xE6 }, { 0x10A0D, 0xDC }, { 0x10A0F, 0xE6 }, { 0x10A38, 0xE6 }, { 0x10A39, 0x01 }, { 0x10A3A, 0xDC }, { 0x10A3F, 0x09 }, { 0x1D165, 0xD8 },
{ 0x1D166, 0xD8 }, { 0x1D167, 0x01 }, { 0x1D168, 0x01 }, { 0x1D169, 0x01 }, { 0x1D16D, 0xE2 }, { 0x1D16E, 0xD8 }, { 0x1D16F, 0xD8 }, { 0x1D170, 0xD8 },
{ 0x1D171, 0xD8 }, { 0x1D172, 0xD8 }, { 0x1D17B, 0xDC }, { 0x1D17C, 0xDC }, { 0x1D17D, 0xDC }, { 0x1D17E, 0xDC }, { 0x1D17F, 0xDC }, { 0x1D180, 0xDC },
{ 0x1D181, 0xDC }, { 0x1D182, 0xDC }, { 0x1D185, 0xE6 }, { 0x1D186, 0xE6 }, { 0x1D187, 0xE6 }, { 0x1D188, 0xE6 }, { 0x1D189, 0xE6 }, { 0x1D18A, 0xDC },
{ 0x1D18B, 0xDC }, { 0x1D1AA, 0xE6 }, { 0x1D1AB, 0xE6 }, { 0x1D1AC, 0xE6 }, { 0x1D1AD, 0xE6 }, { 0x1D242, 0xE6 }, { 0x1D243, 0xE6 }, { 0x1D244, 0xE6 }
};

unsigned int NormalizeTransform::getCanonicalCombiningClass(unsigned int ch)
{
  if(ch < 0x300) {
    return 0;
  }

  // Binary search in the canonicalCombiningClassTable table
  unsigned int min = 0;
  unsigned int max = canonicalCombiningClassTableSize;
  unsigned int middle;
  int cmp;

  while(min < max) {
    middle = (max + min) >> 1;

    cmp = canonicalCombiningClassTable[middle].ch - ch;
    if(cmp > 0) max = middle;
    else if(cmp < 0) {
      min = middle + 1;
    }
    else {
      return canonicalCombiningClassTable[middle].clas;
    }
  }

  return 0;
}
