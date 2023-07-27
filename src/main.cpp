
#include <utility>

#include "account.hpp"

#include "fmt/core.h"

auto main() -> int {
  eth::Account<eth::RpcClientCpr> account{
      eth::Address{"0xd8dA6BF26964aF9D7eEd9e03E53415D37aA96045"}};

  auto balance{account.Balance()};
  if (balance.has_value()) {
    auto balance_double{eth::HexToDouble(balance.value())};
    if (balance_double.has_value()) {
      fmt::print("{}\n", balance_double.value());
    } else {
      fmt::print("ERROR: {}\n", balance_double.error());
    }
  } else {
    fmt::print("ERROR: {}\n", balance.error());
  }

  // TODO: replace via monadic functions
  //  auto balance{account.Balance().and_then(eth::HexToDouble)};
}
