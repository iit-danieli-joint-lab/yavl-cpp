#include <fstream>
#include <iostream>
#include <yaml.h>
#include <yavl.h>

int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cout << "should have 2 arguments grammer file(schema) and file to be checked (argc = " << argc << " )\n";
        return -1;
    }
    // argv[1] grammar file
    // argv[2] file to be checked

    YAML::Node gr;
    try {
        gr = YAML::LoadFile(argv[1]);
    } catch (const YAML::Exception& e) {
        std::cout << "Error reading grammar: " << e.what() << std::endl;
        return 1;
    }

    YAML::Node doc;
    try {
        doc = YAML::LoadFile(argv[2]);
    } catch (const YAML::Exception& e) {
        std::cout << "Error reading document: " << e.what() << std::endl;
        return 2;
    }

    YAVL::Validator yavl(gr, doc);
    bool ok = yavl.validate();
    if (!ok) {
        std::cout << "ERRORS FOUND: " << std::endl;
        std::cout << yavl.get_errors() << std::endl;
    }
    return !ok;
}
