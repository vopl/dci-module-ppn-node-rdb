/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "pch.hpp"
#include "table/cursor.hpp"

namespace dci::module::ppn::node::rdb
{
    class Instance;
}

namespace dci::module::ppn::node::rdb::instance
{
    class Search
        : public query::Result<>::Opposite
        , public sbs::Owner
    {
    public:
        Search(
                Instance* instance,
                query::Scope scope,
                pql::Expression&& constraints);
        virtual ~Search();

        virtual void online(const table::Record& rec);
        virtual void offline(const table::Record& rec);
        virtual void inserted(const table::Record& rec);
        virtual void updated(const table::Record& rec);
        virtual void remove(const table::Record& rec);

    protected:
        void subscribe();
        void unsubscribe();

        table::Cursor enumerateRecords();
        void emitResult(const table::Record& rec);

        bool checkOne(const table::Record& rec);

    protected:
        virtual bool startImpl() = 0;
        virtual bool stopImpl() = 0;

    private:
        Instance *      _instance;
        query::Scope    _scope;
        pql::Expression _constraints;
        bool            _started {false};
    };
}
