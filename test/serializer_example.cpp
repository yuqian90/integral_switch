/*
 * example_test.cpp: An over-simplified example showing what integral_switch can be used for.
 * Copyright (C) 2019  Qian Yu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "integral_switch.h"

namespace integral_switch {
enum class TypeId { msg0 = 0, msg1 = 1, msg2 = 2 };

struct Obj0 {
    std::string field0;

    std::string say_something() const { return "Obj0::field0: " + field0; }
};

struct Obj1 {
    std::string field1;

    std::string say_something() const { return "Obj1::field1: " + field1; }
};

struct Obj2 {
    std::string field2;

    std::string say_something() const { return "Obj2::field2: " + field2; }
};

using Switch = integral_switch<TypeId, TypeId::msg0, TypeId::msg1, TypeId::msg2>;

template <TypeId I> struct MapType;

template <> struct MapType<TypeId::msg0> { using type = Obj0; };

std::string serialize(const Obj0 &obj) { return obj.field0; }

void deserialize(const std::string &msg, Obj0 &obj) { obj.field0 = msg; }

template <> struct MapType<TypeId::msg1> { using type = Obj1; };

std::string serialize(const Obj1 &obj) { return obj.field1; }

void deserialize(const std::string &msg, Obj1 &obj) { obj.field1 = msg; }

template <> struct MapType<TypeId::msg2> { using type = Obj2; };

std::string serialize(const Obj2 &obj) { return obj.field2; }

void deserialize(const std::string &msg, Obj2 &obj) { obj.field2 = msg; }

struct PrintVisitor {
    const std::string &msg;

    template <TypeId I> void operator()(std::integral_constant<TypeId, I>) const {
        using ObjType = typename MapType<I>::type;
        ObjType obj;
        deserialize(msg, obj);
        std::cout << obj.say_something() << std::endl;
    }
};

TEST(serializer_example, serialize) {
    using Msg = std::pair<TypeId, std::string>;

    std::vector<Msg> messages;

    Obj0 obj0{"hello"};
    Obj1 obj1{"world"};
    Obj2 obj2{"!"};

    // Serialize
    messages.emplace_back(TypeId::msg0, serialize(obj0));
    messages.emplace_back(TypeId::msg1, serialize(obj1));
    messages.emplace_back(TypeId::msg2, serialize(obj2));

    // Call say_something() on the deserialized objects.
    std::vector<std::string> fields;

    testing::internal::CaptureStdout();
    for (const auto &msg : messages) {
        PrintVisitor printer{msg.second};
        Switch::visit(printer, msg.first);
    }
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, R"(Obj0::field0: hello
Obj1::field1: world
Obj2::field2: !
)");
}

} // namespace integral_switch
