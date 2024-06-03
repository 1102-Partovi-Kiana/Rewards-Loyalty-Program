# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/kianapartovi/CS202_PA/cs202_sp23_pa5-1102-Partovi-Kiana/tests/gtest/src/gtest"
  "/Users/kianapartovi/CS202_PA/cs202_sp23_pa5-1102-Partovi-Kiana/tests/gtest/src/gtest-build"
  "/Users/kianapartovi/CS202_PA/cs202_sp23_pa5-1102-Partovi-Kiana/tests/gtest"
  "/Users/kianapartovi/CS202_PA/cs202_sp23_pa5-1102-Partovi-Kiana/tests/gtest/tmp"
  "/Users/kianapartovi/CS202_PA/cs202_sp23_pa5-1102-Partovi-Kiana/tests/gtest/src/gtest-stamp"
  "/Users/kianapartovi/CS202_PA/cs202_sp23_pa5-1102-Partovi-Kiana/tests/gtest/src"
  "/Users/kianapartovi/CS202_PA/cs202_sp23_pa5-1102-Partovi-Kiana/tests/gtest/src/gtest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/kianapartovi/CS202_PA/cs202_sp23_pa5-1102-Partovi-Kiana/tests/gtest/src/gtest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/kianapartovi/CS202_PA/cs202_sp23_pa5-1102-Partovi-Kiana/tests/gtest/src/gtest-stamp${cfgdir}") # cfgdir has leading slash
endif()
