// RUN: mlir-opt  %s

#set0 = affine_set<(d0) : (d0 - 1 >= 0)>
#set1 = affine_set<(d0) : (d0 + 1 >= 0)>

func.func @presburger_setop() {
  %0 = presburger.set #set0
  %1 = presburger.set #set1
  %2 = presburger.set_union %0, %1 : !presburger.set_attr
  return
}
