/* This file is part of the the dci project. Copyright (C) 2013-2021 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "pch.hpp"
#include "checkOne.hpp"
#include "evaluateBool.hpp"

namespace dci::module::ppn::node::rdb::instance::search
{
    bool checkOne(query::Scope scope, const pql::Expression& constraints, const table::Record& rec)
    {
        if(query::Scope::online == scope && rec.sv_remote().empty())
        {
            return false;
        }

        if(evaluateBool(rec, constraints))
        {
            return true;
        }

        return false;
    }
}
