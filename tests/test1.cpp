#include <catch.hpp>

#include "stack.hpp"

TEST_CASE("push", "") {
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    REQUIRE(s1.count() == 5);
}

TEST_CASE("pop", "") {
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    REQUIRE(s1.count() == 5);
    s1.pop();
    REQUIRE(s1.count() == 4);
    s1.pop();
    REQUIRE(s1.count() == 3);
    s1.pop();
    REQUIRE(s1.count() == 2);
}

TEST_CASE("top", "") {
    stack<int> s1;
    int temp;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    temp = s1.top();
    REQUIRE(temp == -1);
    REQUIRE(s1.count() == 4);
}

   
TEST_CASE("empty", "") {
    stack<int> s1;
    s1.empty();
    REQUIRE(s1.empty() == true);
    s1.push(1);
    s1.empty();
    REQUIRE(s1.empty() == false);    
    s1.pop();  
    s1.empty();
    REQUIRE(s1.empty() == true);
}
