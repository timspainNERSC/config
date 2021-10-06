/*
 * Config.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: timpai
 */

#include "include/Config.hpp"
#include <boost/program_options.hpp>

namespace Nextsim {

std::vector<std::ifstream> Config::files;

void Config::addFile(const std::string& filename)
{
    files.push_back(std::ifstream(filename));
}

boost::program_options::variables_map Config::parseStatic(const boost::program_options::options_description& opt)
{
    boost::program_options::variables_map vm;

    for (auto& filestream: files) {
        boost::program_options::store( boost::program_options::parse_config_file(filestream, opt, false), vm);
    }
    return vm;
}
} /* namespace Nextsim */
