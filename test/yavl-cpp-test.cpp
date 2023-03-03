#include <catch.hpp>
#include <yaml.h>
#include <yavl.h>

TEST_CASE("yavl-cpp", "[yavl-cpp]")
{
    YAML::Node grammar = YAML::Load("map:\n"
                                    "  test: [bool: ]");
    YAML::Node document = YAML::Load("test: true");

    YAVL::Validator yavl_bool(grammar, document);
    REQUIRE(yavl_bool.validate());

    grammar = YAML::Load("map:\n"
                         "  test: [float: ]");
    document = YAML::Load("test: 3.1415");

    YAVL::Validator yavl_float(grammar, document);
    REQUIRE(yavl_float.validate());
}
