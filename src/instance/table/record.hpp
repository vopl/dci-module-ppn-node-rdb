/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"

namespace dci::module::ppn::node::rdb::instance
{
    class Table;
}

namespace dci::module::ppn::node::rdb::instance::table
{
    class Record
    {
    protected:
        Record(Table* table, std::size_t index);

    public:
        Record();
        Record(const Record& from);
        ~Record();

        Record& operator=(const Record& from);

        std::size_t index() const;

        const Set<link::Remote<>>& sv_remote() const;
        const pql::id256& sv_id() const;

        const pql::Value& value(const pql::Column& c) const;

    protected:
        Table *     _table {nullptr};
        std::size_t _index {std::numeric_limits<std::size_t>::max()};
    };
}
