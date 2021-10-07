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
#include "include/CommandoLion.hpp"

#include <iostream>
int main(int argc, char* argv[]) {

    Nextsim::CommandoLion cl(argc, argv);

    Nextsim::Config::addFiles(cl.getConfigFileNames());
    Nextsim::Config::setCommandLine(argc, argv);

    std::cout << "Configured" << std::endl;
    Nextsim::Configured cfgd;
    cfgd.configure();
    cfgd.print(std::cout) << std::endl;

    std::cout << "Derived" << std::endl;
    Nextsim::Derived drv;

    Nextsim::Config::configureAll();

    drv.print(std::cout) << std::endl;
}
