#include "import_chart.h"


Import_Chart::Import_Chart(/* args */)
{

Json::Value root;   // starts as "null"; will contain the root value after parsing
std::cin >> root;

// Get the value of the member of root named 'my-encoding', return 'UTF-32' if there is no
// such member.
std::string my_encoding = root.get("my-encoding", "UTF-32" ).asString();

// Get the value of the member of root named 'my-plug-ins'; return a 'null' value if
// there is no such member.
const Json::Value my_chart = root["chartInformation"];
// for ( int index = 0; index < my_plugins.size(); ++index )  // Iterates over the sequence elements.
//    yourlib::loadPlugIn( my_plugins[index].asString() );

// yourlib::setIndentLength( root["my-indent"].get("length", 3).asInt() );
// yourlib::setIndentUseSpace( root["my-indent"].get("use_space", true).asBool() );

// ...
// At application shutdown to make the new configuration document:
// Since Json::Value has implicit constructor for all value types, it is not
// necessary to explicitly construct the Json::Value object:
// root["encoding"] = yourlib::getCurrentEncoding();
// root["indent"]["length"] = yourlib::getCurrentIndentLength();
// root["indent"]["use_space"] = yourlib::getCurrentIndentUseSpace();

// Make a new JSON document with the new configuration. Preserve original comments.
std::cout << root << "\n";

} 