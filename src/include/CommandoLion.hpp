/*
 * CommandoLion.hpp
 *
 *  Created on: Oct 7, 2021
 *      Author: timpai
 */

#ifndef SRC_INCLUDE_COMMANDOLION_HPP_
#define SRC_INCLUDE_COMMANDOLION_HPP_

#include <vector>
#include <string>

#include "/opt/home/include/boost/program_options.hpp"

namespace Nextsim {

class CommandoLion {
public:
    CommandoLion(int argc, char* argv[]);
    virtual ~CommandoLion() = default;

    std::vector<std::string> getConfigFileNames();
private:
    CommandoLion() = default;

    boost::program_options::variables_map m_arguments;
    std::vector<std::string> m_configFilenames;
};

} /* namespace Nextsim */

#endif /* SRC_INCLUDE_COMMANDOLION_HPP_ */
