/*
 * SyncI.cpp
 *
 *  Created on: 26.03.2016
 *      Author: fohlen
 */

#include "SyncI.hpp"

namespace inexor {
namespace tree {

void SyncI::printString(const std::string& s, const Ice::Current&)
{
    std::cout << s << std::endl;
}

} /* namespace tree */
} /* namespace inexor */
