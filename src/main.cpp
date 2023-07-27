
#include <utility>

#include "account.hpp"

#include "fmt/core.h"
#include "utils.hpp"

auto main() -> int {
  eth::Account<eth::RpcClientCpr> account{
      eth::Address{"0xd8dA6BF26964aF9D7eEd9e03E53415D37aA96045"}};

  auto exp_balance{account.Balance().and_then(eth::HexToDouble)};
  if (exp_balance.has_value()) {
    fmt::print("balance = {}\n", exp_balance.value());
  }
}
