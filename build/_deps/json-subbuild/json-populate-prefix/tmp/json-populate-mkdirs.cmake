# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/Peter/Desktop/TerminalCaptionPlayer/build/_deps/json-src"
  "/Users/Peter/Desktop/TerminalCaptionPlayer/build/_deps/json-build"
  "/Users/Peter/Desktop/TerminalCaptionPlayer/build/_deps/json-subbuild/json-populate-prefix"
  "/Users/Peter/Desktop/TerminalCaptionPlayer/build/_deps/json-subbuild/json-populate-prefix/tmp"
  "/Users/Peter/Desktop/TerminalCaptionPlayer/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
  "/Users/Peter/Desktop/TerminalCaptionPlayer/build/_deps/json-subbuild/json-populate-prefix/src"
  "/Users/Peter/Desktop/TerminalCaptionPlayer/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/Peter/Desktop/TerminalCaptionPlayer/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/${subDir}")
endforeach()
