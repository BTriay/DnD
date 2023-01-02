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
import enumeration;

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

Hero io::xml::deserialize(const std::string& filename)
{
	auto cclass = io::xml::get_class_name(filename, "m_class_name");

	Hero hero{ "Aragorn", Race::Human, cclass, 
		{ .charisma = 8, .constitution = 8, .dexterity = 8, 
		.intelligence = 15, .strength = 15, .wisdom = 15 } };

	std::ifstream fs2{ filename };
	boost::archive::xml_iarchive ia{ fs2 };
	ia >> BOOST_SERIALIZATION_NVP(hero);

	return hero;
}