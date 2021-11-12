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

class ConfClass : public Nextsim::Configured
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

    for (std::string name: cl.getConfigFileNames()) {
        //files.push_back(std::ifstream(name));
        Nextsim::Config::addStream(std::unique_ptr<std::istream>(new std::fstream(name)));
    }
    Nextsim::Config::setCommandLine(argc, argv);

    std::cout << "Configured" << std::endl;
    ConfClass cfgd;
    cfgd.configure();
    std::cout << cfgd << std::endl;
}
