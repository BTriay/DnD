module;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

export module io;

import <string>;

namespace io
{
	namespace xml
	{
		namespace pt = boost::property_tree;

		std::string get_variable_name(const std::string& filename)
		{
			const std::string ignore = "<xmlattr>";
			std::string var;

			pt::ptree tree;
			pt::read_xml(filename, tree);

			BOOST_FOREACH(pt::ptree::value_type & v, tree.get_child("boost_serialization"))
			{
				if (ignore.compare(v.first.data()))
					var = v.first.data();
			}

			return var;
		}

		export std::string get_class_name(const std::string& filename,
			const std::string& member_name)
		{
			auto variable_name = get_variable_name(filename);
			auto xml_path = "boost_serialization." + variable_name + "." + member_name;

			pt::ptree tree;
			pt::read_xml(filename, tree);

			return tree.get<std::string>(xml_path);
		}

	}
}
