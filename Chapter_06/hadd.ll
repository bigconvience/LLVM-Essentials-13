define i32 @hadd(<4 x i32> %a) nounwind {
  %vecext = extractelement <4 x i32> %a, i32 3
  %vecext1 = extractelement <4 x i32> %a, i32 2
  %add = add i32 %vecext, %vecext1
  %vecext2 = extractelement <4 x i32> %a, i32 1
  %add3 = add i32 %add, %vecext2
  %vecext4 = extractelement <4 x i32> %a, i32 0
  %add5 = add i32 %add3, %vecext4
  ret i32 %add5
}
