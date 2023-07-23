
#include <utility>

#include "types.hpp"

#include "fmt/core.h"

auto main() -> int {
  eth::Address address{"0x6b110ba7206431374934a40a32cf14906d286e2b"};
  fmt::print("address = 0x{}\n", address.Str());
}
