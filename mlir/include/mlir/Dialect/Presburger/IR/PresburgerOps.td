//===- PresburgerOps.td - Presburger op definitions --------------------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef PRESBURGER_OPS
#define PRESBURGER_OPS

include "mlir/Dialect/Presburger/IR/PresburgerTypes.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "mlir/IR/SymbolInterfaces.td"
include "mlir/IR/OpAsmInterface.td"
include "mlir/IR/BuiltinAttributes.td"

//===----------------------------------------------------------------------===//
// Presburger Ops
//===----------------------------------------------------------------------===//

class Presburger_Op<string mnemonic, list<Trait> traits = []>
    : Op<Presburger_Dialect, mnemonic, traits>;

//===----------------------------------------------------------------------===//
def Presburger_SetOp : Presburger_Op<"set", []> {
    let summary = "presburger set operation";

    let arguments = (ins Builtin_IntegerSetAttr:$self);

    let results = (outs Presburger_SetAttr:$res);

  let assemblyFormat = [{
    attr-dict $self
  }];
}
// Presburger Set Op
//===----------------------------------------------------------------------===//

def Presburger_SetUnionOp : Presburger_Op<"set_union", []> {
    let summary = "presburger set union operation";

    let arguments = (ins Presburger_SetAttr:$self, Presburger_SetAttr:$other);

    let results = (outs Presburger_SetAttr:$res);
  let assemblyFormat = [{
    attr-dict $self `,` $other `:` type($self)
  }];
}

#endif // PRESBURGER_OPS
