/*!
 * @file Configured.hpp
 *
 * @date Oct 5, 2021
 * @author Tim Spain
 */

#ifndef SRC_INCLUDE_CONFIGURED_HPP
#define SRC_INCLUDE_CONFIGURED_HPP

#include <string>
#include <ostream>
#include <boost/program_options.hpp>

namespace Nextsim {

class Configured {
public:
    Configured();
    virtual ~Configured();

    void configure();

    std::ostream& print(std::ostream&);
private:
    double configuredValue;
    std::string configuredString;
};

} /* namespace Nextsim */

#endif /* SRC_INCLUDE_CONFIGURED_HPP */
