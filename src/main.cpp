/*!
 * @file main.cpp
 *
 * @date Oct 4, 2021
 * @author Tim Spain <timothy.spain@nersc.no>
 */

#include "include/Config.hpp"
#include "include/Configured.hpp"
#include "include/Derived.hpp"

#include <iostream>
int main() {

    Nextsim::Config::addFile("test.cfg");
    Nextsim::Configured cfgd;

    std::cout << "Configured" << std::endl;
    cfgd.configure();
    cfgd.print(std::cout) << std::endl;

    std::cout << "Derived" << std::endl;
    Nextsim::Derived drv;

    Nextsim::Config::configureAll();

    drv.print(std::cout) << std::endl;
}
