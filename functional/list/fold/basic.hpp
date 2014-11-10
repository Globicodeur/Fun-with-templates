#pragma once

namespace functional {
    namespace list {

        template <class F> struct foldl {

            template <class V, class C>
            auto operator()(const V & v, const C & c) const {
                using std::accumulate;

                return accumulate(c.begin(), c.end(), v, F{});
            }

        };

        template <class F> struct foldl1 {

            template <class C>
            auto operator()(const C & c) const {
                using std::out_of_range;
                using std::accumulate;

                if (c.empty())
                    throw out_of_range(__func__);

                return accumulate(c.begin() + 1, c.end(), *c.begin(), F{});
            }

        };

        template <class F> struct foldr {

            template <class V, class C>
            auto operator()(const V & v, const C & c) const {
                using std::accumulate;

                return accumulate(c.rbegin(), c.rend(), v, F{});
            }

        };

        template <class F> struct foldr1 {

            template <class C>
            auto operator()(const C & c) const {
                using std::out_of_range;
                using std::accumulate;

                if (c.empty())
                    throw out_of_range(__func__);

                return accumulate(c.rbegin() + 1, c.rend(), *c.rbegin(), F{});
            }

        };

        namespace impl {

            template <class F>
            struct foldl1<F> foldl1;
            template <class F>
            struct foldl<F> foldl;
            template <class F>
            struct foldr<F> foldr;
            template <class F>
            struct foldr1<F> foldr1;

        };
    };
};
