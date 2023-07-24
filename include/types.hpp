

#ifndef TYPES_HPP
#define TYPES_HPP

#include <array>
#include <string_view>

namespace eth {

// value type for ethereum address
class Address final {
 public:
  Address() noexcept;
  Address(std::string_view) noexcept;

  [[nodiscard]] auto Str() const noexcept -> std::string;

 private:
  std::array<char, 40> value_{};
};
static_assert(std::is_copy_constructible_v<Address>);
static_assert(std::is_copy_assignable_v<Address>);
static_assert(std::is_move_constructible_v<Address>);
static_assert(std::is_move_assignable_v<Address>);

}  // namespace eth

#endif
