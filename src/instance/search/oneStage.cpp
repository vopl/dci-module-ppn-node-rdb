/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "oneStage.hpp"

namespace dci::module::ppn::node::rdb::instance::search
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    OneStage::OneStage(
            Instance* instance,
            query::Scope scope,
            pql::Expression&& constraints)
        : Search(instance, scope, std::move(constraints))
    {
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    OneStage::~OneStage()
    {
        stopImpl();
        flush();
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    bool OneStage::startImpl()
    {
        if(!Search::startImpl())
        {
            return false;
        }

        table::Cursor tc = enumerateRecords();
        while(tc)
        {
            if(checkOne(tc))
            {
                emitResult(tc);
            }
            tc.next();
        }

        OneStage::stopImpl();

        return true;
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    bool OneStage::stopImpl()
    {
        if(!Search::stopImpl())
        {
            return false;
        }

        return true;
    }
}
