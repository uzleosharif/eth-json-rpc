

#include "utils.hpp"

#include <regex>

namespace eth {
auto Valid(std::string_view addr_str) noexcept
    -> std::expected<void, std::string> {
  static constexpr std::string_view pattern_str{"^0x[0-9a-fA-F]{40}$"};
  static const std::regex pattern{std::string{pattern_str}};

  if (not addr_str.starts_with("0x")) {
    return std::unexpected{"address string not formatted properly"};
  }
  if (not(addr_str.size() == 42)) {
    return std::unexpected{"address string has incorrect size"};
  }
  if (not std::regex_match(std::string{addr_str}, pattern)) {
    return std::unexpected{"address string is not alphanumeric"};
  }

  return {};
}

}  // namespace eth
