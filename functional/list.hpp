#pragma once

namespace functional {
    namespace list {

        struct minimum {

            template <class C>
            auto operator()(const C & c) {
                using std::out_of_range;
                using std::min_element;

                if (!c.size())
                    throw out_of_range(__func__);

                return *min_element(c.begin(), c.end());
            }

        };

        template <
            template <class, class> class F
        > struct zip_with {

            template <class V1, class V2, template <class...> class C>
            auto operator()(const C<V1> & c1, const C<V2> & c2) {
                using std::min;
                using std::result_of;
                using Vr = typename result_of<F<V1,V2>(V1, V2)>::type;

                auto min_size = min(c1.size(), c2.size());
                C<Vr> r(min_size);
                F<V1, V2> f;

                for (decltype(min_size) i = 0; i < min_size; ++i)
                    r[i] = f(c1[i], c2[i]);

                return r;
            }

        };

        template <template <class...> class F> struct foldl1 {

            template <class C>
            auto operator()(const C & c) {
                using std::out_of_range;
                using std::accumulate;
                using V = typename C::value_type;

                if (!c.size())
                    throw out_of_range(__func__);

                return accumulate(c.begin() + 1, c.end(), *c.begin(), F<V>{});
            }

        };

    };
};
