/*
 * Config.hpp
 *
 *  Created on: Oct 4, 2021
 *      Author: timpai
 */

#ifndef SRC_INCLUDE_CONFIG_HPP
#define SRC_INCLUDE_CONFIG_HPP

#include <string>
#include <vector>
#include <set>
#include <functional>

#include <boost/program_options.hpp>

namespace Nextsim {

class Config {
public:
    Config();
    virtual ~Config() = default;

    static void addFile(const std::string&);
    template<typename C>
    static void addFiles(const C& container)
    {
        for(const auto& item: container) {
            addFile(item);
        }
    }
    inline static void setCommandLine(int argc, char* argv[])
    {
        m_argc = argc;
        m_argv = argv;
    }
    static boost::program_options::variables_map parseStatic(const boost::program_options::options_description& opt);

    static void addConfigurable(Config*);
    static void configureAll();
protected:
    virtual void parseVirtual() = 0;

private:
    static std::vector<std::string> filenames;
    static std::set<Config*> configuringObjects;

    static int m_argc;
    static char** m_argv;
};

} /* namespace Nextsim */

#endif /* SRC_INCLUDE_CONFIG_HPP */
