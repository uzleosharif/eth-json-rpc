

#include "utils.hpp"

#include <regex>

#include "fmt/core.h"

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

auto RpcClientCpr::SendRequest(std::string_view method,
                               nlohmann::json&& params) const noexcept
    -> std::expected<nlohmann::json, std::string> {
  nlohmann::json request{
      {"jsonrpc", "2.0"}, {"method", method}, {"params", params}, {"id", 1}};

  cpr::Response response{};
  try {
    response = cpr::Post(cpr::Url{kEndpointUrl}, cpr::Body{request.dump()},
                         kCprHeader);
  } catch (const std::exception& ex) {
    return std::unexpected{std::string{"caught exception while sending Post "
                                       "request via cpr. Exception: "} +
                           std::string{ex.what()}};
  }

  nlohmann::json result{};
  try {
    result = nlohmann::json::parse(response.text);
  } catch (std::exception& ex) {
    return std::unexpected{
        std::string{"caught exception while json::parse with msg: "} +
        std::string{ex.what()}};
  }

  return result;
}

}  // namespace eth
