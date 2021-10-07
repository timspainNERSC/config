/*!
 * @file main.cpp
 *
 * @date Oct 4, 2021
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#include "/opt/home/include/boost/program_options.hpp"
#include "include/Config.hpp"
#include "include/Configured.hpp"
#include "include/Derived.hpp"

#include <iostream>
int main(int argc, char* argv[]) {


    boost::program_options::options_description opt("Commando lion options");
    opt.add_options()
            ("help,h", "print help message")
            ("config-file", boost::program_options::value<std::string>(), "specify a configuration file")
            ("config-files", boost::program_options::value<std::vector<std::string> >()->multitoken(), "specify a list of configuration files" )
            ;
    boost::program_options::variables_map commandoLionVars;
    boost::program_options::store(boost::program_options::command_line_parser(argc, argv)
            .options(opt)
            .style(boost::program_options::command_line_style::unix_style)
            .allow_unregistered()
            .run(),
            commandoLionVars);

    if (commandoLionVars.count("config-file")) {
        Nextsim::Config::addFile(commandoLionVars["config-file"].as<std::string>());
    }
    if (commandoLionVars.count("config-files")) {
        for (const std::string& configFilename: commandoLionVars["config-files"].as<std::vector<std::string>>()) {
            Nextsim::Config::addFile(configFilename);
        }
    }

    std::cout << "Configured" << std::endl;
    Nextsim::Configured cfgd;
    cfgd.configure();
    cfgd.print(std::cout) << std::endl;

    std::cout << "Derived" << std::endl;
    Nextsim::Derived drv;

    Nextsim::Config::configureAll();

    drv.print(std::cout) << std::endl;
}
