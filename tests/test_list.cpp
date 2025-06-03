#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../list.h"
#include <string>

TEST_CASE("List operations", "[list]") {
    SECTION("Default constructor creates empty list") {
        list<int> list;
        REQUIRE(list.empty());
        REQUIRE(list.size() == 0);
    }

    SECTION("Size-value constructor creates list with correct size and values") {
        list<int> list(3, 42);
        REQUIRE(list.size() == 3);
        REQUIRE(list.front() == 42);
        REQUIRE(list.back() == 42);
    }

    SECTION("Push back operations") {
        list<int> list;
        
        SECTION("Single push_back") {
            list.push_back(1);
            REQUIRE(list.size() == 1);
            REQUIRE(list.back() == 1);
            REQUIRE(list.front() == 1);
        }

        SECTION("Multiple push_back") {
            list.push_back(1);
            list.push_back(2);
            list.push_back(3);
            REQUIRE(list.size() == 3);
            REQUIRE(list.back() == 3);
            REQUIRE(list.front() == 1);
        }
    }

    SECTION("Push front operations") {
        list<int> list;
        
        SECTION("Single push_front") {
            list.push_front(1);
            REQUIRE(list.size() == 1);
            REQUIRE(list.front() == 1);
            REQUIRE(list.back() == 1);
        }

        SECTION("Multiple push_front") {
            list.push_front(1);
            list.push_front(2);
            list.push_front(3);
            REQUIRE(list.size() == 3);
            REQUIRE(list.front() == 3);
            REQUIRE(list.back() == 1);
        }
    }

    SECTION("Pop operations") {
        list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);

        SECTION("Pop back") {
            int popped = list.pop_back();
            REQUIRE(popped == 3);
            REQUIRE(list.size() == 2);
            REQUIRE(list.back() == 2);
        }

        SECTION("Pop front") {
            int popped = list.pop_front();
            REQUIRE(popped == 1);
            REQUIRE(list.size() == 2);
            REQUIRE(list.front() == 2);
        }

        SECTION("Pop until empty") {
            list.pop_back();
            list.pop_back();
            list.pop_back();
            REQUIRE(list.empty());
            REQUIRE(list.size() == 0);
        }
    }

    SECTION("Clear operation") {
        list<int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        
        list.clear();
        REQUIRE(list.empty());
        REQUIRE(list.size() == 0);
    }

    SECTION("Resize operations") {
        list<int> list;
        list.push_back(1);
        list.push_back(2);

        SECTION("Resize larger") {
            list.resize(4, 42);
            REQUIRE(list.size() == 4);
            REQUIRE(list.back() == 42);
        }

        SECTION("Resize smaller") {
            list.resize(1);
            REQUIRE(list.size() == 1);
            REQUIRE(list.front() == 1);
        }

        SECTION("Resize to zero") {
            list.resize(0);
            REQUIRE(list.empty());
            REQUIRE(list.size() == 0);
        }

        SECTION("Resize with negative size") {
            list.resize(-1);
            REQUIRE(list.size() == 2);
        }
    }

    SECTION("Reverse operation") {
        list<int> list;
        
        SECTION("Reverse empty list") {
            list.reverse();
            REQUIRE(list.empty());
        }

        SECTION("Reverse single element") {
            list.push_back(1);
            list.reverse();
            REQUIRE(list.front() == 1);
            REQUIRE(list.back() == 1);
        }

        SECTION("Reverse multiple elements") {
            list.push_back(1);
            list.push_back(2);
            list.push_back(3);
            list.reverse();
            REQUIRE(list.front() == 3);
            REQUIRE(list.back() == 1);
        }
    }

    SECTION("Different data types") {
        SECTION("String list") {
            list<std::string> strList;
            strList.push_back("Hello");
            strList.push_back("World");
            REQUIRE(strList.size() == 2);
            REQUIRE(strList.front() == "Hello");
            REQUIRE(strList.back() == "World");
        }

        SECTION("Double list") {
            list<double> doubleList;
            doubleList.push_back(1.5);
            doubleList.push_back(2.7);
            REQUIRE(doubleList.size() == 2);
            REQUIRE(doubleList.front() == Approx(1.5));
            REQUIRE(doubleList.back() == Approx(2.7));
        }
    }

    SECTION("Edge cases") {
        list<int> list;
        
        SECTION("Pop from empty list") {
            int popped = list.pop_back();
            REQUIRE(popped == 0);
            REQUIRE(list.empty());

            popped = list.pop_front();
            REQUIRE(popped == 0);
            REQUIRE(list.empty());
        }

        SECTION("Multiple operations sequence") {
            list.push_back(1);
            list.push_front(2);
            list.push_back(3);
            list.pop_front();
            list.push_back(4);
            REQUIRE(list.size() == 3);
            REQUIRE(list.front() == 1);
            REQUIRE(list.back() == 4);
        }
    }
} 