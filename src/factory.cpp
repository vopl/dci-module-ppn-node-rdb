/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#include "factory.hpp"
#include "instance.hpp"

namespace dci::module::ppn::node::rdb
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Factory::Factory()
        : api::Factory<>::Opposite(idl::interface::Initializer())
    {
        //in build(list<Feature> features) -> Instance;
        methods()->build() += sol() * [this](List<api::Feature<>>&& features)
        {
            Instance* instance = new Instance;
            instance->involvedChanged() += instance * [instance](bool v)
            {
                if(!v)
                {
                    delete instance;
                }
            };

            return instance->initialize(std::move(features)).apply<api::Instance<>>(sol(), [res=instance->opposite()](auto in, auto& out)
            {
                if(in.resolvedCancel())
                {
                    out.resolveCancel();
                }
                else if(in.resolvedException())
                {
                    out.resolveException(in.detachException());
                }
                else
                {
                    out.resolveValue(res);
                }
            });
        };
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    Factory::~Factory()
    {
        sol().flush();
    }
}
