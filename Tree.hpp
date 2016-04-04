/*
 * Tree.hpp
 *
 */

#ifndef TREE_HPP_
#define TREE_HPP_

// This can be extended in later steps but we're currently fine using the default
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/optional.hpp>
#include <boost/variant.hpp>
#include <boost/signals2.hpp>

namespace inexor {
namespace tree {
	typedef boost::variant<bool, short, int, long, double, float, std::string> Primitive;
	/*struct Observe : public boost::static_visitor {
		template<typename T>
		void operator()(T t) const { }
	};*/

	extern boost::property_tree::ptree Tree;
}
}


#endif /* TREE_HPP_ */
