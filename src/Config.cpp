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
std::set<Config*> Config::configuringObjects;

int Config::m_argc = 0;
char** Config::m_argv = nullptr;

Config::Config()
{
    configuringObjects.insert(this);
}

void Config::addFile(const std::string& filename)
{
    filenames.push_back(filename);
}

boost::program_options::variables_map Config::parseStatic(const boost::program_options::options_description& opt)
{
    boost::program_options::variables_map vm;
    // Parse the command file for any overrides
    if (m_argc) {
        auto parsed = boost::program_options::command_line_parser(m_argc, m_argv)
                                          .options(opt)
                                          .style(boost::program_options::command_line_style::unix_style)// | po::command_line_style::allow_long_disguise)
                                          .allow_unregistered()
                                          .run();
        boost::program_options::store(parsed, vm);
    }
    // Parse the named files for configuration
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

void Config::addConfigurable(Config* pcfg)
{
    configuringObjects.insert(pcfg);
}

void Config::configureAll()
{
    for(Config* pConfigurer: configuringObjects) {
        pConfigurer->parseVirtual();
    }
    configuringObjects.clear();
}
} /* namespace Nextsim */
