module;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

module io;

import <string>;

std::string io::xml::get_class_name(const std::string& filename,
	const std::string& member_name)
{
	namespace pt = boost::property_tree;

	const auto xml_path = "boost_serialization.hero." + member_name;

	pt::ptree tree;
	pt::read_xml(filename, tree);

	return tree.get<std::string>(xml_path);
}