add_mlir_dialect_library(MLIRPresburgerDialect
    Presburger.cpp
    PresburgerTypes.cpp

    ADDITIONAL_HEADER_DIRS
    ${MLIR_MAIN_INCLUDE_DIR}/mlir/Dialect/Presburger

    DEPENDS
    MLIRPresburgerOpsIncGen

	LINK_LIBS PUBLIC
    MLIRControlFlowInterfaces
    MLIRIR
    MLIRInferTypeOpInterface
    MLIRSideEffectInterfaces
	)
