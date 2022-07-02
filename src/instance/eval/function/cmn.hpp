/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "exec.hpp"

namespace dci::module::ppn::node::rdb::instance::eval::function
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <>
    pql::Value exec<pql::fun::cmn_eqType>(const Args& args)
    {
        if(args.size() != 2) return {};
        return pql::Value{args[0].data.index() == args[1].data.index()};
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <>
    pql::Value exec<pql::fun::cmn_eq>(const Args& args)
    {
        if(args.size() != 2) return {};
        return pql::Value{args[0] == args[1]};
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <>
    pql::Value exec<pql::fun::cmn_ne>(const Args& args)
    {
        if(args.size() != 2) return {};
        return pql::Value{args[0] != args[1]};
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <>
    pql::Value exec<pql::fun::cmn_gt>(const Args& args)
    {
        if(args.size() != 2) return {};
        return pql::Value{args[0] > args[1]};
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <>
    pql::Value exec<pql::fun::cmn_lt>(const Args& args)
    {
        if(args.size() != 2) return {};
        return pql::Value{args[0] < args[1]};
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <>
    pql::Value exec<pql::fun::cmn_ge>(const Args& args)
    {
        if(args.size() != 2) return {};
        return pql::Value{args[0] >= args[1]};
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <>
    pql::Value exec<pql::fun::cmn_le>(const Args& args)
    {
        if(args.size() != 2) return {};
        return pql::Value{args[0] <= args[1]};
    }
}
