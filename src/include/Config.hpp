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
#include <istream>
#include <fstream>
#include <memory>

#include <boost/program_options.hpp>

namespace Nextsim {

class Config {
public:
    Config();
    virtual ~Config() = default;

    static inline void addStream(std::unique_ptr<std::istream> is)
    {
        sources.push_back(std::move(is));
    }
    template<typename C>
    static void addStreams(C& container)
    {
        for (auto& stream: container) {
            addStream(stream);
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
    static std::vector<std::unique_ptr<std::istream>> sources;
    static std::set<Config*> configuringObjects;

    static int m_argc;
    static char** m_argv;
};

} /* namespace Nextsim */

#endif /* SRC_INCLUDE_CONFIG_HPP */
