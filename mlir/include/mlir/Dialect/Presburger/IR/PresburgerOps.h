//===- PresburgerOps.h - Pattern Descriptor Language Operations --------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the operations for the Pattern Descriptor Language dialect.
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_DIALECT_Presburger_IR_PresburgerOPS_H_
#define MLIR_DIALECT_Presburger_IR_PresburgerOPS_H_

#include "mlir/Dialect/Presburger/IR/PresburgerTypes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/SymbolTable.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

//===----------------------------------------------------------------------===//
// Presburger Dialect Operations
//===----------------------------------------------------------------------===//

#define GET_OP_CLASSES
#include "mlir/Dialect/Presburger/IR/PresburgerOps.h.inc"

#endif // MLIR_DIALECT_Presburger_IR_PresburgerOPS_H_
