
#ifndef UTILS_HPP
#define UTILS_HPP

#include <expected>
#include <string_view>
#include <type_traits>

#include "types.hpp"

#include "cpr/cpr.h"
#include "nlohmann/json.hpp"

namespace eth {
[[nodiscard]] auto Valid(std::string_view) noexcept
    -> std::expected<void, std::string>;

template <typename client_t>
concept RpcClient = requires(const client_t& rpc_client,
                             std::string_view method, nlohmann::json&& params) {
  {
    rpc_client.SendRequest(method, std::move(params))
  } -> std::same_as<std::expected<nlohmann::json, std::string>>;
};

// JSON RPC client using CPR lib
class RpcClientCpr final {
  static constexpr std::string_view kEndpointUrl{"https://eth.llamarpc.com"};
  static inline const cpr::Header kCprHeader{
      {"Content-Type", "application/json"}};

 public:
  RpcClientCpr() noexcept = default;
  RpcClientCpr(const RpcClientCpr&) noexcept = delete;
  RpcClientCpr& operator=(const RpcClientCpr&) noexcept = delete;
  RpcClientCpr(RpcClientCpr&&) noexcept = default;
  RpcClientCpr& operator=(RpcClientCpr&&) noexcept = default;

  [[nodiscard]] auto SendRequest(std::string_view method,
                                 nlohmann::json&& params) const noexcept
      -> std::expected<nlohmann::json, std::string>;

 private:
};
static_assert(not std::is_copy_assignable_v<RpcClientCpr>);
static_assert(not std::is_copy_constructible_v<RpcClientCpr>);
static_assert(std::is_move_assignable_v<RpcClientCpr>);
static_assert(std::is_move_constructible_v<RpcClientCpr>);
}  // namespace eth

#endif
