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
#include <vector>

class ConfClass : public Nextsim::Configured<ConfClass>
{
public:
    void configure() override
    {
        data = Configured::getConfiguration("conf.data", 1);
    };
private:
    int data = 0;

friend std::ostream& operator<<(std::ostream&, const ConfClass&);
};

std::ostream& operator<<(std::ostream& os, const ConfClass& cc)
{
    return os << cc.data;
}

int main(int argc, char* argv[]) {

    Nextsim::CommandoLion cl(argc, argv);

    std::cout << "Using file streams:" << std::endl;
    for (std::string name: cl.getConfigFileNames()) {
        std::cout << name << std::endl;
        Nextsim::Configurator::addFile(name);
    }
    Nextsim::Configurator::setCommandLine(argc, argv);

    std::cout << "Configured" << std::endl;
    ConfClass cfgd;
    Nextsim::tryConfigure(cfgd);//.configure();
    std::cout << cfgd << std::endl;

    ConfClass cfge;
    Nextsim::tryConfigure(&cfge);
    std::cout << cfge << std::endl;
}
