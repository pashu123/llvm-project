//===- PresburgerTypes.td - Presburger types --------------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the Presburger dialect types.
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_DIALECT_PRESBURGER_IR_PRESBURGERTYPES
#define MLIR_DIALECT_PRESBURGER_IR_PRESBURGERTYPES

include "mlir/IR/AttrTypeBase.td"
include "mlir/Dialect/Presburger/IR/PresburgerBase.td"

//===----------------------------------------------------------------------===//
// Presburger Types
//===----------------------------------------------------------------------===//

class Presburger_Type<string name, string typeMnemonic>
    : TypeDef<Presburger_Dialect, name> {
  let mnemonic = typeMnemonic;
}

//===----------------------------------------------------------------------===//
// presburger::SetAttrType
//===----------------------------------------------------------------------===//

def Presburger_SetAttr : Presburger_Type<"IntegerSetAttr", "set_attr"> {
  let summary = "Presburger handle to an `mlir::IntegerSetAttr`";
  let description = [{
    This type represents a handle to an instance of an `mlir::IntegerSetAttr`..
  }];
}

#endif // MLIR_DIALECT_PRESBURGER_IR_PRESBURGERTYPES
