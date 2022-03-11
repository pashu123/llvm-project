//===- Passes.h - Presburger Patterns and Passes --------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This header declares patterns and passes on MemRef operations.
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_DIALECT_PRESBURGER_TRANSFORMS_PASSES_H
#define MLIR_DIALECT_PRESBURGER_TRANSFORMS_PASSES_H

#include "mlir/Pass/Pass.h"

namespace mlir {

class AffineDialect;
class ModuleOp;

namespace func {
class FuncDialect;
} // namespace func
namespace tensor {
class TensorDialect;
} // namespace tensor
namespace vector {
class VectorDialect;
} // namespace vector

namespace presburger {
class AllocOp;

//===----------------------------------------------------------------------===//
// Passes
//===----------------------------------------------------------------------===//

/// Creates an pass to normalize the presburger sets.
std::unique_ptr<Pass> createNormalizePresburgerPass();

//===----------------------------------------------------------------------===//
// Registration
//===----------------------------------------------------------------------===//

#define GEN_PASS_REGISTRATION
#include "mlir/Dialect/Presburger/Transforms/Passes.h.inc"

} // namespace memref
} // namespace mlir

#endif // MLIR_DIALECT_PRESBURGER_TRANSFORMS_PASSES_H
