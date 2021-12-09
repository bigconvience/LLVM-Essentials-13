define i32 @testfunc(i32 %x, i32 %y, i32 %z) {
  %and1 = and i32 %x, %y
  %and2 = and i32 %x, %z
  %res = xor i32 %and1, %and2
  ret i32 %res
}
