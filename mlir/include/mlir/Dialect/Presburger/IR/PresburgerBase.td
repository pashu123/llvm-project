//===- PresburgerBase.td - Base definitions for presburger dialect ------*- tablegen -*-==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef PRESBURGER_BASE
#define PRESBURGER_BASE

include "mlir/IR/OpBase.td"
def Presburger_Dialect : Dialect {
  let name = "presburger";
  let cppNamespace = "::mlir::presburger";
  let description = [{
      A presburger dialect for MLIR.
  }];
  let extraClassDeclaration = [{
    void registerTypes();
  }];
  let emitAccessorPrefix = kEmitAccessorPrefix_Prefixed;
}

#endif // PRESBURGER_BASE
