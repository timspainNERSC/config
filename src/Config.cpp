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

std::vector<std::istream*> Config::sources;
std::set<Config*> Config::configuringObjects;

int Config::m_argc = 0;
char** Config::m_argv = nullptr;

Config::Config()
{
    configuringObjects.insert(this);
}

boost::program_options::variables_map Config::parseStatic(const boost::program_options::options_description& opt)
{
    boost::program_options::variables_map vm;
    // Parse the command file for any overrides
    if (m_argc && m_argv) {
        auto parsed = boost::program_options::command_line_parser(m_argc, m_argv)
                                          .options(opt)
                                          .style(boost::program_options::command_line_style::unix_style)// | po::command_line_style::allow_long_disguise)
                                          .allow_unregistered()
                                          .run();
        boost::program_options::store(parsed, vm);
    }
    // Parse the named files for configuration
    for (std::istream* stream: sources) {
        try {
        boost::program_options::store( boost::program_options::parse_config_file(*stream, opt, true), vm);
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        // Once the stream has been parsed, clear all flags (especially EOF)
        // and seek back to the start.
        stream->clear();
        stream->seekg(0, std::ios_base::beg);
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
