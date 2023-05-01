#ifndef NODE_H
#define NODE_H

#include <cstddef> // for std::size_t
#include <tuple>   // for std::tuple_element, std::tuple_size


typedef struct Node {
    int i, j;
        
    Node(int a, int b) : i(a), j(b) {}

    // Define the tuple_size type trait for Node
    static constexpr std::size_t tuple_size = 2;

    // Define the tuple_element type trait for Node
    template <std::size_t N>
    struct tuple_element {
        static_assert(N < tuple_size, "Index out of range");
        using type = int;
    };

    // Define get function to return the value of the ith element of Node
    template <std::size_t N>
    int get() const {
        static_assert(N < tuple_size, "Index out of range");
        if constexpr (N == 0) {
            return i;
        } else if constexpr (N == 1) {
            return j;
        }
    }
} No;


// Define the std::get function for Node
template <std::size_t N>
int get(const Node& node) {
    return node.get<N>();
}

#endif // NODE_H
