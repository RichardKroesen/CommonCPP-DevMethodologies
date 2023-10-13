#include <iostream>
#include <pugixml.hpp>

int main() {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("../example.xml");

    if (result) {
        pugi::xml_node root = doc.child("mainBody");

        for (pugi::xml_node node : root.children("element")) {
            std::string name = node.attribute("name").value();
            std::string type = node.attribute("type").value();

            std::string text = node.text().get();

            std::cout << "Name: " << name << ", Sensor Type: " << type << ", Value: " << text << std::endl;
        }
    } else {
        std::cerr << "XML parsing error: " << result.description() << std::endl;
    }

    return 0;
}
