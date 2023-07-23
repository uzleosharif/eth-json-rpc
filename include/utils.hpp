
#ifndef UTILS_HPP
#define UTILS_HPP

#include <expected>
#include <string_view>

#include "types.hpp"

namespace eth {
[[nodiscard]] auto Valid(std::string_view) noexcept
    -> std::expected<void, std::string>;

class RpcClient {};
}  // namespace eth

#endif
