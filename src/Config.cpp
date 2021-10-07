/*
 * Config.cpp
 *
 *  Created on: Oct 4, 2021
 *      Author: timpai
 */

#include "include/Config.hpp"

#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>

namespace Nextsim {

std::vector<std::string> Config::filenames;

void Config::addFile(const std::string& filename)
{
    filenames.push_back(filename);
}

boost::program_options::variables_map Config::parseStatic(const boost::program_options::options_description& opt)
{
    boost::program_options::variables_map vm;

    for (auto& filename: filenames) {
        try {
        std::ifstream filestream(filename);
        boost::program_options::store( boost::program_options::parse_config_file(filestream, opt, true), vm);
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return vm;
}
} /* namespace Nextsim */
