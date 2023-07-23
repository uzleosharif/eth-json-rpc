
#include <iostream>
#include <string_view>

#include "cpr/cpr.h"

auto main() -> int {
  std::string_view url{"https://eth.llamarpc.com"};

  std::string_view request_json{R"(
  {
    "jsonrpc": "2.0",
    "method": "eth_blockNumber",
    "params": [],
    "id": 1
  }
  )"};

  auto response{cpr::Post(cpr::Url{url},
                          cpr::Header{{"Content-Type", "application/json"}},
                          cpr::Body{request_json})};
  if (response.error) {
    std::cerr << "cpr request failed: " << response.error.message << "\n";
  }

  std::cout << response.text << '\n';
}
