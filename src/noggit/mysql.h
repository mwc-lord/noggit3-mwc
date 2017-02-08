// This file is part of Noggit3, licensed under GNU General Public License (version 3).

#pragma once

#include <cstdint>

namespace mysql
{
  std::uint32_t getGUIDFromDB();
  void UpdateUIDInDB (std::uint32_t NewUID);
};