/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "../search.hpp"

namespace dci::module::ppn::node::rdb::instance::search
{
    class IterativeMinimize final
        : public Search
        , public mm::heap::Allocable<IterativeMinimize>
    {
    public:
        IterativeMinimize(
                Instance* instance,
                query::Scope scope,
                pql::Expression&& constraints,
                pql::Expression&& rate);
        ~IterativeMinimize() override;

    private:
        bool startImpl() override;
        bool stopImpl() override;

        void online(const table::Record& rec) override;
        void offline(const table::Record& rec) override;
        void inserted(const table::Record& rec) override;
        void updated(const table::Record& rec) override;

    private:
        bool checkAndRespectOne(const table::Record& rec);
        void processOne(const table::Record& rec);

    private:
        pql::Expression    _rate;
        real64             _currentRate {std::numeric_limits<real64>::max()};
    };
}
