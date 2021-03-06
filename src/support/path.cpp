/*
 * Copyright 2018 WebAssembly Community Group participants
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
// Command line helpers.
//

#include "support/path.h"

namespace wasm {

namespace Path {

char getPathSeparator() {
  // TODO: use c++17's path separator
  //       http://en.cppreference.com/w/cpp/experimental/fs/path
#if defined(WIN32) || defined(_WIN32)
  return '\\';
#else
  return '/';
#endif
}

std::string getDirName(const std::string& path) {
  auto sep = path.rfind(getPathSeparator());
  if (sep == std::string::npos) {
    return "";
  }
  return path.substr(0, sep);
}

std::string getBaseName(const std::string& path) {
  auto sep = path.rfind(getPathSeparator());
  if (sep == std::string::npos) {
    return path;
  }
  return path.substr(sep + 1);
}

std::string getBinaryenRoot() {
  auto* envVar = getenv("BINARYEN_ROOT");
  if (envVar) {
    return envVar;
  }
  return ".";
}

static std::string binDir;

std::string getBinaryenBinDir() {
  if (binDir.empty()) {
    return getBinaryenRoot() + getPathSeparator() + "bin" + getPathSeparator();
  } else {
    return binDir;
  }
}

void setBinaryenBinDir(const std::string& dir) {
  binDir = dir;
  if (binDir.back() != getPathSeparator()) {
    binDir += getPathSeparator();
  }
}

// Gets the path to a binaryen binary tool, like wasm-opt
std::string getBinaryenBinaryTool(const std::string& name) {
  return getBinaryenBinDir() + name;
}

} // namespace Path

} // namespace wasm
