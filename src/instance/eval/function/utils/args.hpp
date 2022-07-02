/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "../../../table/record.hpp"

namespace dci::module::ppn::node::rdb::instance::eval::function::utils
{
    class Args
    {
    public:
        Args(const List<pql::Expression>& raw, const table::Record& record);

        const table::Record& record() const;
        std::size_t size() const;
        const pql::Value& operator[](std::size_t idx) const;
        const List<pql::Value>& head(std::size_t amount) const;

    protected:
        const List<pql::Expression>& _raw;
        const table::Record& _record;

        mutable List<pql::Value> _combined;

        static const pql::Value _nullStub;
    };
}
