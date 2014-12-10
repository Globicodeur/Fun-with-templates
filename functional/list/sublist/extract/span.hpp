#pragma once

#include <tuple>

#include "../../../compose.hpp"

namespace functional {
    namespace list {

        static struct _span: composable<2, _span> {

            template <class C, class F>
            auto operator()(const F & f, const C & c) const {
                using std::make_tuple;

                auto mid = c.begin();
                while (mid != c.end() && f(*mid))
                    ++mid;

                return make_tuple(C { c.begin(), mid }, C { mid, c.end() });
            }

        } span;

    }
}
