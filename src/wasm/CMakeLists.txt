file(GLOB wasm_HEADERS ../*.h)
set(wasm_SOURCES
  literal.cpp
  wasm.cpp
  wasm-binary.cpp
  wasm-debug.cpp
  wasm-emscripten.cpp
  wasm-debug.cpp
  wasm-interpreter.cpp
  wasm-io.cpp
  wasm-s-parser.cpp
  wasm-stack.cpp
  wasm-type.cpp
  wasm-validator.cpp
  ${wasm_HEADERS}
)
add_library(wasm OBJECT ${wasm_SOURCES})
