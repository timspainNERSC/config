/*
 * Derived.cpp
 *
 *  Created on: Oct 6, 2021
 *      Author: timpai
 */

#include "include/Derived.hpp"

#include <iostream>
#include <string>
#include <boost/program_options.hpp>

namespace Nextsim {

Derived::Derived()
    : Config()
    , configuredInt(0)
    , configuredString("Yo!")
{}

Derived::~Derived()
{
    // TODO Auto-generated destructor stub
}

void Derived::parseVirtual()
{
    boost::program_options::options_description opt("Options");

    const std::string valueKey = "derived.int";
    const std::string stringKey = "configs.string";

    opt.add_options()
            (valueKey.c_str(), boost::program_options::value<int>()->default_value(1), "Specify a value")
            (stringKey.c_str(), boost::program_options::value<std::string>()->default_value("default"), "Specify a string")
            ;

    boost::program_options::variables_map vm = Config::parseStatic(opt);

    configuredInt = vm[valueKey].as<int>();
    configuredString = std::string("Yo!") + vm[stringKey].as<std::string>();
}

std::ostream& Derived::print(std::ostream& os)
{
    return os << "integer = " << configuredInt << ", string = " << configuredString;
}
} /* namespace Nextsim */
