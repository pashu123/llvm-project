//===- PresburgerTypes.cpp - Pattern Descriptor Language Types -------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "mlir/Dialect/Presburger/IR/PresburgerTypes.h"
#include "mlir/Dialect/Presburger/IR/Presburger.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/TypeSwitch.h"

using namespace mlir;
using namespace mlir::presburger;

//===----------------------------------------------------------------------===//
// TableGen'd type method definitions
//===----------------------------------------------------------------------===//

#define GET_TYPEDEF_CLASSES
#include "mlir/Dialect/Presburger/IR/PresburgerOpsTypes.cpp.inc"

//===----------------------------------------------------------------------===//
// PDLDialect
//===----------------------------------------------------------------------===//

void PresburgerDialect::registerTypes() {
  addTypes<
#define GET_TYPEDEF_LIST
#include "mlir/Dialect/Presburger/IR/PresburgerOpsTypes.cpp.inc"
      >();
}

static Type parsePresburgerType(AsmParser &parser) {
  StringRef typeTag;
  if (parser.parseKeyword(&typeTag))
    return Type();
  {
    Type genType;
    auto parseResult = generatedTypeParser(parser, typeTag, genType);
    if (parseResult.hasValue())
      return genType;
  }

  // FIXME: This ends up with a double error being emitted if `RangeType` also
  // emits an error. We should rework the `generatedTypeParser` to better
  // support when the keyword is valid but the individual type parser itself
  // emits an error.
  parser.emitError(parser.getNameLoc(), "invalid 'presburger' type: `")
      << typeTag << "'";
  return Type();
}

//===----------------------------------------------------------------------===//
// PDL Types
//===----------------------------------------------------------------------===//

bool PresburgerType::classof(Type type) {
  return llvm::isa<PresburgerDialect>(type.getDialect());
}

