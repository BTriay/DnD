export module io;

import <string>;

import Hero;

namespace io
{
	namespace xml
	{

		export std::string get_class_name(const std::string& filename,
			const std::string& member_name);

		export void serialize(const Hero& hero, const std::string& filename);

		export Hero deserialize(const std::string& filename);

	}
}
