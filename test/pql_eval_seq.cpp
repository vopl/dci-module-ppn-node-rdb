/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "pql_eval.hpp"

/////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
TEST(module_ppn_node_rdb, pql_eval_seq)
{
    Value nums{List<Value>{{-1}, {0}, {1}, {2}}};
    List<Value> res;

    //seq_map,
    {
        List<Value> res = evalTo<fun::seq_map, List<Value>>(Node{fun::num_abs, List<Expression>{}}, nums);
        EXPECT_EQ(res, (List<Value>{{1}, {0}, {1}, {2}}));
    }

    //seq_grep,
    {
        List<Value> res = evalTo<fun::seq_grep, List<Value>>(Node{fun::num_lt, List<Expression>{Value{0}}}, nums);
        EXPECT_EQ(res, (List<Value>{{1}, {2}}));
    }

    //seq_reduce,
    {
        int res = evalTo<fun::seq_reduce, int>(Node{fun::num_add, List<Expression>{}}, nums);
        EXPECT_EQ(res, 2);
    }

    //seq_at,//element by index
    {
        int res = evalTo<fun::seq_at, int>(nums, Value{2});
        EXPECT_EQ(res, 1);
    }

    //seq_size,
    {
        std::size_t res = evalTo<fun::seq_size, std::size_t>(nums);
        EXPECT_EQ(res, 4u);
    }
}
