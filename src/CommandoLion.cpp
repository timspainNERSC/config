/*
 * CommandoLion.cpp
 *
 *  Created on: Oct 7, 2021
 *      Author: timpai
 */

#include <string>
#include <iostream>

#include "include/CommandoLion.hpp"
#include "/opt/home/include/boost/program_options.hpp"

namespace Nextsim {

CommandoLion::CommandoLion(int argc, char* argv[])
{
    char oneConfigFile[] = "config-file";
    char manyConfigFiles[] = "config-files";

    boost::program_options::options_description opt("Commando lion options");
    opt.add_options()
            ("help,h", "print help message")
            (oneConfigFile, boost::program_options::value<std::string>(), "specify a configuration file")
            (manyConfigFiles, boost::program_options::value<std::vector<std::string> >()->multitoken(), "specify a list of configuration files" )
            ;
    auto parsed = boost::program_options::parse_command_line(argc, argv, opt);
    boost::program_options::store(parsed, m_arguments);

    for (auto& lionOption: parsed.options) {
        if (lionOption.string_key == oneConfigFile || lionOption.string_key == manyConfigFiles) {
            for (auto& stringValue: lionOption.value) {
                m_configFilenames.push_back(stringValue);
            }
        }
    }
}

std::vector<std::string> CommandoLion::getConfigFileNames()
{
    return m_configFilenames;
}
} /* namespace Nextsim */
