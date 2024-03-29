/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "pql_eval.hpp"

/////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
TEST(module_ppn_node_rdb, pql_eval_bits)
{
    //bits_neg,
    EXPECT_EQ(~220,        evalToInt<fun::bits_neg>(Value{220}));

    //bits_and,
    EXPECT_EQ(220&380,     evalToInt<fun::bits_and>(Value{220}, Value{380}));

    //bits_or,
    EXPECT_EQ(220|380,     evalToInt<fun::bits_or>(Value{220}, Value{380}));

    //bits_xor,
    EXPECT_EQ(220^380,     evalToInt<fun::bits_xor>(Value{220}, Value{380}));
}
