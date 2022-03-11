add_mlir_dialect_library(MLIRPresburgerTransforms
  NormalizePresburger.cpp

  ADDITIONAL_HEADER_DIRS
  ${MLIR_MAIN_INCLUDE_DIR}/mlir/Dialect/Presburger

  DEPENDS
  MLIRPresburgerPassIncGen

  LINK_LIBS PUBLIC
  MLIRAffine
  MLIRAffineUtils
  MLIRArithmetic
  MLIRFunc
  MLIRInferTypeOpInterface
  MLIRLoopLikeInterface
  MLIRMemRef
  MLIRPass
  MLIRTensor
  MLIRTransforms
  MLIRVector
  MLIRPresburger
)

