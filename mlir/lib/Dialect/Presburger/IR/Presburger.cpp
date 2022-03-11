//===- PresburgerDialect.cpp - Presburger dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "mlir/Dialect/Presburger/IR/PresburgerTypes.h"
#include "mlir/Dialect/Presburger/IR/Presburger.h"
#include "mlir/Dialect/Presburger/IR/PresburgerOps.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/Interfaces/InferTypeOpInterface.h"
#include "llvm/ADT/DenseSet.h"
#include "llvm/ADT/TypeSwitch.h"

using namespace mlir;
using namespace mlir::presburger;

#include "mlir/Dialect/Presburger/IR/PresburgerOpsDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// Presburger dialect.
//===----------------------------------------------------------------------===//

void PresburgerDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "mlir/Dialect/Presburger/IR/PresburgerOps.cpp.inc"
      >();
  addTypes<
#define GET_TYPEDEF_LIST
#include "mlir/Dialect/Presburger/IR/PresburgerOpsTypes.cpp.inc"
      >();
}

//===----------------------------------------------------------------------===//
// TableGen'd op method definitions
//===----------------------------------------------------------------------===//

#define GET_OP_CLASSES
#include "mlir/Dialect/Presburger/IR/PresburgerOps.cpp.inc"
