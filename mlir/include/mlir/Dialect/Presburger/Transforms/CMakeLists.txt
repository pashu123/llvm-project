set(LLVM_TARGET_DEFINITIONS Passes.td)
mlir_tablegen(Passes.h.inc -gen-pass-decls -name Presburger)
add_public_tablegen_target(MLIRPresburgerPassIncGen)
add_dependencies(mlir-headers MLIRPresburgerPassIncGen)

add_mlir_doc(Passes PresburgerPasses ./ -gen-pass-doc)
