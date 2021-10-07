/*
 * Config.hpp
 *
 *  Created on: Oct 4, 2021
 *      Author: timpai
 */

#ifndef SRC_INCLUDE_CONFIG_HPP
#define SRC_INCLUDE_CONFIG_HPP

#include <fstream>
#include <vector>
#include <boost/program_options.hpp>

namespace Nextsim {

class Config {
public:
    Config() = default;
    virtual ~Config() = default;

    virtual void parseVirtual() = 0;

    static void addFile(const std::string&);
    template<typename C>
    static void addFiles(const C& container)
    {
        for(const auto& item: container) {
            addFile(item);
        }
    }
    static boost::program_options::variables_map parseStatic(const boost::program_options::options_description& opt);

private:
    static std::vector<std::ifstream> files;
};

} /* namespace Nextsim */

#endif /* SRC_INCLUDE_CONFIG_HPP */
