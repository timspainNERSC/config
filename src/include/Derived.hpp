/*
 * Derived.hpp
 *
 *  Created on: Oct 6, 2021
 *      Author: timpai
 */

#ifndef SRC_INCLUDE_DERIVED_HPP_
#define SRC_INCLUDE_DERIVED_HPP_

#include <string>
#include <ostream>

#include "Config.hpp"

namespace Nextsim {

class Derived : public Config {
public:
    Derived();
    virtual ~Derived();

    inline void configure()
    {
        parseVirtual();
    }
    std::ostream& print(std::ostream&);

protected:
    virtual void parseVirtual();

private:
    int configuredInt;
    std::string configuredString;
};

} /* namespace Nextsim */

#endif /* SRC_INCLUDE_DERIVED_HPP_ */
