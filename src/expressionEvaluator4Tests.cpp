/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "expressionEvaluator4Tests.hpp"
#include "instance/eval.hpp"
#include "instance/table.hpp"

namespace dci::module::ppn::node::rdb
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    ExpressionEvaluator4Tests::ExpressionEvaluator4Tests()
        : pql::ExpressionEvaluator4Tests<>::Opposite(idl::interface::Initializer())
    {
        methods()->evaluate() += sol() * [](const pql::Expression& expr)
        {
            instance::Table tbl(nullptr);
            pql::Expression res = instance::eval::combine(expr, tbl.enumerateRecords());
            return cmt::readyFuture(res.sget<pql::Value>());
        };
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    ExpressionEvaluator4Tests::~ExpressionEvaluator4Tests()
    {
    }
}
