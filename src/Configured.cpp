/*
 * Configured.cpp
 *
 *  Created on: Oct 5, 2021
 *      Author: timpai
 */

#include "include/Configured.hpp"
#include "include/Config.hpp"

#include <string>

#include <iostream>

namespace Nextsim {

const std::string valueKey = "configs.value";
const std::string stringKey = "configs.string";

Configured::Configured()
    : opt("Options")
    , configuredValue(0.)
    , configuredString("")
{
    opt.add_options()
            (valueKey.c_str(), boost::program_options::value<double>()->default_value(1.), "Specify a value")
            (stringKey.c_str(), boost::program_options::value<std::string>()->default_value("default"), "Specify a string")
            ;
}

Configured::~Configured()
{
    // TODO Auto-generated destructor stub
}

void Configured::configure()
{
    boost::program_options::variables_map vm = Config::parseStatic(opt);
    configuredValue = vm[valueKey].as<double>();
    configuredString = vm[stringKey].as<std::string>();
}

std::ostream& Configured::print(std::ostream& os)
{
    return os << "value = " << configuredValue << ", string = " << configuredString;
}
} /* namespace Nextsim */
