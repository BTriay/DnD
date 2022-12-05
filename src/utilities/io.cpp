module;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/set.hpp>
#include <boost/foreach.hpp>

module io;

import <string>;
import <fstream>;

import Hero;

std::string io::xml::get_class_name(const std::string& filename,
	const std::string& member_name)
{
	namespace pt = boost::property_tree;

	const auto xml_path = "boost_serialization.hero." + member_name;

	pt::ptree tree;
	pt::read_xml(filename, tree);

	return tree.get<std::string>(xml_path);
}

void io::xml::serialize(const Hero& hero, const std::string& filename)
{
	std::ofstream fs1{ filename };
	boost::archive::xml_oarchive oa(fs1);
	oa << BOOST_SERIALIZATION_NVP(hero);
}